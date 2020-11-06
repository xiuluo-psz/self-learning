#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert_opt(TreeNode *node, int value)
{
}

void delete_opt(TreeNode *node, int value)
{
}

TreeNode *find_opt(TreeNode *root, int value)
{
  if (!root)
    return root;
  TreeNode *cur = root;
  while (cur)
  {
    if (cur->val == value)
    {
      return cur;
    }
    else if (cur->val < value)
    {
      cur = cur->right;
    }
    else
    {
      cur = cur->left;
    }
  }

  return nullptr;
}

void arr(TreeNode *root, vector<int> &v)
{
  if (!root)
    return;
  arr(root->left, v);
  v.push_back(root->val);
  arr(root->right, v);
}

int main(int argc, const char *argv[])
{
  TreeNode *root = new TreeNode(4);
  TreeNode *l = new TreeNode(2);
  l->left = new TreeNode(1);
  l->right = new TreeNode(3);
  TreeNode *r = new TreeNode(6);
  r->left = new TreeNode(5);
  r->right = new TreeNode(7);
  root->left = l;
  root->right = r;

  TreeNode *result = find_opt(root, 16);
  cout << (result ? result->val : 0) << endl;
  vector<int> v;
  arr(root, v);
  for (auto i : v)
  {
    cout << i << " ";
  }

  return 0;
}