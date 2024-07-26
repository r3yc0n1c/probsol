/*
OJ: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
Time: O(n)
Space: O(n)
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return v;
    }
private:
    void inorder(TreeNode* root, vector<int>& v){
        if(!root) return;

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    for(int x: s.inorderTraversal(root))
        cout << x << " ";
    cout << endl;
    return 0;
}