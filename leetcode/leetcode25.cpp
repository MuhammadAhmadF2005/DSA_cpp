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
    ListNode *reverse(ListNode *head, int k)
    {
        ListNode *curr = head;
        ListNode *next = nullptr;
        ListNode *prev = nullptr;

        while (k-- && curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
        {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode *prevGroupEnd = &dummy;
        ListNode *curr = head;

        while (true)
        {
            ListNode *check = curr;
            int count = 0;
            while (check and count < k)
            {
                check = check->next;
                count++;
            }
            if (count < k)
            {
                break;
            }
            ListNode *groupHead = curr;
            ListNode *newHead = reverse(curr, k);

            prevGroupEnd->next = newHead; // connect previous group to new head
            groupHead->next = check;      // connect end of reversed group to next segment
           
            // Move pointers forward for next group
            prevGroupEnd = groupHead;
            curr = check;
        }

        return dummy.next;
    }
};