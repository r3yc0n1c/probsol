#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> um;
        int i, n = croakOfFrogs.length(), maxFrog = 0;
        for(i=0;i<n;i++){
            um[croakOfFrogs[i]]++;
            if(um['r']>um['c'] || um['o']>um['r'] || um['a']>um['o'] || um['k']>um['a']){
                return -1;
            }
            maxFrog = max(maxFrog, um['c'] - um['k']);
        }
        if(um['c']!=um['k']) return -1;
        return maxFrog;
    }
};

int main() {
    Solution s;
    cout << s.minNumberOfFrogs("croakcroak") << endl;
    return 0;
}