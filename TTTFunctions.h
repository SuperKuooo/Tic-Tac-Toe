#ifndef INPUT_STRING
#define INPUT_STRING 32
#define SHORT_STRING 16
#define TRUE 1
#define FALSE 0
#pragma importf "TTTFunction.c"

char *main_menu(void);
void PVP_game(void);
void print_board(char board[3][3]);
int restart(void);
void input_validation(char* user_input);

#endif

