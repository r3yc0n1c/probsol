/*
OJ: https://leetcode.com/problems/find-common-characters/
Time: 
Space: 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> comms;
        vector<int> minFreq(26, INT_MAX);
        int i;

        for(string w: words){
            vector<int> tempFreq(26, 0);
            for(char c: w){
                tempFreq[c-'a']++;
            }
            for(i=0;i<26;i++){
                minFreq[i] = min(minFreq[i], tempFreq[i]);
            }           
        }
        for(i=0;i<26;i++){
            while(minFreq[i]){
                comms.push_back(string(1, 'a'+i));
                minFreq[i]--;
            }
        }

        return comms;
    }
};

int main() {
    vector<string> s1 = {"cool","lock","cook"}; //{"bella","label","roller"};
    Solution s;
    for(auto x: s.commonChars(s1)){
        cout << x << " ";
    }cout << endl;
    return 0;
}