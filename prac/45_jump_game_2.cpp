#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;

        int curr_end = 0, farthest = 0, minJumps = 0;

        for (int i = 0; i < n; i++)
        {
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1)
                return ++minJumps;
            if (i == curr_end)
            {
                minJumps++;
                curr_end = farthest;
            }
        }
        return minJumps;
    }
};

int main()
{
    vector<int> v = {2, 3, 1, 1, 4};
    Solution s;
    cout << s.jump(v) << endl;
    return 0;
}