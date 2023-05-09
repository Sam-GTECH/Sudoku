/* Ce programme ne marche pas du tout */
#include <stdio.h>
#include <stdint.h>
#include <Windows.h>
#include <conio.h>

//#include <game.c>
//#include <view.c>

#define INPUT_ENTER 50
#define INPUT_LEFT 76
#define INPUT_RIGHT 77
#define INPUT_UP 78
#define INPUT_DOWN 79

int main(void) {
    SetConsoleTitle("Sudoku");

    int tab[9][9];

    //createSudoku(tab);    
    
    printf("Welcome to Sudoku!\n");
    printf("Press any key to start.\n");
    getchar();

    int pointer_x = 0;
    int pointer_y = 0;

    int mode = 0;
    int verif, choice;

    while (1) {
        //printSudoku(tab, pointer_x, pointer_y);
        if (mode == 0) {
            while(_kbhit()) {
                int key = getch();
                switch (key) {
                    case INPUT_DOWN:
                        pointer_y++;
                        break;
                    case INPUT_LEFT:
                        pointer_x--;
                        break;
                    case INPUT_RIGHT:
                        pointer_x++;
                        break;
                    case INPUT_UP:
                        pointer_y--;
                        break;
                    case INPUT_ENTER:
                        mode = 1;
                        break;
                }
            }
        } else {
            printf("Choose a number between 1 and 9 (Type 0 to cancel): ");
            verif = scanf_s("%i", &choice);
            if (choice < 0 || choice > 9) {
                printf("Incorrect choice.");
            } else {
                if (choice == 0) {
                    choice = 0;
                    verif = 0;
                    mode = 0;
                    continue;
                }

                if (tab[pointer_x][pointer_y] == choice) {
                    printf("Number found!");
                } else {
                    printf("Wrong guess...");
                }

                choice = 0;
                verif = 0;
                mode = 0;
            }
        }
    }

    return 0;
}