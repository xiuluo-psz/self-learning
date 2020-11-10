#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool dfs(vector<vector<int>> &board, int horse_row, int horse_col,
			 vector<int> &car)
	{
		if (horse_row < 0 || horse_row > 9 || horse_col < 0 || horse_col > 8)
		{
			return false;
		}
		if (board[horse_row][horse_col])
		{
			return false;
		}
		cout << horse_row << ":" << horse_col << endl;
		if (horse_row == car[0] && horse_col == car[1])
		{
			board[horse_row][horse_col] = 1;
			return true;
		}
		board[horse_row][horse_col] = 1;
		bool result;
		result = dfs(board, horse_row - 1, horse_col - 2, car) ||
				 dfs(board, horse_row - 1, horse_col + 2, car) ||
				 dfs(board, horse_row - 2, horse_col - 1, car) ||
				 dfs(board, horse_row - 2, horse_col + 1, car) ||
				 dfs(board, horse_row + 1, horse_col - 2, car) ||
				 dfs(board, horse_row + 1, horse_col + 2, car) ||
				 dfs(board, horse_row + 2, horse_col - 1, car) ||
				 dfs(board, horse_row + 2, horse_col + 1, car);
		return result;
	}
	bool eatable(vector<vector<int>> &board, vector<int> &horse,
				 vector<int> &car)
	{
		return dfs(board, horse[0], horse[1], car);
	}
};

int main(int argc, const char *argv[])
{
	// vector<vector<int>> board(10, vector<int>(9, 0));
	// vector<int> horse = {6, 5};
	// vector<int> car = {1, 2};
	// Solution s;
	// cout << s.eatable(board, horse, car) << endl;
	// for (auto v : board)
	// {
	// 	for (auto item : v)
	// 	{
	// 		cout << (item == 1 ? "." : "+") << " ";
	// 	}
	// 	cout << endl;
	// }
	return 0;
}