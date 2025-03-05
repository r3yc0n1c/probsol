/*
OJ: https://leetcode.com/problems/reorganize-string/description/?envType=problem-list-v2&envId=7p5x763&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1
Time: 
Space: 
*/

#include <iostream>
#include <queue>
using namespace std;

class Solution {
    public:
        string reorganizeString(string s) {
            vector<int> c(26);
            int l = (s.size()+1)/2;
            priority_queue<pair<int, char>> mh;

            for(char x: s){
                if(++c[x-'a'] > l){
                    return "";
                }
            }
        }
};

int main() {
    Solution sol;
    string s = "aab";
    cout << sol.reorganizeString(s) << endl;
    return 0;
}