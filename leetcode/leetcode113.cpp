#include <bits/stdc++.h>
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
    vector<vector<int>> result;

    void dfs(TreeNode *root, int targetSum, vector<int> &path)
    {
        if (root == nullptr)
            return;

        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr && targetSum == root->val)
        {
            result.push_back(path);
        }

        dfs(root->left, targetSum - root->val, path);
        dfs(root->right, targetSum - root->val, path);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        dfs(root, targetSum, path);
        return result;
    }
};
