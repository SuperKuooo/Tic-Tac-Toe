#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#pragma importf "TTTFunction.c"

#define INPUT_STRING 32
#define SHORT_STRING 16
#define ERROR_VALUE -99
#define TRUE 1
#define FALSE 0


void PVE_game(void);

void PVP_game(void);

void print_board(char board[3][3], FILE *stream);

void game_manager(void);

void see_the_future(char imaginary_board[3][3], FILE *evaluation_out, int depth);

void board_analysis(char imaginary_board[3][3], FILE *evaluation_out, int player);

void sort_AI_results(FILE *evaluation_out, int move[9]);

void input_validation(char *user_input);

int restart(void);

int check_win(int player, char board[3][3]);

int AI_manager(char board[3][3]);

int return_move(int move[9]);

int coordinates_validation(int player, char board[3][3]);

char *main_menu(void);


