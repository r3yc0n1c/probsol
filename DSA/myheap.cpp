#include <iostream>
using namespace std;

#define MAX 100

class Heap {
    public:
        int arr[MAX];
        int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int x){
        size++;
        int index = size;
        arr[index] = x;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void del(){
        if(size == 0){
            cout << "No element to delete" << endl;
            return;            
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }


    void print(){
        for(int i=1; i<=size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 
}

int main(){

    Heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.del();
    h.print();
    
    return 0;
}

