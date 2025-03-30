#include <stdlib.h> // Icludes necessary libraries
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 9 // defines the size of the sudoku board to 9

// This function prints the sudoku board
// and takes the board as argument
void printBoard(int board[SIZE][SIZE]){
    // this is a nested loop to make sure that the loops iterates through 
    // the 2d array correctly, i for horizontal and j for vertical
    for(int i=0; i<SIZE; i++){ 
        for(int j=0; j < SIZE; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n"); // Adds \n after each horizontal row to make it print as we want it to
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
    int row, col;
    bool empty_found = false;
    
    // Find an empty cell (0 represents empty).
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                empty_found = true;
                goto FIND_EMPTY_EXIT;
            }
        }
    }
FIND_EMPTY_EXIT:

    // If no empty cell is found, we've solved the board.
    if (!empty_found)
        return true;
    
    // Try numbers 1 through 9.
    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;  // Tentatively place num.
            
            // Recursively try to solve the rest of the board.
            if (solver(board))
                return true;
            
            // If placing num doesn't lead to a solution, reset the cell.
            board[row][col] = 0;
        }
    }
    
    // Trigger backtracking.
    return false;

}



int main(){





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


// Here we print the board before being solved
printBoard(board);

// Here we use to solve function to solve the board
solver(board);

// Here we print the board after it being solved
printBoard(board);




}




