/*
OJ: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/
Time:
Space:
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n=nums1.size(), m=nums2.size();
        map<int, int> um;
        for(auto x: nums1){
            um.insert({x[0], x[1]});
        }
        
        for(auto x: nums2){
            if(um.find(x[0]) != um.end()){
                um[x[0]] += x[1];
            }
            else {
                um.insert({x[0], x[1]});
            }
        }
        vector<vector<int>> merged;
        for(auto x: um){
            merged.push_back({x.first, x.second});
        }
        return merged; 
    }
};

int main() {
    Solution sol;
    vector<vector<int>> nums1 = {{1,2},{2,3},{4,5}}, nums2 = {{1,4},{3,2},{4,1}};
    for(auto x: sol.mergeArrays(nums1,nums2))
        cout << x[0] << " " << x[1] << ", ";
    cout << endl;
    return 0;
}