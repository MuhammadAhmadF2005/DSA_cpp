#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        return dfs(root, false);
    }

    int dfs(TreeNode *node, bool isLeft)
    {
        if (!node)
        {
            return 0;
        }

        if (isLeft and !node->left and !node->right)
        { // if is leaf
            return node->val;
        }

        return dfs(node->left, true) + dfs(node->right, false);
    }
};