#include "utilityFunctions.h"

int testSudoku[81] = {};



int main(void)
{
	testSudoku[76] = 5;

	printSudoku(testSudoku);
	printf("%d %s",*getValue(testSudoku,9,5), "\n");
	if (rowFit(testSudoku,9,5)) testSudoku[77] = 5;
	if (rowFit(testSudoku,9,2)) testSudoku[75] = 2;

	
	if (colFit(testSudoku, 4, 2)) *getValue(testSudoku,7,4) = 2;
	if (colFit(testSudoku, 4, 1)) *getValue(testSudoku,8,4) = 1;
	printSudoku(testSudoku);

	return 0;
}
