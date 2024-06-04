#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &p1, vector<int> p2)
    {
        return p1[1] < p2[1];
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), cmp);
        int c = 1, end = pairs[0][1], n = pairs.size();

        if (n < 2)
            return n;

        for (int i = 1; i < n; i++)
        {
            if (pairs[i][0] > end)
            {
                c++;
                end = pairs[i][1];
            }
        }
        return c;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 2}, {2, 3}, {3, 4}};
    Solution s;
    cout << s.findLongestChain(v) << endl;
    return 0;
}