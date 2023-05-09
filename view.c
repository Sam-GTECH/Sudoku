#include <stdint.h>
#include <stdlib.h>

void printSudoku(int tab[9][9], int pointer_x, int pointer_y) {
    int row, col;
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (row == pointer_x && col == pointer_y) {
                printf("[09\e"); // The intent is to inverse the colors
            }
            printf("%i", tab[row][col]);
            if (col%3==0)
                printf(" ");
        }
        if (col%3==0)
                printf("\n");
        printf("\n");
    }
    printf("[00\e\0"); //Reset the terminal color?
}