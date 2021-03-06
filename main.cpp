#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <bitset>
using namespace std;

#define vprint(v)               \
  {                             \
    for (auto item : v)         \
    {                           \
      std::cout << item << " "; \
    }                           \
    std::cout << std::endl;     \
  }

// 车马问题
class Solution_t
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

struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// 验证用
int main(int argc, const char *argv[])
{
  vector<string> name = {"123", "psz", "1234", "pszz"};
  vprint(name);
  return 0;
}