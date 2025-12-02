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
    int minDiff = INT_MAX;
    int prevVal = -1; // sentinel meaning "no previous yet"

    void inorder(TreeNode *node)
    {
        if (!node)
            return;

        inorder(node->left);

        // process current node
        if (prevVal != -1)
        {
            minDiff = min(minDiff, node->val - prevVal);
        }
        prevVal = node->val;

        inorder(node->right);
    }

    int minDiffInBST(TreeNode *root)
    {
        inorder(root);
        return minDiff;
    }
};
