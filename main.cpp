#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  TreeNode *build_t(vector<int> &lasorder, int ls, int le, vector<int> &inorder, int is, int ie)
  {
    if (ls > le || is > ie)
      return nullptr;
    int val = lasorder[le];
    int val_pos = 0;
    for (int index = is; index <= ie; ++index)
    {
      if (inorder[index] == val)
      {
        val_pos = index;
        break;
      }
    }
    int left_count = val_pos - is;

    TreeNode *root = new TreeNode(val);
    root->left = build_t(lasorder, ls, le - left_count - 1, inorder, is, val_pos - 1);
    root->right = build_t(lasorder, le - left_count, le - 1, inorder, val_pos + 1, ie);
    return root;
  }
  TreeNode *build(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie)
  {
    if (ps > pe || is > ie)
      return nullptr;
    int val = preorder[ps];
    int val_pos = 0;
    for (int index = is; index <= ie; ++index)
    {
      if (inorder[index] == val)
      {
        val_pos = index;
        break;
      }
    }
    int left_count = val_pos - is;

    TreeNode *root = new TreeNode(val);
    root->left = build(preorder, ps + 1, ps + left_count, inorder, is, val_pos - 1);
    root->right = build(preorder, ps + left_count + 1, pe, inorder, val_pos + 1, ie);
    return root;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    return build_t(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }
};

void print_pre(TreeNode *root)
{
  if (root == nullptr)
    return;
  cout << root->val << " ";
  print_pre(root->left);
  print_pre(root->right);
}

void print_in(TreeNode *root)
{
  if (root == nullptr)
    return;
  print_in(root->left);
  cout << root->val << " ";
  print_in(root->right);
}

void print_las(TreeNode *root)
{
  if (root == nullptr)
    return;
  print_las(root->left);
  print_las(root->right);
  cout << root->val << " ";
}

int main(int argc, const char *argv[])
{
  vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
  vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
  vector<int> lasorder = {4, 5, 2, 6, 7, 3, 1};
  Solution s;
  TreeNode *root = s.buildTree(lasorder, inorder);
  print_pre(root);
  cout << endl;
  print_in(root);
  cout << endl;
  print_las(root);
  cout << endl;
  return 0;
}
