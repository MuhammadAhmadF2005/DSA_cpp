#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;
int main()
{

    return 0;
}

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
    int prevVal = 0;
    int count = 0;
    int max = 0;
    vector<int> modes;
    vector<int> findMode(TreeNode *root)
    {
        inorder(root);
        return modes;
    }

    void inorder(TreeNode *node)
    {
        if (!node)
            return;

        inorder(node->left);

        // Process current node
        if (count == 0 || node->val != prevVal)
        {
            count = 1; // reset
            prevVal = node->val;
        }
        else
        {
            count++; // same as previous → increase freq
        }

        if (count > max)
        {
            max = count;
            modes.clear();
            modes.push_back(node->val);
        }
        else if (count == max)
        {
            modes.push_back(node->val);
        }

        inorder(node->right);
    }
};