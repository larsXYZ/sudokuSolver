#include <stdio.h>
#include <stdbool.h>
#include <string.h>

enum subSquare {UL,UM,UR,ML,MM,MR,DL,DM,DR,ERROR};


//NECESSARY FUNCTIONS

enum subSquare detSubSquare(int row, int col) //determines which subsquare a coordinate is in row(1-9) col(1-90)
{
	if (row <= 0 || row > 9) return ERROR;	

	if (row <= 3)
	{
		if (col <= 3) return UL;
		if (col > 3 && col <= 6) return UM;
		if (col > 6) return UR;
		return ERROR;
	} 
	
	if (row > 3 && row <= 6)
	{
		if (col <= 3) return ML;
		if (col > 3 && col <= 6) return MM;
		if (col > 6) return MR;
		return ERROR;
	} 

	if (row > 6)
	{
		if (col <= 3) return DL;
		if (col > 3 && col <= 6) return DM;
		if (col > 6) return DR;
		return ERROR;
	} 
}

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

bool squareFit(int* sudoku, int row, int col)
{
	

}

void loadSudokuFromFile(int* sudoku, const char* filename) //loads sudoku from textfile
{
	FILE* fp;
	char charArray[255];
	fp = fopen(filename, "r");
	fscanf(fp, "%s", charArray);
	
	for (int i = 0; i < 81; i++)
	{
		sudoku[i] = (int) charArray[i] - 48;
	}
}





