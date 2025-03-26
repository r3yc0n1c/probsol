/*
OJ: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), c=0;
        int i=0,j=0;

        unordered_map<char, int> mp;

        while(j<n)
        {
            mp[s[j]]++;

            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1)
            {
                c += (n - j);

                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return c;
    }
};

int main() {
    Solution sol;
    string s = "abcabc";
    
    cout << sol.numberOfSubstrings(s) << endl;
    return 0;
}