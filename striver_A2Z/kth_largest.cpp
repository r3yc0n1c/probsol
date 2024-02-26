#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq (begin(nums), end(nums));

        while (--k)
        {
            pq.pop();
        }

        return pq.top();
    }
};

int main(){
    Solution s;

    vector<int> n{1,2,3,4,5};
    cout << s.findKthLargest(n, 3);
}