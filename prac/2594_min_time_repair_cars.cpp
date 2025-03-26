/*
OJ: https://leetcode.com/problems/minimum-time-to-repair-cars
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1, r = (ll)*min_element(ranks.begin(), ranks.end()) * cars * cars;

        while(l < r) {
            ll m = (l+r)/2, totalCars = 0;
            bool canRepAll = false;

            for(int rank: ranks) {
                totalCars += sqrt(m/rank);
                if(totalCars >= cars) {
                    canRepAll = true;
                    break;
                }
            }
            if(canRepAll)
                r = m;
            else 
                l = m+1;
        }
        return l;
    }
};

int main() {
    Solution sol;
    vector<int> ranks = {4,2,3,1};
    int cars = 10;
    cout << sol.repairCars(ranks, cars) << endl;
    return 0;
}