
/*
OJ: https://leetcode.com/problems/subsets-ii/
Time: 
Space: 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> currSet;
        vector<vector<int>> solSet;
        sort(nums.begin(), nums.end());
        createSubsDup(nums, currSet, solSet, 0);
        return solSet;
    }
    void createSubsDup(vector<int>& nums, vector<int>& currSet, vector<vector<int>>& solSet, int idx){
        solSet.push_back(currSet);
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            currSet.push_back(nums[i]);
            createSubsDup(nums, currSet, solSet, i+1);
            currSet.pop_back();
        }
    }
};