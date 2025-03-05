/*
OJ: https://leetcode.com/problems/copy-list-with-random-pointer
Time: 
Space: 
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
// */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> new_list;
        Node* curr = head;
        while(curr) {
            new_list[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr) {
            new_list[curr]->next = new_list[curr->next];
            new_list[curr]->random = new_list[curr->random];
            curr = curr->next;
        }
        return new_list[head];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v = {{3,NULL},{3,0},{3,NULL}};
    return 0;
}