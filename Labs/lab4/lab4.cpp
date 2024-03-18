// Alen Ovalles
// lab4.cpp
// 05/20/2022
/* 
** Min-Heap construction and basic operations 
** Lab 4, CPSC 2430, Xin Zhao
*/
// define the max size for the heap array 

#include <iostream>
using namespace std;

const int HEAP_MAX_SIZE = 1000;

class MinHeap {
private:
    int heapArr[HEAP_MAX_SIZE];
    int size;

    void swap(int x, int y) {
        int temp = heapArr[x];
        heapArr[x] = heapArr[y];
        heapArr[y] = temp;
    }
    void percolateUp(int index) {
        int parent = (index-1)/2;
        
        if(index == 0 || heapArr[index] > heapArr[parent]){
            return;
        }
        else{
            swap(index, parent);
            percolateUp(parent);
        }
    }
    void percolateDown(int index) { 
        int left = 2*index + 1;
        int right = 2*index + 2;

        if(index == size || (heapArr[index] < heapArr[left] && heapArr[index] < heapArr[right])){
            return;
        }
        else if(heapArr[left] < heapArr[right] && heapArr[left] < heapArr[index]){
            swap(index, left);
            percolateDown(left);
        }
        else if(heapArr[left] < heapArr[right] && heapArr[right] < heapArr[index]){
            swap(index, right);
            percolateDown(right);
        }
    }
public:
    MinHeap() { 
        size = -1; 
    }
    void insert(int element) {
        size++;
        heapArr[size] = element;
        percolateUp(size);
    }
    void deleteMin() {
        swap(0, size);
        size--;
        percolateDown(0);
    }
    int extractMin() {
         return heapArr[0];
    }
    int heapSize() {
        return size+1;
    }
    void heapDisplay() {
        cout << "The heap is: ";
        for(int i = 0; i <= size; i++){
            cout << heapArr[i] << " ";
        }
        cout << endl;
    }
};

// in your main function, test your implementations. For example,  
int main() {
    MinHeap mh;
    mh.insert(4);
    mh.insert(8);
    mh.insert(1);
    mh.insert(7);
    mh.insert(3);

    cout << endl;

    // display heap
    mh.heapDisplay();  // the output should be: 1, 3, 4, 8, 7

    // deleteMin
    mh.deleteMin();
    mh.heapDisplay();  // the output should be: 3, 7, 4, 8

    // extractMin
    cout << "The smallest element is: " << mh.extractMin() << endl;   // the output should be: 3

    // heapSize
    cout << "The heap size is: " << mh.heapSize() << endl;   // the output should be: 4
    
    cout << endl;
    return 0;
}