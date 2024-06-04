/*
OJ: https://leetcode.com/problems/subsets/description/
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

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> subsets;
//         vector<int> subset;
//         getSubsets(nums, 0, subset, subsets);
//         return subsets;
//     }
// private:
//     void getSubsets(vector<int>& nums, int idx, vector<int>& subset, vector<vector<int>>&    subsets){
//         subsets.push_back(subset);
//         for(int i=idx;i<nums.size();i++){
//             subset.push_back(nums[i]);
//             getSubsets(nums, i+1, subset, subsets);
//             subset.pop_back();
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets = {{}};
        for(int num: nums){
            int n = subsets.size();
            for(int i=0;i<n;i++){
                subsets.push_back(subsets[i]);
                subsets.back().push_back(num);
            }
        }
        return subsets;
    }
};

int main() {
    vector<int> v = {1, 2, 3};
    Solution s;
    for(auto ss: s.subsets(v)){
        for(auto sub: ss){
            cout << sub << " ";
        }
        cout << endl;
    }
    return 0;
}