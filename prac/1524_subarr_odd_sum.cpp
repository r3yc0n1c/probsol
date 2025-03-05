#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numOfSubarrays(vector<int>& arr) {
    int m = (int)1e9 + 7;
    int c = 0, ps = 0, o=0, e=1;

    for (int x: arr) {
      ps += x;
      if(ps & 1){
        o++;
        c+=(e%m);
      }else{
        e++;
        c+=(o%m);
      }
    }
    return c;
  }
};

int main() {
  Solution s;
  vector<int> v = { 1, 3, 5 };
  cout << s.numOfSubarrays(v);
}
