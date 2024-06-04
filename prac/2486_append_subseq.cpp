/*
OJ: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/
Time: O(n + m) // n=s.length(), m=t.length()
Space: O(1)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0, m=s.length(), n=t.length();
        while(i<m && j<n){
            if(s[i] == t[j]){
                j++;
            }
            i++;
        }
        return n-j;
    }
};

int main() {
    string a = "coaching", b = "coding";
    Solution s;
    cout << s.appendCharacters(a, b)  << endl;
    return 0;
}