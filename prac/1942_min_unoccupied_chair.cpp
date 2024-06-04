#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        vector<pair<int, int>> arr;
        vector<pair<int, int>> dep;
        int i = 0, j = 0, k = 0, n = times.size(), chair[10001];

        for (int i = 0; i < n; i++)
        {
            arr.push_back({times[i][0], i + 1});
            dep.push_back({times[i][1], i + 1});
        }

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        memset(chair, 0, sizeof(chair));

        while (i < n && j < n)
        {
            if (arr[i].first < dep[j].first)
            {
                for (k = 0; k < 10001; k++)
                {
                    if (!chair[k])
                    {
                        chair[k] = arr[i].second;
                        if (arr[i].second == targetFriend + 1)
                        {
                            return k;
                        }
                        break;
                    }
                }
                i++;
            }
            else
            {
                for (k = 0; k < 10001; k++)
                {
                    if (chair[k] == dep[j].second)
                    {
                        chair[k] = 0;
                        break;
                    }
                }
                j++;
            }
        }
        return n;
    }
};

int main()
{
    vector<vector<int>> v = {{3, 10}, {1, 5}, {2, 6}};
    Solution s;
    cout << s.smallestChair(v, 0) << endl;

    return 0;
}