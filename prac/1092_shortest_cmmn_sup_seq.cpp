/*
OJ: https://leetcode.com/problems/shortest-common-supersequence/description/
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = m, j = n;
        string scss = "";

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scss.push_back(str1[i - 1]);
                i--; j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                scss.push_back(str1[i - 1]);
                i--;
            }
            else {
                scss.push_back(str2[j - 1]);
                j--;
            }
        }

        while (i > 0) {
            scss.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            scss.push_back(str2[j - 1]);
            j--;
        }

        reverse(scss.begin(), scss.end());

        return scss;
    }
};

int main() {
    Solution sol;
    string s1 = "abcd";
    string s2 = "cde";
    cout << sol.shortestCommonSupersequence(s1, s2) << endl;
    return 0;
}