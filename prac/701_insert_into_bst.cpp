/*
OJ: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
Time:
Space:
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        if(val > root->val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};

int main() {
    Solution sol;
    vector<int> v = { 1, 2, 3 };
    cout << sol.hello(v) << endl;
    return 0;
}