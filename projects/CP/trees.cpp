#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int v)
    {
        data = v;
        left = right = nullptr;
    }
};

//--------------Preorder--------------//

void printPreorder(Node *node)
{
    if (node == nullptr)
        return;

    cout << node->data << " ";

    printPreorder(node->left);
    printPreorder(node->right);
}

//-------------Inorder--------------------//

void printInorder(Node *node)
{
    if (node == nullptr)
        return;

    printInorder(node->left);

    cout << node->data << " ";

    printInorder(node->right);
}

//--------------Postorder-------------------//

void PrintPostorder(Node *node)
{
    if (node == nullptr)
        return;

    PrintPostorder(node->left);

    PrintPostorder(node->right);

    cout << node->data << " ";
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    PrintPostorder(root);

    return 0;
}
