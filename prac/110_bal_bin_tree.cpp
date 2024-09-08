/*
OJ: 
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
 Definition for a binary tree node.*/

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
    bool isBal = true;
    bool isBalanced(TreeNode* root) {
        getHeight(root);
        return isBal;
    }
    
    bool getHeight(TreeNode* root) {
        if(!root) return 0;
        if(!isBal) return 0;

        int lh = isBalanced(root->left);
        int rh = isBalanced(root->right);

        if(abs(lh-rh) > 1) isBal = false;
        return max(lh, rh)+1;
    }
};

int main() {
    TreeNode *r = new TreeNode(3);
    r->left = new TreeNode(9);
    r->right = new TreeNode(20);
    r->right->left = new TreeNode(15);
    r->right->right = new TreeNode(7);

    Solution s;
    cout << s.isBalanced(r) << endl;
    return 0;
}