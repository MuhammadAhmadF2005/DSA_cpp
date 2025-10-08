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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (root->left == NULL and root->right == NULL) // if leaf node check condition
        {
            return root->val == targetSum;
        }

        // if not leaf, continue recursively till you reach leaf ..//

        return hasPathSum(root->left, targetSum - root->val) or
               hasPathSum(root->right, targetSum - root->val);
    }
};