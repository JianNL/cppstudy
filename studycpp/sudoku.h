#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class sudoku
{
public:
	sudoku()
	{
		
	}
	bool getSolution(vector<vector<int> > matrix);
	void printSolution(vector<vector<int> > matrix);

private:
	vector<int> getRow(vector<vector<int> > matrix,int rowNum);
	vector<int> getCol(vector<vector<int> > matrix,int colNum);
	vector<int> getGrid(vector<vector<int> > matrix,int rowNum, int colNum);
	vector<int> getPossibleVaule(vector<vector<int> > matrix,int rowNum, int colNum);
	bool getEmptyPos(vector<vector<int> > matrix,int &rowNum, int &colNum);
	
};