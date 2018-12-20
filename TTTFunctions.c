#include "TTTFunctions.h"
//Test

void game_manager(void) {
    char game_mode[SHORT_STRING];

    strcpy(game_mode, main_menu()); //picks game mode
    if (!strcmp(game_mode, "PVP")) {
        PVP_game();
    } else if (!strcmp(game_mode, "PVE")) {
        PVE_game();
    } else if (!strcmp(game_mode, "EXIT")) {
        return;
    }
    if (restart()) {
        game_manager();
    }
}

int AI_manager(char board[3][3]) {
    FILE *evaluation_out;
    char imaginary_board[3][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
    };
    int temp, minimax[9], move[9], final;
    char header;

    if ((evaluation_out = fopen("board_outcome.txt", "w+")) == NULL) {
        printf("Cannot Open File\n");
        exit(EXIT_FAILURE);
    }
    for (int row = 0; row <= 2; row++) {
        strcpy(imaginary_board[row], board[row]);
    }
    fprintf(evaluation_out, "# 1 2 3 4 5 6 7 8 9\n");
    fprintf(evaluation_out, "+ ");
    board_analysis(imaginary_board, evaluation_out, 1); //depth 1
    fprintf(evaluation_out, "\n");

    for (int row = 0; row <= 2; row++) {
        for (int column = 0; column <= 2; column++) {
            if (imaginary_board[row][column] == 'O' || imaginary_board[row][column] == 'X') {
                continue;
            } else {
                int player = 2;
                temp = imaginary_board[row][column];
                imaginary_board[row][column] = (player == 1) ? 'X' : 'O';
                fprintf(evaluation_out, "%d ", row * 3 + column + 1);
                board_analysis(imaginary_board, evaluation_out, 2);
                fprintf(evaluation_out, "\n");
                imaginary_board[row][column] = temp;
            }
        }
    }

    if (fseek(evaluation_out, 0L, SEEK_SET) != 0) {
        /* Handle repositioning error */
        printf("Failure to rewind files\n");
    }

    while (fscanf(evaluation_out, " %c %d %d %d %d %d %d %d %d %d", &header, &minimax[0], &minimax[1], &minimax[2],
                  &minimax[3], &minimax[4], &minimax[5], &minimax[6], &minimax[7], &minimax[8]) != EOF) {
        if (header == '+') {
            for (int i = 0; i <= 8; i++) {
                move[i] = minimax[i];
            }
        } else if (isdigit(header)) {
            for (int i = 0; i <= 8; i++) {
                if (minimax[i] == 1) {
                    move[header - '1'] = 1;
                    break;
                }
            }
        }
    }
    fprintf(evaluation_out, "\n\n@ ");
    for (int i = 0; i <= 8; i++) {
        fprintf(evaluation_out, "%d ", move[i]);
    }

    for (int i = 0; i<=8; i++){
        if (move[i] == 2){
            return i+1;
        }
    }
    for (int i = 0; i<=8; i++){
        if (move[i] == 0){
            return i+1;
        }
    }
    for (int i = 0; i<=8; i++){
        if (move[i] == 1){
            return i+1;
        }
    }
    fclose(evaluation_out);

    return ERROR_VALUE;
}

void board_analysis(char imaginary_board[3][3], FILE *evaluation_out, int player) { //sees 1 step ahead
    char temp;

    player = (player % 2) + 1;
    for (int row = 0; row <= 2; row++) {
        for (int column = 0; column <= 2; column++) {
            if (imaginary_board[row][column] == 'O' || imaginary_board[row][column] == 'X' ||
                check_win(player, imaginary_board)) {
                fprintf(evaluation_out, "5 ");
                continue;
            } else {
                temp = imaginary_board[row][column];
                imaginary_board[row][column] = (player == 1) ? 'X' : 'O';
                fprintf(evaluation_out, "%d ", check_win(player, imaginary_board));
                //print_board(imaginary_board, evaluation_out);
                imaginary_board[row][column] = temp;
            }
        }
    }
}

void PVE_game(void) {
    int player = 0;
    int AI_input= 0;
    int winner = FALSE;
    char board[3][3] =
            {
                    {'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}
            };

    for (int i = 0; i < 9 && winner == FALSE; i++) {
        print_board(board, stdout);
        player = i % 2 + 1;
        if (player == 1) {
            while (coordinates_validation(player, board) == -1);
        } else if (player == 2) {
            AI_input = AI_manager(board);
            board[--AI_input / 3][AI_input % 3] = 'O';
        }
        winner = check_win(player, board);
    }
    print_board(board, stdout);
    if (winner == FALSE)
        printf("\nDraw\n");
    else
        printf("\nPlayer %d, YOU WON!\n", winner);
}

void input_validation(char *user_input) {
    char *valid; //Input trim and validation

    if ((valid = strchr(user_input, '\n')) != NULL)
        *valid = '\0';
    else {
        printf("Error: Input too Long MAX %d characters. \n", INPUT_STRING);
        exit(1);
    }
}

void print_board(char board[3][3], FILE *stream) {
    fprintf(stream, "\n\n");
    fprintf(stream, " %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    fprintf(stream, "-----------\n");
    fprintf(stream, " %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    fprintf(stream, "-----------\n");
    fprintf(stream, " %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int check_win(int player, char board[3][3]) {
    int line;

    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
        return player;
    else {
        for (line = 0; line <= 2; line++)
            if ((board[line][0] == board[line][1] && board[line][0] == board[line][2]) ||
                (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
                return player;
    }

    return FALSE;
}

char *main_menu(void) {
    const char input_prompt[INPUT_STRING] = "\nPLAY MODE> "; //repeats to let user know to input
    char user_input[INPUT_STRING]; //takes user's choice on game mode

    printf("\n**************** Welcome to Tic Tac Toe ****************\n\n");
    printf("Choose a play mode:\n\n");
    printf("PvP, Game Mode 1:  Start the game versus another player\n");
    printf("PvE, Game Mode 2:  Start the game versus the AI\n");
    printf("q,   quit:         Quit the game\n");
    printf("\n......................................................\n");
    printf("%s", input_prompt);
    //fgets(user_input, INPUT_STRING, stdin); //gets user input
    strcpy(user_input, "pve\n");
    input_validation(user_input);

    if (!strcmp(user_input, "PvP") || !strcmp(user_input, "pvp") || !strcmp(user_input, "Game Mode 1")) {
        printf("Entering %s.\n", user_input);
        return "PVP";
    } else if (!strcmp(user_input, "PvE") || !strcmp(user_input, "pve") || !strcmp(user_input, "Game Mode 2")) {
        printf("Entering %s.\n", user_input);
        return "PVE";
    } else if (!strcmp(user_input, "q") || !strcmp(user_input, "quit")) {
        printf("Quitting the game...\n");
        return "EXIT";
    } else {
        printf("\nInput undefined. Please enter again. \n");
        main_menu();
    }
    return "ERROR";
}

void PVP_game(void) {
    int player = 0;
    int winner = FALSE;
    char board[3][3] =
            {
                    {'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}
            };

    for (int i = 0; i < 9 && winner == FALSE; i++) {
        print_board(board, stdout);
        player = i % 2 + 1;
        while (coordinates_validation(player, board) == -1);
        winner = check_win(player, board);
    }
    print_board(board, stdout);
    if (winner == FALSE)
        printf("\nDraw\n");
    else
        printf("\nPlayer %d, YOU WON!\n", winner);
}

int coordinates_validation(int player, char board[3][3]) {
    int input;
    int row, column;
    char valid;

    printf("\nPlayer %d, please enter the number of the square "
           "where you want to place your %c: ", player, (player == 1) ? 'X' : 'O');
    scanf("%d", &input);
    while ((valid = getchar()) != '\n') {
        if (isalpha(valid)) {
            while (getchar() != '\n');
            printf("Invalid input, try again.\n");
            return -1;
        }
    }
    row = --input / 3;
    column = input % 3;
    if (input < 0 || input > 9 || board[row][column] > '9') {
        printf("Invalid input, try again.\n");
        return -1;
    }
    board[row][column] = (player == 1) ? 'X' : 'O';
    return 0;
}

int restart(void) {
    char user_input[INPUT_STRING];

    printf("Do you want to play another game?\n\n");
    fgets(user_input, INPUT_STRING, stdin);
    input_validation(user_input);
    if (!strcmp(user_input, "Yes") || !strcmp(user_input, "yes") || !strcmp(user_input, "y")) {
        return 1;
    } else {
        printf("Thank you for playing! Goodbye\n");
        return 0;
    }
}