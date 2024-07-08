/*
OJ: https://leetcode.com/problems/water-bottles/description/
Time: 
Space: 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int maxBottles = numBottles;
        
        while(numBottles >= numExchange){
            maxBottles += numBottles / numExchange;
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
        }

        return maxBottles;
    }
};

int main() {
    Solution s;
    cout << s.numWaterBottles(13, 3)<< endl;
    return 0;
}