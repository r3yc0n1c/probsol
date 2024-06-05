/*
OJ: https://leetcode.com/problems/find-common-characters/
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
    vector<string> commonChars(vector<string>& words) {
        sort(words.begin(), words.end());
        vector<string> comms;
        
    }
};

int main() {
    vector<string> s1 = {"bella","label","roller"};
    Solution s;
    for(auto x: s.commonChars(s1)){
        cout << x << " ";
    }cout << endl;
    return 0;
}