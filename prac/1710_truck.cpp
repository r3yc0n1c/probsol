#include <iostream>
#include <vector>
#include <algo
using namespace std;

class Solution {
public:
    bool cpm(vector<int>& b1, vector<int>& b2){
        return b1[1] > b2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
    }
};

int main() {
    vector<vector<int>> boxTypes = {{1,3},{2,2},{3,1}};
    int truckSize = 4;

    Solution s;
    cout << s.maximumUnits();
    return 0;
}