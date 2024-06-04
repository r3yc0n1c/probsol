#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[1] < b[1])
            return true;
        else if (a[1] == b[1])
            return a[0] < b[0];
        return false;
    }
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end(), cmp);
        int n = events.size(), c = 0, end = events[n-1][1];
        set<int> d;

        for (int i=1;i<=n;i++)
            d.insert(i);

        for (int i = 0; i < n; i++)
        {
            auto it = d.lower_bound(events[i][0]);
            if(it == d.end() or *it > events[i][1])
                continue;
            else{
                c++;
                d.erase(it);
            }
        }
        return c;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};

    Solution s;
    cout << s.maxEvents(v) << endl;

    return 0;
}