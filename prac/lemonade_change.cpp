#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int bill: bills){
            if(bill == 5) five++;
            else if(bill == 10){
                if(five == 0) return false;
                five--;
                ten++;
            }
            else{
                if((five < 3) && (ten == 0 || five == 0))
                    return false;
                
                if(ten>0){
                    ten--;
                    five--;
                }
                else
                    five -= 3;
            }
        }
        return true;
    }
};

int main() {
    vector<int> bills = {5,5,10,10,20};
    Solution s;
    cout << s.lemonadeChange(bills) << endl;
    return 0;
}