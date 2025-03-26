/*
OJ: https://leetcode.com/problems/find-missing-and-repeated-values/description/
Time: O(n^2)
Space: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    //     int a=-1, b=-1, n = grid.size(), s = n*n;
    //     vector<int> f(s+1, 0);

    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             f[grid[i][j]]++;
    //         }
    //     }

    //     for(int i=1;i<=s;i++){
    //         if(f[i] == 2)
    //             a = i;
    //         if(f[i] == 0)
    //             b = i;
    //     }
    //     return {a,b};
    // }
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), s = n * n;

        long long exp_sum = 1LL * s * (s + 1) / 2;
        long long exp_sum_sqr = 1LL * s * (s + 1) * (2 * s + 1) / 6;

        long long orig_sum = 0, orig_sum_sqr = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                orig_sum += grid[i][j];
                orig_sum_sqr += (long long)grid[i][j] * grid[i][j];
            }
        }

        // a - b
        long long diff = orig_sum - exp_sum;

        // a² - b²
        long long diff_sqr = orig_sum_sqr - exp_sum_sqr;

        // a + b = (a² - b²) / (a - b)
        long long sum_a_b = diff_sqr / diff;

        int a = (sum_a_b + diff) / 2;
        int b = (sum_a_b - diff) / 2;

        return { a, b };
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v = { { 1, 3},{2, 2 } };

    vector<int> ans = sol.findMissingAndRepeatedValues(v);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}