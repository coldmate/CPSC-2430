// Alen Ovalles
// lab5.cpp
// 06/3/2022
//
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// Converted int size[] = {10,100,1000,10000}; to const variables bc...
// I would keep getting a "ISO C++ forbids variable length array" using the 
// variable size[i] as the length when declaring the unsortedArray[] at compile time 
const int TEST1 = 10;
const int TEST2 = 100;
const int TEST3 = 1000;
const int TEST4 = 10000;

// Execution sort functions
void heapTime();
void mergeTime(); 
void quickTime();

// Heap sort functions
void heapSort (int arr[], int n);
void percolateUp(int arr[], int n, int i);
void swap(int arr[], int x, int y);

// Merge sort functions
void mergeSort(int arr[], int const i , const int j);
void merge(int arr[], int const left, int const mid, int const right);

// Quick sort functions
void quickSort (int arr[], int i, int j);
int partition(int arr[], int i, int j);

int main() {
    cout << endl;
    cout << "HEAP SORTED EXECUTION TIMES" << endl;
    cout << "---------------------------" << endl;
    heapTime();

    cout << "MERGE SORTED EXECUTION TIMES" << endl;
    cout << "----------------------------" << endl;
    mergeTime();
    
    cout << "QUICK SORTED EXECUTION TIMES" << endl;
    cout << "----------------------------" << endl;
    quickTime();
} 

void heapTime(){
    for(int i = 0; i < 4; i ++){
        if(i == 0){
            int unsortedArray[TEST1]; 
            cout << "The current array size is: " << TEST1 << endl;
            for(int j = 0; j < TEST1; j++){
                unsortedArray[j] = rand() % 1000000;
            }

            auto start = high_resolution_clock::now(); 
            heapSort(unsortedArray, TEST1);
            auto stop = high_resolution_clock::now(); 
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Execution time for N = " << TEST1<< ": " << duration.count() << endl << endl;
        }
        else if(i == 1){
            int unsortedArray[TEST2]; 
            cout << "The current array size is: " << TEST2 << endl;
            for(int j = 0; j < TEST2; j++){
                unsortedArray[j] = rand() % 1000000;
            }

            auto start = high_resolution_clock::now();
            heapSort(unsortedArray, TEST2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Execution time for N = " << TEST2 << ": " << duration.count() << endl << endl;
        }
        else if(i == 2){
            int unsortedArray[TEST3]; 
            cout << "The current array size is: " << TEST3 << endl;
            for(int j = 0; j < TEST3; j++){
                unsortedArray[j] = rand() % 1000000;
            }

            auto start = high_resolution_clock::now();
            heapSort(unsortedArray, TEST3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Execution time for N = " << TEST3 << ": " << duration.count() << endl << endl;
        }
        else if(i == 3){
            int unsortedArray[TEST4]; 
            cout << "The current array size is: " << TEST4 << endl;
            for(int j = 0; j < TEST4; j++){
                unsortedArray[j] = rand() % 1000000;
            }

            auto start = high_resolution_clock::now();
            heapSort(unsortedArray, TEST4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Execution time for N = " << TEST4 << ": " << duration.count() << endl << endl;
        }
    }
}

void mergeTime(){
    for(int i = 0; i < 4; i ++){
        if(i == 0){
            int unsortedArray[TEST1]; 
            cout << "The current array size is: " << TEST1 << endl;
            for(int j = 0; j < TEST1; j++){
                unsortedArray[j] = rand() % 1000000;
            }

            auto start = high_resolution_clock::now();
            mergeSort(unsortedArray, 0, TEST1);
            auto stop = high_resolution_clock::now(); 
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Execution time for N = " << TEST1<< ": " << duration.count() << endl << endl;
        }
        else if(i == 1){
            int unsortedArray[TEST2]; 
            cout << "The current array size is: " << TEST2 << endl;
            for(int j = 0; j < TEST2; j++){
                unsortedArray[j] = rand() % 1000000;
            }

            auto start = high_resolution_clock::now();
            mergeSort(unsortedArray, 0, TEST2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Execution time for N = " << TEST2 << ": " << duration.count() << endl << endl;
        }
        else if(i == 2){
            int unsortedArray[TEST3]; 
            cout << "The current array size is: " << TEST3 << endl;
            for(int j = 0; j < TEST3; j++){
                unsortedArray[j] = rand() % 1000000;
            }

            auto start = high_resolution_clock::now();
            mergeSort(unsortedArray, 0, TEST3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Execution time for N = " << TEST3 << ": " << duration.count() << endl << endl;
        }
        else if(i == 3){
            int unsortedArray[TEST4]; 
            cout << "The current array size is: " << TEST4 << endl;
            for(int j = 0; j < TEST4; j++){
                unsortedArray[j] = rand() % 1000000;
            }

            auto start = high_resolution_clock::now();
            mergeSort(unsortedArray, 0, TEST4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Execution time for N = " << TEST4 << ": " << duration.count() << endl << endl;
        }
    }
}

void quickTime(){
    for(int i = 0; i < 4; i ++){
        if(i == 0){
            int unsortedArray[TEST1]; 
            cout << "The current array size is: " << TEST1 << endl;
            for(int j = 0; j < TEST1; j++){
                unsortedArray[j] = rand() % 1000000;
            }

            auto start = high_resolution_clock::now();
            quickSort(unsortedArray, 0, TEST1);
            auto stop = high_resolution_clock::now(); 
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Execution time for N = " << TEST1<< ": " << duration.count() << endl << endl;
        }
        else if(i == 1){
            int unsortedArray[TEST2]; 
            cout << "The current array size is: " << TEST2 << endl;
            for(int j = 0; j < TEST2; j++){
                unsortedArray[j] = rand() % 1000000;
            }

            auto start = high_resolution_clock::now();
            quickSort(unsortedArray, 0, TEST2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Execution time for N = " << TEST2 << ": " << duration.count() << endl << endl;
        }
        else if(i == 2){
            int unsortedArray[TEST3]; 
            cout << "The current array size is: " << TEST3 << endl;
            for(int j = 0; j < TEST3; j++){
                unsortedArray[j] = rand() % 1000000;
            }

            auto start = high_resolution_clock::now();
            quickSort(unsortedArray, 0, TEST3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Execution time for N = " << TEST3 << ": " << duration.count() << endl << endl;
        }
        else if(i == 3){
            int unsortedArray[TEST4]; 
            cout << "The current array size is: " << TEST4 << endl;
            for(int j = 0; j < TEST4; j++){
                unsortedArray[j] = rand() % 1000000;
            }

            auto start = high_resolution_clock::now();
            quickSort(unsortedArray, 0, TEST4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Execution time for N = " << TEST4 << ": " << duration.count() << endl << endl;
        }
    }
}

void heapSort(int arr[], int n){
    int size = n / 2 - 1;

    for(int i = size; i >= 0; i--){
        percolateUp(arr, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        swap(arr, 0, i);
        percolateUp(arr, i, 0);
    }
}

void percolateUp(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr, i, largest);
        percolateUp(arr, n, largest);
    }
}

void swap(int arr[], int x, int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void mergeSort(int arr[], int const i , int const j){
    if(i >= j){
        return;
    }
    int mid = i + (j - i) / 2;  
    mergeSort(arr, i, mid);       
    mergeSort(arr, mid + 1, j);    
    merge(arr, i, mid, j);        
}

void merge(int arr[], int const left, int const mid, int const right){
    int const S1 = mid - left + 1;
    int const S2 = right - mid;
    int *leftA = new int[S1];
    int *rightA = new int[S2];

    for(int i = 0; i < S1; i++){
        leftA[i] = arr[left + i];
    }
    for(int j = 0; j < S2; j++){
        rightA[j] = arr[mid + 1 + j];
    }
  
    int tempS1 = 0;
    int tempS2 = 0;
    int tempArr = left;
  
    while(tempS1 < S1 && tempS2 < S2){
        if(leftA[tempS1] <= rightA[tempS2]){
            arr[tempArr] = leftA[tempS1];
            tempS1++;
        }
        else{
            arr[tempArr] = rightA[tempS2];
            tempS2++;
        }
        tempArr++;
    }
    while(tempS1 < S1){
        arr[tempArr] = leftA[tempS1];
        tempS1++;
        tempArr++;
    }
    while(tempS2 < S2){
        arr[tempArr] = rightA[tempS2];
        tempS2++;
        tempArr++;
    }
}
 
void quickSort(int arr[], int i, int j) {
    if(i >= j){
        return;
    }
    int pivotIndex = partition(arr, i, j);
    quickSort(arr, i, pivotIndex-1);
    quickSort(arr, pivotIndex+1, j);
}

int partition(int arr[], int start, int end){
    int p = arr[start];
    int m = 0;

    for(int i = start + 1; i <= end; i++){
        if (arr[i] <= p)
            m++;
    }
 
    int pivotIndex = start + m;
    swap(arr[start], arr[pivotIndex]);
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex){
        while(arr[i] <= p){
            i++;
        }
        while(arr[j] > p){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}