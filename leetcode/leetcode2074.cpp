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
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        int k = 0;

        if (!head || !head->next)
        {
            return head;
        }

        ListNode *prev = head;
        ListNode *curr = head->next;
        int groupsize = 2;

        while (curr)
        {
            ListNode *temp = curr;
            int count = 0;
            while (count < groupsize && temp)
            {
                count++;
                temp = temp->next;
            }

            if (count % 2 == 0)
            {
                ListNode *prevnode = temp;
                ListNode *currnode = curr;

                for (int i = 0; i < count; i++)
                {
                    ListNode *next = currnode->next;
                    currnode->next = prevnode;
                    prevnode = currnode;
                    currnode = next;
                }
                prev->next = prevnode;
                prev = curr;
                curr = temp;
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
            groupsize++;
        }

        return head;
    }
};