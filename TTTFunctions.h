#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#ifndef INPUT_STRING
#define INPUT_STRING 32
#define SHORT_STRING 16
#define TRUE 1
#define ERROR_VALUE -99
#define FALSE 0
#pragma importf "TTTFunction.c"

void game_manager(void);
char *main_menu(void);
void PVP_game(void);
void print_board(char board[3][3], FILE *stream);
int restart(void);
void input_validation(char* user_input);
int check_win(int player, char board[3][3]);
void PVE_game(void);
int coordinates_validation(int player, char board[3][3]);
int AI_manager(char board[3][3]);



#endif

