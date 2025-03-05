/*
OJ: link
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int t = n1+n2, l = (t+1)/2, low = 0, high = n1;
        while(low <= high){
            int m1 = (low + high) >> 1;
            int m2 = l - m1;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            if (m1 < n1)
                r1 = nums1[m1];
            if (m2 < n2)
                r2 = nums2[m2];
            if (m1 - 1 >= 0)
                l1 = nums1[m1 - 1];
            if (m2 - 1 >= 0)
                l2 = nums2[m2 - 1];
            
            if (l1 <= r2 && l2 <= r1) {
                if (t % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) {
                high = m1 - 1;
            }
            else {
                low = m1 + 1;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = { 1, 3 }, v2 = {2};
    cout << sol.findMedianSortedArrays(v1, v2) << endl;
    return 0;
}