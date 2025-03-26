/*
OJ: link
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> s;
        
        if(matrix.empty() || matrix[0].empty()) return s;

        int l=0, r=n-1,t=0,b=m-1, i;

        while(l <= r && t <= b) {
            for(i=l;i<=r;i++)
                s.push_back(matrix[t][i]);
            t++;
            for(i=t;i<=b;i++)
                s.push_back(matrix[i][r]);
            r--;
            if(t <= b){
                for(i=r;i>=l;i--) {
                    s.push_back(matrix[b][i]);
                }
                b--;
            }
            if(l <= r){
                for(i=b;i>=t;i--) {
                    s.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    for (auto x: sol.spiralOrder(v))
        cout << x << endl;
    return 0;
}