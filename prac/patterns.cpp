#include <bits/stdc++.h>
using namespace std;

int main() {
    // pattern 22 from strivers a2z sheet
    int n,i,j,top,bottom,left,right,min_dist;
    cin >> n;

    for(i=0;i<2*n-1;i++){
        for(j=0;j<2*n-1;j++){
            top = i;
            left = j;
            right = ((2*n-1) - 1) - j;  // last_idx - j
            bottom = ((2*n-1) - 1) - i;  // last_idx - i
            min_dist = min(min(top,bottom),min(left,right));
            cout << (n-min_dist) << " ";
        }
        cout << endl;
    }

    return 0;
}