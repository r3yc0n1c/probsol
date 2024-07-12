/*
OJ: https://leetcode.com/problems/maximum-score-from-removing-substrings/description/
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

class Solution
{
public:
    // with stack
    int maximumGain(string s, int x, int y)
    {
        // high priority pair, low prio
        string hpp = "ab", lpp = "ba";
        int totalScore = 0;

        if (x < y){
            hpp = "ba";
            lpp = "ab";
        }
        else{
            swap(x, y);
        }

        //
        stack<char> stk;
        for (char c : s){
            if (!stk.empty() && c == hpp[1] && stk.top() == hpp[0]){
                totalScore += y;
                stk.pop();
            }else {
                stk.push(c);
            }
            // cout << s << endl;
        }

        stack<char> stk2;

        while(!stk.empty()){
            // cout << stk.top();
            // stk.pop();
            if (!stk2.empty() && stk.top() == lpp[0] && stk2.top() == lpp[1]){
                stk2.pop();
                totalScore += x;
            }else {
                stk2.push(stk.top());
            }
            stk.pop();
        }

        return totalScore;
    }
};

int main()
{
    string str = "cdbcbbaaabab";
    int x = 4, y = 5;
    Solution s;
    cout << s.maximumGain(str, x, y) << endl;
    return 0;
}