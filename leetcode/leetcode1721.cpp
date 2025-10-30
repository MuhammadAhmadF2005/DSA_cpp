#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *curr = head;
        int count = 0;
        while (curr)
        {
            curr = curr->next;
            count++;
        }

        int front = k;
        int back = count - k;

        curr = head;

        for (int i = 1; i < front; i++)
        {
            curr = curr->next;
        }
        ListNode *first = curr;

        curr = head;
        for (int i = 0; i < back; i++)
        {
            curr = curr->next;
        }
        ListNode *second = curr;

        int temp = first->val;
        first->val = second->val;
        second->val = temp;

        return head;
    }
};