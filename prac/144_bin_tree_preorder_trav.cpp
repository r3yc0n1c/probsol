/*
OJ: https://leetcode.com/problems/binary-tree-preorder-traversal/description/
Time: O(n)
Space: O(h)
*/
#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> preorderTraversalIterative(TreeNode* root) {
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

    vector<int> preorderTraversalRecursive(TreeNode* root) {
        vector<int> v;
        preorder(root, v);
        return v;
    }

private:
    void preorder(TreeNode* root, vector<int>& v){
        if(!root) return;

        v.push_back(root->val);
        preorder(root->left, v);
        preorder(root->right, v);
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
    for(int x: s.preorderTraversalIterative(root))
        cout << x << " ";
    cout << endl;
    
    for(int x: s.preorderTraversalRecursive(root))
        cout << x << " ";
    cout << endl;
    
    return 0;
}