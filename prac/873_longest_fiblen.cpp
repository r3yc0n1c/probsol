/*
OJ: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
Time: O(n2 log M)
Space: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // unordered_set<int> f(int n){
    //     if(n==1) return {1};
    //     if(n==2) return {1, 1};
    //     unordered_set<int> fibs;
    //     int a = 1, b = 1;
    //     fibs.insert(a);
    //     while(1){
    //         int c = a+b;
    //         if(c>n) break;
    //         fibs.insert(c);
    //         a = b; b = c;
    //     }
    //     return fibs;
    // }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2) return 0;
        unordered_set<int> s(arr.begin(), arr.end());
        int maxLen = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int lc=2, a = arr[i], b=arr[j];
                while(s.count(a+b)){
                    int c = a+b;
                    a=b;
                    b=c;
                    lc++;
                }
                maxLen = max(lc, maxLen);
            }
        }
        return (maxLen>2)?maxLen:0;
    }
};

int main() {
    Solution sol;
    vector<int> v = { 1,3,5 };
    cout << sol.lenLongestFibSubseq(v) << endl;
    // for(auto x: sol.f(100))
    //     cout << x << endl;
    return 0;
}