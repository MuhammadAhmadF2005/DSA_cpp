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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        if (!root)
            return res;

        dfs(root, "", res);
        return res;
    }

    void dfs(TreeNode *node, string path, vector<string> &res)
    {
        if (!node)
        {
            return;
        }

        if (path.empty())
        {
            path = to_string(node->val); // first val has no arrow before
        }
        else
        {
            path += "->" + to_string(node->val);
        }

        if (!node->left and !node->right)
        { // if leaf pushback a path
            res.push_back(path);
            return;
        }

        dfs(node->left, path, res);
        dfs(node->right, path, res);
    }
};