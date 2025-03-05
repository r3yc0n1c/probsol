/*
OJ: https://leetcode.com/problems/contains-duplicate/
Time:
Space:
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /*
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j] == nums[i])
                    return true;
            }
        }
        return false;
    }
    */
    /*
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for(int x: nums){
            if(s.find(x) != s.end())
                return true;
            s.insert(x);
        }
        return false;
    }
    */
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.size());

        for (int x : nums) {
            if(!s.insert(x).second) // insert() returns a pair <iterator,bool> where 2nd one tells if 'x' is already present or not
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> v = { 1,2,3,41 };
    cout << sol.containsDuplicate(v) << endl;
    return 0;
}