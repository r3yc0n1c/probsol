#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int m = g.size(), n = g.size(), i = 0, c = 0;
        
        while(c<m && i<n){
            if(s[i]>=g[c]) c++;
            i++;
        } return c;
    }
};

int main() {
    vector<int> g = {1,2}, s1 = {1,2,3};
    Solution s;
    cout << s.findContentChildren(g, s1) << endl;
    return 0;
}