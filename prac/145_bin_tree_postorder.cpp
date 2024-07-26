/*
OJ: https://leetcode.com/problems/binary-tree-postorder-traversal/
Time: 
Space: 
*/
#include <iostream>
#include <vector>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postorder(root, v);
        return v;
    }
private:
    void postorder(TreeNode* root, vector<int>& v){
        if(!root) return;

        postorder(root->left, v);
        postorder(root->right, v);
        v.push_back(root->val);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    

    Solution s;
    for(int x: s.postorderTraversal(root))
        cout << x << " ";
    cout << endl;
    return 0;
}