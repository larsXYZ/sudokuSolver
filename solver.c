#include "utilityFunctions.h"

int testSudoku[81] = {};





int main(void)
{
	for (int i = 0; i < 81; i++) testSudoku[i] = i;
	printSudoku(testSudoku);
	return 0;
}
