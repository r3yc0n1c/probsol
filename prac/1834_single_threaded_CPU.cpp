#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        }
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size(), i = 0, j = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        vector<int> taskID(n);
        
        // store IDs
        while(i<n){
            tasks[i].push_back(i);
            i++;
        }

        sort(tasks.begin(), tasks.end());
        long currEnqTime = tasks[0][0];
        pair<int, int> currTask;
        i = 0;
        while(i < n){
            while(j < n && tasks[j][0] <= currEnqTime){
                pq.push({tasks[j][1], tasks[j][2]});
                j++;
            }

            if(!pq.empty()){
                currTask = pq.top();
                pq.pop();
                currEnqTime += currTask.first;
                taskID[i++] = currTask.second;
            }
            else{
                currEnqTime = tasks[j][0];
            }
        }
        return taskID;
    }
};

int main() {
    vector<vector<int>> v = {{559841983,67647432},{424805198,991980212},{515634828,31532862},{219345346,591200755},{171790137,689153372},{981058035,670269512},{323108233,654089671},{891095095,590376742}}; //{{1,2},{2,4},{3,2},{4,1}};
    Solution s;
    auto r = s.getOrder(v);
    for(auto x: r)
        cout << x << " ";
    cout << endl;
    
    return 0;
}