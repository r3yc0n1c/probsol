/*
OJ: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length(), m = k, w;

        for(int i=0;i<=n-k;i++) {
            w = 0;
            for(int j=i;j<k+i;j++){
                if(blocks[j] == 'W') w++;
            }
            m = min(m, w);
            // cout << i << "," << m << "," << endl;
        }
        return m;
    }
    */

    int minimumRecolors(string blocks, int k) {
        int n = blocks.length(), w = count(blocks.begin(), blocks.begin() + k, 'W');
        int rc = w;

        for (int l = 0, r = k; r < n;l++, r++) {
            w += (blocks[r] == 'W') - (blocks[l] == 'W');
            rc = min(rc, w);
        }
        return rc;
    }
};

int main() {
    Solution sol;
    string s = "WBWBBBW";
    int k = 2;
    cout << sol.minimumRecolors(s, k) << endl;
    return 0;
}