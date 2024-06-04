/*
OJ: https://leetcode.com/problems/lru-cache/description/
Time: 
Space: 
*/
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    struct item {
        int val;
        list<int>::iterator it;
    };

    list<int> time;
    unordered_map<int, item> cache;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            time.erase(cache[key].it);
            time.push_front(key);
            cache[key].it = time.begin();
            return cache[key].val;
        }
        // if not found
        return -1;
    }
    
    void put(int key, int value) {
        // if key is present
        if(cache.find(key) != cache.end()){
            time.erase(cache[key].it);
        }
        else{
            // del from tail
            if(cache.size() == size){
                cache.erase(time.back());
                time.pop_back();
            }
        }
        time.push_front(key);
        cache[key] = { value, time.begin() };
    }
};

int main() {
    LRUCache* obj = new LRUCache(2);
    string ins[100] = {"LRUCache","put","put","get","put","get","put","get","get","get"};
    vector<vector<int>> v = {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}};

    // for(int i=0;i<ins->length(); i++){
    //     if(ins[i] == "put"){
    //         obj->put(v[i][0], v[i][1]);
    //         cout << ins[i]  << endl;
    //     }
    //     if(ins[i] == "get"){
    //         obj->get(v[i][0]);
    //         cout << ins[i]  << endl;
    //     }
    // }

    list<int> dll;
    dll.push_back(1);
    cout << dll.front() << endl;
    // int param_1 = obj->get(key);
    return 0;
}