#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//NECESSARY FUNCTIONS

void printSudoku(int* sudoku) //Simple print
{
	for (int i = 0; i < 9; i++)
	{
		for (int q = 0; q < 9; q++)
		{
			printf("%d", sudoku[i*9 + q]);
			if (q % 3 == 2) printf(" ");
		}
		printf("\n");
		if (i % 3 == 2) printf("\n");
	}
}

int* getValue(int* sudoku, int row, int column) //row(1-9), column(1-9), returns pointer to value!!
{
	return &sudoku[9 * (row-1) + column - 1];
}

bool rowFit(int* sudoku, int row, int value) //returns TRUE if you can place value at given row
{
	for (int c = 0; c < 9; c++)
	{
		if (sudoku[9*(row-1) + c] == value) return false;
	}
	return true;
}

bool colFit(int* sudoku, int col, int value) //returns TRUE if you can place value at given column
{
	for (int r = 0; r < 9; r++)
	{
		if (sudoku[9*r + col - 1] == value) return false;
	}
	return true;
}

void loadSudokuFromFile(char* filename, int* sudoku)
{








}



