
#include "utilityFunctions.h"

bool solveAttempt(int* sudoku, int i)
{
	//CHECKS IF WE ARE DONE WITH SUDOKU
	if (i > 80)
	{
		printf("\nSolution:\n");
		printSudoku(sudoku);
		
		return true;
	}

	//CREATES WORKCOPY
	int copy[81];
	for (int q = 0; q < 81; q++) copy[q] = sudoku[q];
	
	//CHECKS IF FIELD IS EMPTY
	if (copy[i] != 0) return solveAttempt(copy, i + 1);
	else
	{
		for (int q = 1; q <= 9; q++)
		{
			if (valueFits(copy, i, q))
			{
				copy[i] = q;
				solveAttempt(copy, i + 1);
			}
		}
	return false;
	} 
}


void solve(int* sudoku)
{
	int i = 0;
	solveAttempt(sudoku, i);
}
