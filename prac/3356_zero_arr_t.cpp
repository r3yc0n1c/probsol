/*
OJ: https://leetcode.com/problems/zero-array-transformation-ii/
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int n=nums.size(), m=queries.size();
        vector<int> f(n+1);
        int ops=0, k=0;
        for(int i=0; i<n; i++){
            while(ops+f[i] < nums[i]){
                k++;
                if (k>m) return -1;
                const int l=queries[k-1][0], r=queries[k-1][1], v=queries[k-1][2];
                if (r<i) continue;
                f[max(l, i)]+=v;
                if (r + 1 < f.size())
                    f[r+1]-=v;
            }
            ops+=f[i];
        }
        return k;
    }
};

int main() {
    Solution sol;
    vector<int> v = { 1, 2, 3 };
    cout << sol.hello(v) << endl;
    return 0;
}