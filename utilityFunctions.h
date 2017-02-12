#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

enum subSquare {UL,UM,UR,ML,MM,MR,DL,DM,DR,ERROR}; //defines the subsquares within the sudoku board

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

	return ERROR;
}

void getValuesInSubSquare(int* s, enum subSquare square, int* result) //returnes a 9 element array with the values in the given subsquare 
{
	switch (square)
	{
		case UL :
			result[0] = s[0];
			result[1] = s[1];
			result[2] = s[2];
			result[3] = s[9];
			result[4] = s[10];
			result[5] = s[11];
			result[6] = s[18];
			result[7] = s[19];
			result[8] = s[20];
			break;
		
		case UM :
			result[0] = s[3];
			result[1] = s[4];
			result[2] = s[5];
			result[3] = s[12];
			result[4] = s[13];
			result[5] = s[14];
			result[6] = s[21];
			result[7] = s[22];
			result[8] = s[23];
			break;

		case UR :
			result[0] = s[6];
			result[1] = s[7];
			result[2] = s[8];
			result[3] = s[15];
			result[4] = s[16];
			result[5] = s[17];
			result[6] = s[24];
			result[7] = s[25];
			result[8] = s[26];
			break;

		case ML :
			result[0] = s[27];
			result[1] = s[28];
			result[2] = s[29];
			result[3] = s[36];
			result[4] = s[37];
			result[5] = s[38];
			result[6] = s[45];
			result[7] = s[46];
			result[8] = s[47];
			break;

		case MM :
			result[0] = s[30];
			result[1] = s[31];
			result[2] = s[32];
			result[3] = s[39];
			result[4] = s[40];
			result[5] = s[41];
			result[6] = s[48];
			result[7] = s[49];
			result[8] = s[50];
			break;

		case MR :
			result[0] = s[33];
			result[1] = s[34];
			result[2] = s[35];
			result[3] = s[42];
			result[4] = s[43];
			result[5] = s[44];
			result[6] = s[51];
			result[7] = s[52];
			result[8] = s[53];
			break;

		case DL :
			result[0] = s[54];
			result[1] = s[55];
			result[2] = s[56];
			result[3] = s[63];
			result[4] = s[64];
			result[5] = s[65];
			result[6] = s[72];
			result[7] = s[73];
			result[8] = s[74];
			break;

		case DM :
			result[0] = s[57];
			result[1] = s[58];
			result[2] = s[59];
			result[3] = s[66];
			result[4] = s[67];
			result[5] = s[68];
			result[6] = s[75];
			result[7] = s[76];
			result[8] = s[77];
			break;

		case DR :
			result[0] = s[60];
			result[1] = s[61];
			result[2] = s[62];
			result[3] = s[69];
			result[4] = s[70];
			result[5] = s[71];
			result[6] = s[78];
			result[7] = s[79];
			result[8] = s[80];
			break;

		case ERROR :
			result[0] = 0;
			result[1] = 0;
			result[2] = 0;
			result[3] = 0;
			result[4] = 0;
			result[5] = 0;
			result[6] = 0;
			result[7] = 0;
			result[8] = 0;
			break;
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

bool squareFit(int* sudoku, int row, int col, int val)
{
	int otherVals[9];
	getValuesInSubSquare(sudoku, detSubSquare(row,col), otherVals);

	for (int i = 0; i < 9; i++)
	{
		if (otherVals[i] == val) return false;
	}	
	return true;
}

bool valueFits(int* sudoku, int index, int val)
{
	int row = index / 9 + 1;
	int col = index % 9 + 1;

	return (colFit(sudoku,col,val) && rowFit(sudoku,row,val) && squareFit(sudoku,row,col,val));
}

bool full(int* sudoku)
{
	for (int i = 0; i < 81; i++) if (sudoku[i] == 0) return false;
	return true;
}

void loadSudokuFromFile(int* sudoku, const char* filename) //loads sudoku from textfile
{
	FILE* fp;
	char charArray[255];
	fp = fopen(filename, "r");
	fscanf(fp, "%s", charArray);
	
	for (int i = 0; i < 81; i++)
	{
		sudoku[i] = (int)charArray[i] - 48;
	}
}





