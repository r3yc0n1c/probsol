/*
OJ: https://leetcode.com/problems/binary-tree-preorder-traversal/description/
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }

        vector<int> v;
        stack<TreeNode*> stk;

        stk.push(root);

        while(!stk.empty()){
            root = stk.top();
            stk.pop();
            v.push_back(root->val);

            if(root->right)
                stk.push(root->right);
            
            if(root->left)
                stk.push(root->left);
        }

        return v;
    }
};

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(12);
    

    Solution s;
    for(int x: s.preorderTraversal(root))
        cout << x << " ";
    return 0;
}