#include <iostream>
#include <algorithm>
#include <vector>   
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size() - 1;
        for(int i = nums.size() - 1; i>=0; i--){
            if(nums[i] >= (end - i))
                end = i;
        }
        return end == 0;
    }
};

int main() {
    vector<int> v = {3,2,1,0,4};
    Solution s;
    cout << s.canJump(v) << endl;
    return 0;
}