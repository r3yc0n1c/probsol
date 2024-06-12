/*
OJ: https://leetcode.com/problems/sort-colors/description/
Time: 
Space: 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    vector<int> c = {2,0,2,1,1,0};
    Solution s;
    s.sortColors(c);    

    for(int x: c)
        cout << x << " ";
    cout << endl;
    return 0;
}