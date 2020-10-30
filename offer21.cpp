#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> exchange(vector<int> &nums)
  {
    int i = 0;
    int j = nums.size() - 1;
    while (i < j)
    {
      while (i < nums.size() && nums[i] % 2 == 1)
      {
        i++;
      }
      while (j >= 0 && nums[j] % 2 == 0)
      {
        j--;
      }
      if (i < j)
      {
        swap(nums[i], nums[j]);
      }
    }
    return nums;
  }
};

int main(int argc, const char *argv[])
{
  vector<int> nums = {1, 2, 3, 4, 5, 2, 6, 3, 5, 7, 9, 1, 0};
  Solution s;
  vector<int> result = s.exchange(nums);
  for (auto num : result)
  {
    cout << num << " ";
  }
  return 0;
}