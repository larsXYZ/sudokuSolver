#include "utilityFunctions.h"

int testSudoku[81] = {};



int main(void)
{
	loadSudokuFromFile("savedSudoku",testSudoku);
	printSudoku(testSudoku);
	return 0;
}
