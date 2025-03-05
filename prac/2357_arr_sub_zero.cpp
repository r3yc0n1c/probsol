/*
OJ: https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/
Time: 
Space: 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct comp {
    bool operator()(int a, int b) const { return a > b; }
};

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        // priority_queue<int, vector<int>, comp> pq;
        for(int x: nums)
            if(x)
                pq.push(x);
        
        int c = 0, min = 0, curr;
        while(!pq.empty()) {
            curr = pq.top();
            pq.pop();
            if(curr > min) {
                c++;
                min = curr;
            }
        }
        return c;
    }
};

int main() {
    Solution sol;
    vector<int> v = {1,5,0,3,5};
    cout << sol.minimumOperations(v) << endl;
    return 0;
}