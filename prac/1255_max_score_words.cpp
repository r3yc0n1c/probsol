/*
OJ: https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/
Time: 
Space: 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int a[26], b[26], maxScore = 0;

    void solve(int i, vector<string>& words, vector<int>& score){
        if(i == words.size()){
            int s = 0;
            for(int j=0;j<26;j++){
                if(a[j] < b[j]) return;
                s += score[j] * b[j];
            }
            maxScore = max(maxScore, s);
            return;
        }
        solve(i+1, words, score);
        for(char c: words[i]){
            b[c-'a']++;
        }
        solve(i+1, words, score);
        for(char c: words[i]){
            b[c-'a']--;
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(char c: letters){
            a[c - 'a']++;
        }
        solve(0, words, score);
        return maxScore;
    }    
};

int main() {
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};

    Solution s;
    cout << s.maxScoreWords(words, letters, score)  << endl;
    return 0;
}