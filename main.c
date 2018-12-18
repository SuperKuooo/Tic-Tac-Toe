#include <string.h>
#include <stdio.h>
#include "TTTFunctions.h"

void game_manager(void);

int main(void) {
    game_manager();

    return 0;
}

void game_manager(void) {
    char game_mode[SHORT_STRING];
    strcpy(game_mode, main_menu());
    if (!strcmp(game_mode, "PVP")){
        PVP_game();
    }


}

