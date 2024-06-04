/*
OJ: https://leetcode.com/problems/longest-palindrome/description/
Time: 
Space: 
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        int odd=0;
        for(char c: s){
            freq[c]++;
            if(freq[c] & 1){
                odd++;
            }else{
                odd--;
            }
        }
        if(odd > 1){
            return (s.length() - odd + 1);
        }
        return s.length();
    }
};

int main() {
    string str = "aabbccdd";
    Solution s;
    cout << s.longestPalindrome(str)  << endl;
    return 0;
}