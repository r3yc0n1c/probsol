#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> cand(n, 1);

        for(int i = 1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                cand[i] = cand[i-1] + 1;
            }
        }
        for(int i = n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                cand[i] = max(cand[i], cand[i+1] + 1);
            }
        }

        return accumulate(cand.begin(), cand.end(), 0);
    }
};

int main() {
    vector<int> v = {1,3,2,2,1};
    Solution s;
    cout << s.candy(v) << endl;
    return 0;
}