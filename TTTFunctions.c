#include "TTTFunctions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char board[3][3] = //Global board variable
        {
                {'1', '2', '3'},
                {'4', '5', '6'},
                {'7', '8', '9'}
        };

void print_board(void) {
    printf("\n\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

char *main_menu(void) {
    const char input_prompt[INPUT_STRING] = "\nPLAY MODE> "; //repeats to let user know to input
    char user_input[INPUT_STRING]; //takes user's choice on game mode
    char *vald; //Input trim and validation

    printf("\n**************** Welcome to Tic Tac Toe ****************\n\n");
    printf("Choose a play mode:\n\n");
    printf("PvP, Game Mode 1:  Start the game versus another player\n");
    printf("PvE, Game Mode 2:  Start the game versus the AI\n");
    printf("q,   quit:         Quit the game\n");
    printf("\n......................................................\n");
    printf("%s", input_prompt);

    fgets(user_input, INPUT_STRING, stdin); //gets user input
    if ((vald = strchr(user_input, '\n')) != NULL)
        *vald = '\0';
    else {
        printf("Error: Input too Long MAX %d characters. \n", INPUT_STRING);
        exit(1);
    }
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

void PVP_game(void){

    int player = 0;
    int go = 0;
    int row = 0;
    int column = 0;
    int line = 0;
    int winner = FALSE;


    for (int i = 0; i < 9 && winner == FALSE; i++) {
        print_board();

        player = i % 2 + 1;

        do {
            printf("\nPlayer %d, please enter the number of the square "
                   "where you want to place your %c: ", player, (player == 1) ? 'X' : 'O');
            scanf("%d", &go);

            row = --go / 3;
            column = go % 3;
        } while (go < 0 || go > 9 || board[row][column] > '9');

        board[row][column] = (player == 1) ? 'X' : 'O';

        if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
            winner = player;
        else

            for (line = 0; line <= 2; line++)

                if ((board[line][0] == board[line][1] && board[line][0] == board[line][2]) ||
                    (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
                    winner = player;

    }
    print_board();
    if (winner == FALSE)
        printf("\nDraw\n");
    else
        printf("\nplayer %d, YOU WON!\n", winner);
}