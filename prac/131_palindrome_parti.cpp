/*
OJ: https://leetcode.com/problems/palindrome-partitioning/description/
Time: 
Space: 
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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> pstrs;
        vector<string> pstr;
        getPalinStrs(s, 0, pstr, pstrs);
        return pstrs;
    }
private:
    void getPalinStrs(string s, int start, vector<string>& pstr, vector<vector<string>>& pstrs){
        int n = s.length();
        if(n == start){
            pstrs.push_back(pstr);
        }   
        for(int i=start; start<n;start++){
            pstr.push_back(s.substr(i, start-i+1));
            if(isPalin(pstr.back())){
                getPalinStrs(s, start+1, pstr, pstrs);
            }
            pstr.pop_back();
        }

    }
    bool isPalin(const string& s){
        int n = s.length();
        for(int i=0;i<(n/2);i++){
            if(s[i] != s[n-i-1]){
                return false;
            }
        }
        return true;
    }
};

int main() {
    string v = "aab";
    Solution s;
    for(auto ss: s.partition(v)){
        for(auto sub: ss){
            cout << sub << ", ";
        }
        cout << endl;
    }
    return 0;
}