/*
TC: O(n/2)
SC: O(n/2)
*/
#include <bits/stdc++.h>
using namespace std;

void rev(string &s, int i, int n){
    if(i >= n/2) return;
    swap(s[i], s[n-i-1]);
    rev(s, i+1, n);
}

bool isPalin(string &s, int i, int n){
    if(i >= n/2) return true;
    if(s[i] != s[n-i-1]) return false;
    return isPalin(s, i+1, n);
}

int main(){
    string s = "madam";

    // rev(s, 0, s.size());

    // cout << s;

    cout << isPalin(s, 0, s.size());
}