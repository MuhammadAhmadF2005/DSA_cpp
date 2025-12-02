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
    int minDiff = 0;
    int prev = -1; // previous node

    void inorder(TreeNode *node)
    {
        if (!node)
            return;

        inorder(node->left);

        // process current node
        if (prev != -1)
        {
            minDiff = min(minDiff, abs(node->val - prev));
        }
        prev = node->val;

        inorder(node->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        inorder(root);
        return minDiff;
    }
};