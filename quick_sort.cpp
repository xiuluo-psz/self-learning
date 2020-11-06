#include <iostream>
#include <array>
#include <memory>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>

void quick_sort(std::vector<int> *v, int left, int right)
{
  if (left > right)
    return;
  int pivot = v->at(left);
  int l = left;
  int r = right;
  while (l < r)
  {
    while (l < r && v->at(r) >= pivot)
      r--;
    v->at(l) = v->at(r);
    while (l < r && v->at(l) <= pivot)
      l++;
    v->at(r) = v->at(l);
  }
  v->at(l) = pivot;
  quick_sort(v, left, l - 1);
  quick_sort(v, l + 1, right);
}

void merge_sort(std::vector<int> *v, int left, int right)
{
  if (left == right)
    return;
  int mid = (left + right) / 2;
  merge_sort(v, left, mid);
  merge_sort(v, mid + 1, right);
  int temp[right - left + 1];
  int l = left, r = mid + 1, loc = 0;
  while (l <= mid && r <= right)
  {
    if (v->at(l) < v->at(r))
      temp[loc++] = v->at(l++);
    else
      temp[loc++] = v->at(r++);
  }
  while (l <= mid)
    temp[loc++] = v->at(l++);
  while (r <= right)
    temp[loc++] = v->at(r++);
  for (int i = left; i <= right; i++)
  {
    v->at(i) = temp[i - left];
  }
}

std::vector<int> nextGreatDay(std::vector<int> &nums)
{
  std::vector<int> res(nums.size());
  std::stack<int> s;
  // 判定个子高矮
  for (int i = nums.size() * 2 - 1; i >= 0; --i)
  {
    // 矮个起开
    while (!s.empty() && nums[s.top()] <= nums[i % nums.size()])
    {
      s.pop();
    }
    res[i % nums.size()] = s.empty() ? 0 : s.top() - i % nums.size();
    s.push(i % nums.size());
  }
  return res;
}

// nums1 = {6, 1, 8}, nums2 = {7, 0, 1, 3, 5, 4, 6, 8}
std::vector<int> nextGreatElement(std::vector<int> &nums1, std::vector<int> &nums2)
{
  std::vector<int> res;
  std::unordered_map<int, int> mp;
  std::stack<int> sk;
  for (int num : nums2)
  {
    while (!sk.empty() && sk.top() < num)
    {
      mp[sk.top()] = num;
      std::cout << "pop:" << sk.top() << std::endl;
      sk.pop();
    }
    sk.push(num);
    std::cout << "push:" << num << std::endl;
  }
  while (!sk.empty())
  {
    mp[sk.top()] = -1;
    sk.pop();
  }
  for (int num : nums1)
  {
    res.push_back(mp[num]);
  }
  // 判定个子高矮
  // for (int idx = 0; idx < nums2.size(); --idx)
  // {
  // int temp = 0;
  // for (int i = nums1.size() - 1; i >= 0; --i)
  // {
  //   // 矮个起开
  //   while (!s.empty() && s.top() <= nums2[idx])
  //   {
  //     s.pop();
  //   }
  // }
  // res[idx] = s.empty() ? -1 : s.top();
  // s.push(temp);
  // }
  return res;
}

std::vector<int> nextDreatE(std::vector<int> &T)
{
  int size = T.size();
  std::vector<int> result(size);
  std::stack<int> s;
  for (int index = size * 2 - 1; index >= 0; --index)
  {
    while (!s.empty() && s.top() <= T[index % size])
    {
      s.pop();
    }
    result[index % size] = s.empty() ? -1 : s.top();
    s.push(T[index % size]);
  }
  return result;
}

int main()
{
  std::cout << std::endl
            << "run begin <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
  // std::vector<int> v = {2, 4, 6, 4, 7, 9, 1, 4, 67, 42, 64, 234, 46, 8, 2, 546, 46, 45, 6, 435, 35, 0, 6, 7, 76878, 86, 57, 567, 65};
  // merge_sort(&v, 0, v.size() - 1);
  // for (auto item : v)
  //   std::cout << item << " ";
  // std::cout << std::endl;
  // for (std::vector<int>::reverse_iterator item = v.rbegin(); item != v.rend(); item++)
  //   std::cout << *item << " ";
  // std::cout << std::endl;

  // int arr[] = {7, 0, 1, 2, 4, 5, 8};
  // int children[] = {8, 1, 7};
  std::vector<int> nums2 = {9, 0, 1, 3, 5, 4, 6, 8};
  std::vector<int> nums1 = {6, 1, 8};
  auto result = nextDreatE(nums2);
  for (auto item : result)
    std::cout << item << " ";
  std::cout << std::endl;

  std::cout << "run end >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
  return 0;
}