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
    struct Job{
        int start;
        int end;
        int profit;
    };

    static bool cmp(Job j1, Job j2){
        return j1.start < j2.start;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int maxProfit = 0, n = startTime.size(), i;
        Job j[n];
        for(i = 0; i<n;i++){
            j[i].start = startTime[i];
            j[i].end = endTime[i];
            j[i].profit = profit[i];
        }

        sort(j, j+n, cmp);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(i = 0; i<n;i++){
            while(!pq.empty() && j[i].start >= pq.top()[0]){
                maxProfit = max(maxProfit, pq.top()[1]);
                pq.pop();
            }
            pq.push({j[i].end, (maxProfit + j[i].profit)});
        }
        while(!pq.empty()){
            maxProfit = max(maxProfit, pq.top()[1]);
            pq.pop();
        }
        return maxProfit;
    }
};

int main() {
    vector<int> startTime = {1,2,3,3}, endTime = {3,4,5,6}, profit = {50,10,40,70};
    Solution s;
    cout << s.jobScheduling(startTime, endTime, profit) << endl;
    return 0;
}