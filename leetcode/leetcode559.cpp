#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
        {
            return 0;
        }

        int depth = 0;
        for (Node *child : root->children)
        {
            depth = max(depth, maxDepth(child));
        }

        return depth + 1;
    }
};