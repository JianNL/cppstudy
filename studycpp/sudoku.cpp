#include "sudoku.h"






vector<int> sudoku::getRow(vector<vector<int> > matrix,int rowNum)
{
	vector<int> rowData;
	for (auto e:matrix[rowNum])
	{
		if (e>0)
		{
			rowData.push_back(e);
		}
	}
	return rowData;
}


vector<int> sudoku::getCol(vector<vector<int> > matrix,int colNum)
{
	vector<int> colData;
	int temp=0;
	for (int i = 0; i != 9; ++i)
	{
		if ((temp=matrix[i][colNum])>0)
		{
			colData.push_back(temp);
		}
	}
	return colData;
}


vector<int> sudoku::getGrid(vector<vector<int> > matrix,int rowNum, int colNum)
{
	int startRow = (rowNum / 3) * 3;
	int startCol = (colNum / 3) * 3;
	vector<int> gridData;
	int temp=0;
	for (int i = startRow; i != startRow + 3;++i)
	{
		for (int j = startCol; j != startCol + 3;++j)
		{
			if ((temp=matrix[i][j])>0)
			{
				gridData.push_back(temp);
			}
		}
	}
	return gridData;
}


vector<int> sudoku::getPossibleVaule(vector<vector<int> > matrix,int rowNum, int colNum)
{
	vector<int> nineNumbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> rowData = getRow(matrix,rowNum);
	vector<int> colData = getCol(matrix,colNum);
	vector<int> gridData = getGrid(matrix,rowNum, colNum);
	auto p = remove_if(nineNumbers.begin(), nineNumbers.end(), [rowData, colData, gridData](int n){
		if (find(rowData.begin(),rowData.end(),n)!=rowData.end())
		{
			return true;
		}
		if (find(colData.begin(),colData.end(),n)!=colData.end())
		{
			return true;
		}
		if (find(gridData.begin(),gridData.end(),n)!=gridData.end())
		{
			return true;
		}
		return false;
	});
	nineNumbers.erase(p, nineNumbers.end());
	return nineNumbers;
}



bool sudoku::getEmptyPos(vector<vector<int> > matrix,int &rowNum, int &colNum)
{
	for (int i = 0; i != 9; ++i)
	{
		for (int j = 0; j != 9;++j)
		{
			if (matrix[i][j]==0)
			{
				rowNum = i;
				colNum = j;
				return true;
			}
		}
	}
	return false;
}


bool sudoku::getSolution(vector<vector<int> > matrix)
{
	int rowNum = -1;
	int colNum = -1;
	if (getEmptyPos(matrix, rowNum, colNum))
	{
		auto possibleValues = getPossibleVaule(matrix, rowNum, colNum);
		if (possibleValues.empty())
		{
			return false;
		}
		for (auto e : possibleValues)
		{
			matrix[rowNum][colNum] = e;
			if (!getSolution(matrix))
			{
				continue;
			}
			else
				return true;
		}
		return false;


	}
	else
	{
		printSolution(matrix);
		cout << "________________________" << endl;
		return true;
	}
}


void sudoku::printSolution(vector<vector<int> > matrix)
{
	for (int i = 0; i != 9;++i)
	{
		for (int j = 0; j != 9;++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}