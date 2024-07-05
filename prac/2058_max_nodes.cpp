/*
OJ: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/
Time:
Space:
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

/**
 * Definition for singly-linked list.
 */

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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        int minD = INT_MAX, maxD = INT_MIN;
        return {0};
    }
};

ListNode* makeList(vector<int>& arr){
    ListNode *head;

    for(int i: arr){
        head = new ListNode(i);
        head->val = i;
        head = head->next;
    }

    return head;
}

void printList(ListNode* head){
    ListNode *t = head;
    cout << t->val;
    // while(t->next != NULL){
    //     cout <<  t->val << " ";
    //     t = t->next;
    // }cout << endl;
}

int main()
{
    vector<int> v = {1,3,2,2,3,2,2,2,7};    
    ListNode *r = makeList(v);
    printList(r);

    Solution s;
    // s.nodesBetweenCriticalPoints(r);
    return 0;
}