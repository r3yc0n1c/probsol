/*
OJ: https://leetcode.com/problems/apply-operations-to-an-array/description/
Time:
Space:
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n= nums.size(), c=0;
        vector<int> q;
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
            if(nums[i]==0)
                c++;      
        }
        // for(int x: nums)
        //     cout << x << " ";
        // cout << endl;
        for(int x: nums){
            if(x){
                q.push_back(x);
            }
        }
        for(int i=0;i<c;i++){
            q.push_back(0);
        }
        return q;
    }
};

int main() {
    Solution sol;
    vector<int> v = { 1,2,2,1,1,0 };
    for(int x: sol.applyOperations(v))
        cout << x << ", ";
    cout<< endl;
    return 0;
}