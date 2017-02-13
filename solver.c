#include "utilityFunctions.h"
#include "solvingAlgorithm.h"

int testSudoku[81] = {};

int main(void)
{
	loadSudokuFromFile(testSudoku,"originalSudokuHard2");
	printf("\n\nLoaded sudoku from file:\n");
	printSudoku(testSudoku);
	solve(testSudoku);
	return 0;
}
