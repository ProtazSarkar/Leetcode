#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


class Solution
{
public:
    ListNode* head = NULL;
    ListNode* curr = NULL;

    void insert(int x)
    {
        ListNode* newNode = new ListNode(x);

        if(head == NULL)
        {
            head = newNode;
            curr = newNode;
        }
        else
        {
            curr->next = newNode;
            curr = newNode;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int n = lists.size();

        vector<ListNode*> currents = lists;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        for(int i=0;i<n;i++)
        {
            if(currents[i])
            {
                pq.push({currents[i]->val,i});
            }
        }

        while(!pq.empty())
        {
            auto [val,i] = pq.top();
            pq.pop();

            insert(val);

            currents[i] = currents[i]->next;

            if(currents[i])
            {
                pq.push({currents[i]->val,i});
            }
        }

        return head;
    }
};