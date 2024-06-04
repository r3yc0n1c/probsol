#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    // K sorted Array / Nearly Sorted Array problem
    void sortKNearly(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq(begin(nums), begin(nums) + (k + 1));

        int idx = 0;
        for (int i = k + 1; i < nums.size(); i++)
        {
            nums[idx] = pq.top();
            idx++;
            pq.pop();
            pq.push(nums[i]);
        }

        while (!pq.empty())
        {
            nums[idx] = pq.top();
            idx++;
            pq.pop();
        }
    }
};

int main()
{
    vector<int> n = {1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
    int k = 2;

    Solution s;
    s.sortKNearly(n, k);

    for (int i = 0; i < n.size(); i++)
        cout << n[i] << " ";
    cout << endl;

    return 0;
}