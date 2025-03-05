/*
OJ: https://leetcode.com/problems/search-in-a-binary-search-tree/
Time:
Space:
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;

        if (root->val == val) {
            return root;
        }
        else if (root->val > val) {
            return searchBST(root->left, val);
        }
        else {
            return searchBST(root->right, val);
        }

    }
};

int main() {
    Solution sol;
    vector<int> v = { 1, 2, 3 };
    cout << sol.hello(v) << endl;
    return 0;
}