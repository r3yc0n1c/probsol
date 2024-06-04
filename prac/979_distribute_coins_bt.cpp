/*
OJ: https://leetcode.com/problems/distribute-coins-in-binary-tree/description/
Time: O(n)
Space: O(n)
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
    int totalMoves = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int localMoves = root->val + dfs(root->left) + dfs(root->right) - 1;
        totalMoves += abs(localMoves);
        return localMoves;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return totalMoves;
    }
};

int main() {
    TreeNode* t = new TreeNode(3);
    t->right = new TreeNode(0);
    t->left = new TreeNode(0);

    Solution s;
    cout << s.distributeCoins(t)  << endl;
    return 0;
}