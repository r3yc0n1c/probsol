#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> p, star;
        int n = s.length();

        for(int i = 0; i<n;i++){
            if(s[i] == '(')
                p.push(i);
            else if ( s[i] == '*')
                star.push(i);
            else{
                if(!p.empty())
                    p.pop();
                else if (!star.empty())
                    star.pop();
                else{
                    return false;
                }
            }
        }

        while (!p.empty() && !star.empty() && star.top() > p.top())
        {
            p.pop();
            star.pop();
        }
        return p.empty();
    }
};

int main()
{
    string s1 = "()";
    Solution s;
    cout << s.checkValidString(s1);
    return 0;
}