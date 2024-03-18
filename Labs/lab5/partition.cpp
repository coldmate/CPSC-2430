#include <iostream>
using namespace std;

void swap(int a[], int x, int y){
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

int partition(int a[], int i, int j) {
    // partition data items in a[i..j]
    int p = i; // p is the pivot, the ith item
    int m = 0; // initially S1 and S2 are empty
    for(int k = i+1; k <= j; k++){ //process unknown region
        if (a[k] <= a[p]) {  // case 2: put a[k] to S1
            m++;
            swap(a, k, m);
        }
    }   
    p = m;
    swap(a, p, i);
    // put the pivot at the right place
    return p;    // return the pivot’s final position
}

int main(){
    int arr[] = {6, 2, 3, 5, 4, 10, 7};
    int size = 6;
    cout << partition(arr, 0, size) << endl;

    for(int i = 0; i <= size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}