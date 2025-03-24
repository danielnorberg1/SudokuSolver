#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 9

// This function prints the sudoku board
void printBoard(int board[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j < SIZE; j++){
            printf("%d", board[i][j]);
        }
        printf("\n");
    }


}

// Function that check if placing num at board[][] is valid
bool isValid(int board[SIZE][SIZE], int row, int col, int num){
     // Check the row and column.
     for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }
    
    // Determine the top-left coordinates of the 3x3 subgrid.
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    
    // Check the 3x3 subgrid.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }
    
    return true;
}



// Function that solves the sudoku and returs true or false depending on succes/or not
bool solver(int board[SIZE][SIZE]){


}



int main(){


srand(time(NULL));

// Here we create the sudoku
// Right now we create it manually so take one from the internet
// or make it yourself
int board[SIZE][SIZE]= {
    {5, 3, 0,   0, 7, 0,   0, 0, 0},
    {6, 0, 0,   1, 9, 5,   0, 0, 0},
    {0, 9, 8,   0, 0, 0,   0, 6, 0},

    {8, 0, 0,   0, 6, 0,   0, 0, 3},
    {4, 0, 0,   8, 0, 3,   0, 0, 1},
    {7, 0, 0,   0, 2, 0,   0, 0, 6},

    {0, 6, 0,   0, 0, 0,   2, 8, 0},
    {0, 0, 0,   4, 1, 9,   0, 0, 5},
    {0, 0, 0,   0, 8, 0,   0, 7, 9}


};

// Prints board
printBoard(board);




}




