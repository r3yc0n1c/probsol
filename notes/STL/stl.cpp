#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

void pair_demo() {
    pair<int, int> p(1, 2);
    cout << p.first << ", " << p.second << endl;

    pair<int, pair<int, int>> q = {3, {4, 5}};
    cout << q.first << ", (" << q.second.first << ", " << q.second.second << ")\n";

    pair<int, int> arr[] = {{6, 7}, {8, 9}};
    
    for(auto x: arr)
        cout << x.first << ", " << x.second << endl;

}

void prints(auto v){
    for(auto x: v)
        cout << x << " ";
    cout << endl;
}

void vector_demo(){
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2); // optimized

    prints(v);
   
    vector<pair<int, int>> pv;
   
    pv.push_back({3, 4});
    pv.emplace_back(5, 6);

    for(auto x: pv)
        cout << x.first << ", " << x.second << endl;

    
    vector<int> v1(5);
    
    prints(v1);

    vector<int> v2(5, 20);
    vector<int> v3(v2);

    vector<int>::iterator it = v3.begin();
    it++;
    
    cout << *(it) << endl;
    
    it = it + 2;

    cout << *(it) << "\n-----------\n";

    v3 = {1, 2, 3, 4, 5};
    vector<int>::iterator it1 = v3.end();

    for(; it1 > v3.begin(); it1--){
        cout << *(it1) << endl;
    }

    cout << "\n-----\n";

    vector<int>::reverse_iterator it2 = v3.rbegin();
    
    for(; it2 != v3.rend(); it2++){
        cout << *(it2) << endl;
    }

    cout << "\n-----\n";

    vector<int>::reverse_iterator it3 = v3.rend();
    
    for(; it3 != v3.rbegin(); it3--){
        cout << *(it3) << endl;
    }

    cout << "\n-----\n";

    cout << v3[0] << " " << v3.at(1) << " " << v3.back() << endl;

    cout << "\n-----\n";
   
    // Delete simgle
    v3.erase(v3.begin()+1);
    prints(v3);

    cout << "\n-----\n";

    // Delete Multiple
    v3 = {1, 2, 3, 4, 5};
    v3.erase(v3.begin()+1, v3.begin()+3);
    prints(v3);

    // Insert
    vector<int> v4 (2, 100);
    v4.insert(v4.begin()+1, 200);
    prints(v4);
    v4.insert(v4.begin()+1, 2, 50);
    prints(v4);

    vector<int> temp(2, 300);
    v4.insert(v4.begin(), temp.begin(), temp.end());
    prints(v4);


    // Size
    cout << "v4.size() = " << v4.size() << endl;

    v4.pop_back();
    cout << "v4.pop_back() = " << v4.back() << endl;

    // Swap
    prints(v2);
    v4.swap(v2);

    prints(v2);
    prints(v4);

    v4.clear();

    cout << v4.empty() << endl;
}

void list_demo(){
    list<int> ls;

    ls.push_back(10);
    ls.emplace_back(20);

    ls.push_front(5);
    ls.emplace_front(2);

    // rest func same as vector
    prints(ls);
}

void dq_demo(){
    deque<int> dq;
    
    dq.push_back(10);
    dq.emplace_back(20);
    
    dq.push_front(8);
    dq.emplace_front(5);

    prints(dq);

    dq.pop_back();
    prints(dq);

    dq.pop_front();
    prints(dq);

    cout << "back = " << dq.back() << " front = " << dq.front() << endl;
}

void stack_demo(){
    /*
     * all: O(1)
     * */
    stack<int> stk;
    
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.emplace(40);

    int n = stk.size();
    while(n--){
        cout << stk.top() << " ";
        stk.pop();
    }cout << endl;

    cout << stk.empty() << endl;

    stack<int> stk1, stk2;
    stk1.swap(stk2);
}

void queue_demo(){
    /*
     * all: O(1)
     * */
    queue<int> q;

    q.push(1);  // O(1)
    q.push(2);
    q.push(3);
    q.emplace(4);

    q.back() += 5;

    cout << q.back() << endl;
    cout << q.front() << endl;
    
    int n = q.size();
    while(n--){
        cout << q.front() << " ";
        q.pop();
    }cout << endl;
}

void pq_demo(){
    // Max heap
    priority_queue<int> pq;

    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    cout << pq.top() << endl;   // O(1)
    pq.pop();   // O(log n)
    cout << pq.top() << endl;

    int n = pq.size();  // O(1)
    while(n--){
        cout << pq.top() << " ";
        pq.pop();
    }cout << endl;

    // Min heap
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(5);
    pq1.push(2);
    pq1.push(8);
    pq1.emplace(10);
    
    n = pq1.size();
    while(n--){
        cout << pq1.top() << " ";
        pq1.pop();
    }cout << endl;
}

void set_demo(){
    set<int> s;
    s.insert(10);   // O(log n)
    s.emplace(20);
    s.insert(20);
    s.insert(40);
    s.insert(30);
    s.insert(3);
    s.insert(50);

    prints(s);

    auto it = s.find(30);   // O(log n)
    cout << *(it) << endl;

    it = s.find(60);
    cout << *(it) << endl;

    s.erase(30);    // O(1)
    prints(s);

    int c = s.count(20);
    cout << c << endl;

    auto it1 = s.find(20);
    auto it2 = s.find(40);
    s.erase(it1, it2);
    prints(s);

    it = s.lower_bound(2);
    cout << *(it) << endl;
    it = s.upper_bound(3);
    cout << *(it) << endl;
}

void multiset_demo(){
    multiset<int> ms;
    ms.insert(10);
    ms.emplace(20);
    ms.insert(20);
    ms.insert(40);
    ms.insert(30);
    ms.insert(3);
    ms.insert(40);
    ms.insert(50);

    prints(ms);

    auto it = ms.find(30);
    cout << *(it) << endl;

    it = ms.find(60);
    cout << "found idx for 60: " << *(it) << endl;

    ms.erase(20);
    prints(ms);

    int c = ms.count(30);
    cout << c << endl;

    ms.erase(ms.find(40));
    prints(ms);

    ms.erase(ms.find(3), ms.find(3+2));
    prints(ms);
}

void unorderd_set_demo(){
    /*
     * best: O(1)
     * worst: O(n)
     * */
    unordered_set<int> us;

    us.insert(5);
    us.insert(1);
    us.insert(4);
    us.insert(1);
    us.insert(3);

    prints(us);
}

void map_demo(){
    map<int, int> m;
    map<pair<int, int>, int> m1;
    map<int, pair<int, int>> m2;

    m[1] = 2;
    m.emplace(3, 1);
    m.insert({2, 4});
    
    m1[{2,3}] = 10;
    cout << m1[{2,3}] << endl;

    for(auto x: m)
        cout << x.first << " " << x.second << endl;

    auto x = m.find(3);
    cout << x->second << endl;

    x = m.find(5);
    cout << x->first << endl;

}

int main(void) { 
    // pair_demo(); 
    // vector_demo();
    // list_demo();
    // dq_demo();
    // stack_demo();
    // queue_demo();
    /* pq_demo(); */
    /* set_demo(); */
    /* multiset_demo();  */
    /* unorderd_set_demo(); */
    map_demo();
}
