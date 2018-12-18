#include "TTTFunctions.h"


void game_manager(void) {
    char game_mode[SHORT_STRING];
    strcpy(game_mode, main_menu()); //picks game mode
    if (!strcmp(game_mode, "PVP")) {
        PVP_game();
    } else if (strcmp(game_mode, "PVE")) {
        PVE_game();
    }
    if (restart()) {
        game_manager();
    }
}

void PVE_game(void) {
    int player = 0;
    int go = 0;
    int row = 0, column = 0;
    int winner = FALSE;
    char board[3][3] = //Global board variable
            {
                    {'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}
            };

    for (int i = 0; i < 9 && winner == FALSE; i++) {
        print_board(board);

        player = i % 2 + 1;

        do {
            printf("\nPlayer %d, please enter the number of the square "
                   "where you want to place your %c: ", player, (player == 1) ? 'X' : 'O');
            if (scanf("%d", &go) == 1){
                getchar();
            }
            else{
                continue;
            }
            row = --go / 3;
            column = go % 3;
        } while (go < 0 || go > 9 || board[row][column] > '9');
        board[row][column] = (player == 1) ? 'X' : 'O';
        winner = check_win(player, board);
    }
    print_board(board);
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

void print_board(char board[3][3]) {
    printf("\n\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int check_win(int player, char board[3][3]) {
    int line;

    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
        return player;
    else

        for (line = 0; line <= 2; line++)
            if ((board[line][0] == board[line][1] && board[line][0] == board[line][2]) ||
                (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
                return player;

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
    fgets(user_input, INPUT_STRING, stdin); //gets user input
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
}

void PVP_game(void) {
    int player = 0;
    int go = 0;
    int row = 0;
    int column = 0;
    int winner = FALSE;
    char board[3][3] = //Global board variable
            {
                    {'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}
            };

    for (int i = 0; i < 9 && winner == FALSE; i++) {
        print_board(board);

        player = i % 2 + 1;

        do {
            go = coordinates_validation(player);

            row = --go / 3;
            column = go % 3;
        } while (go < 0 || go > 9 || board[row][column] > '9');

        board[row][column] = (player == 1) ? 'X' : 'O';
        winner = check_win(player, board);
    }
    print_board(board);
    if (winner == FALSE)
        printf("\nDraw\n");
    else
        printf("\nPlayer %d, YOU WON!\n", winner);
}


int coordinates_validation(int player){
    int input;
    char valid;

    printf("\nPlayer %d, please enter the number of the square "
           "where you want to place your %c: ", player, (player == 1) ? 'X' : 'O');
    scanf("%d", &input);
    valid  = getchar();
    while (valid != '\n') {
        if (isalpha(valid)) {
            while (getchar() != '\n');
            printf("Invalid input, try again.\n");
            return -1;
        }
    }
    if (input <= 0 || input > 100) {
        printf("Guess out of bounds, try again.\n");
        return -1;
    }
    return input;
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