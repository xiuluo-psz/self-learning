#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool dfs(vector<vector<char>> &board, vector<vector<int>> &visited, int pos_i, int pos_j, string &world, int index)
  {
    if (pos_i < 0 || pos_i >= board.size() || pos_j < 0 || pos_j >= board[0].size())
    {
      return false;
    }
    if (visited[pos_i][pos_j])
    {
      return false;
    }
    if (board[pos_i][pos_j] != world[index])
    {
      return false;
    }
    if (index == world.size() - 1)
    {
      return true;
    }

    bool result = false;
    visited[pos_i][pos_j] = 1;
    index++;
    result = dfs(board, visited, pos_i + 1, pos_j, world, index) ||
             dfs(board, visited, pos_i - 1, pos_j, world, index) ||
             dfs(board, visited, pos_i, pos_j + 1, world, index) ||
             dfs(board, visited, pos_i, pos_j - 1, world, index);
    return result;
  }
  bool exist(vector<vector<char>> &board, string &world)
  {
    if (board.size() == 0 || board[0].size() == 0)
      return world == "";
    int line = board.size();
    int col = board[0].size();
    vector<vector<int>> visited(line, vector<int>(col, 0));
    for (int i = 0; i < line; ++i)
    {
      for (int j = 0; j < col; ++j)
      {
        // cout << i << " " << j << endl;
        if (dfs(board, visited, i, j, world, 0))
        {
          return true;
        }
      }
    }
    return false;
  }
};

int main(int argc, const char *argv[])
{
  vector<char> c1 = {'A', 'B', 'C', 'D'};
  vector<char> c2 = {'E', 'F', 'G', 'H'};
  vector<char> c3 = {'I', 'J', 'K', 'L'};
  vector<vector<char>> board = {c1, c2, c3};
  string str = "AEIJK";

  Solution s;
  cout << s.exist(board, str);

  return 0;
}