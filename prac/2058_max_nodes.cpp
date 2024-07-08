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

// TODO

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        int i = 1, minIdx = INT_MIN, minDiff = INT_MAX,  = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        if(!prev || !curr || !curr->next){
            return {-1, -1};
        }

        while(curr->next != NULL){
            if((curr->val > prev->val && curr->val > curr->next->val) || (curr->val < prev->val && curr->val < curr->next->val)){
                if(maxIdx != 0){
                    minDiff = min(i - maxIdx, minDiff);
                }
                minIdx = min(minIdx, i);
                maxIdx = i;
            }
            i++;
            prev = curr;
            curr = curr->next;
        }

        return {minDiff, maxIdx - minIdx};
    }
};

ListNode* makeList(vector<int>& arr){
    ListNode *head = new ListNode(arr[0]);
    arr.erase(arr.begin());

    ListNode *curr = head;

    for(int i: arr){
        // cout << curr->val << " ";
        curr->next = new ListNode(i);
        curr = curr->next;
    }

    return head;
}

void printList(ListNode* head){
    ListNode *t = head;
    while(t != NULL){
        cout <<  t->val << " ";
        t = t->next;
    }cout << endl;
}

int main()
{
    vector<int> v = {1,3,2,2,3,2,2,2,7};    
    ListNode *r = makeList(v);
    printList(r);

    Solution s;
    
    vector<int> x = s.nodesBetweenCriticalPoints(r);

    cout << x[0] << " " << x[1];

    
    return 0;
}