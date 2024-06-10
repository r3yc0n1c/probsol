/*
OJ: https://leetcode.com/problems/height-checker/description/
Time: 
Space: 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        int c = 0;

        sort(expected.begin(), expected.end());

        for(int i=0;i<heights.size();i++){
            if(heights[i] != expected[i]){
                c++;
            }
        }
        return c;
    }
};

int main() {
    vector<int> v = {5,1,2,3,4}; //{1,1,4,2,1,3};
    Solution s;
    cout << s.heightChecker(v) << endl;
    return 0;
}