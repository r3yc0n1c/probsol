/*
OJ: https://leetcode.com/problems/evaluate-boolean-binary-tree/description/
Time: 
Space: 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->val == 3){
            return evaluateTree(root->left) & evaluateTree(root->right);
        }
        else if(root->val == 2){
            return evaluateTree(root->left) | evaluateTree(root->right);
        }
        return root->val;
    }
};

int main() {
    TreeNode* r = new TreeNode(0);
    // r->left = new TreeNode(1);
    // r->right = new TreeNode(3);
    // r->right->left = new TreeNode(0);
    // r->right->right = new TreeNode(1);

    Solution s;
    cout << s.evaluateTree(r)  << endl;
    return 0;
}