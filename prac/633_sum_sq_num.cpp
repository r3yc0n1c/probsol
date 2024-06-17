/*
OJ: https://leetcode.com/problems/sum-of-square-numbers/description/
Time: O(sqrt(n))
Space: 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int a;
        double b;
        for(a=0;a<=sqrt(c); a++){
            b = sqrt(c - a*a);
            if((int)b == b){
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.judgeSquareSum(4)  << endl;
    return 0;
}