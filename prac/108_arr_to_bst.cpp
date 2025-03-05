/*
OJ: link
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
    TreeNode* toBTS(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = toBTS(nums, left, mid - 1);
        root->right = toBTS(nums, mid + 1, right);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBTS(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> v = { 1, 2, 3 };
    cout << sol.hello(v) << endl;
    return 0;
}