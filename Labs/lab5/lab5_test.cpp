//
//  main.cpp
//  lab5 (SQ)
//
//  Created by Jashit Dahiya on 5/27/22.
//

#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

//void swap(int x, int y){
//    int temp = x;
//    x = y;
//    y = temp;
//}

int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subA1 = mid - left + 1;
    auto const subA2 = right - mid;
    auto *leftA = new int[subA1],
         *rightA = new int[subA2];

    for (auto i = 0; i < subA1; i++)
        leftA[i] = array[left + i];
    for (auto j = 0; j < subA2; j++)
        rightA[j] = array[mid + 1 + j];
  
    auto iSubA1 = 0,
        iSubA2 = 0;
    int iMergedA = left;
  
    while (iSubA1 < subA1 && iSubA2 < subA2) {
        if (leftA[iSubA1] <= rightA[iSubA2]) {
            array[iMergedA] = leftA[iSubA1];
            iSubA1++;
        }
        else {
            array[iMergedA] = rightA[iSubA2];
            iSubA2++;
        }
        iMergedA++;
    }
    while (iSubA1 < subA1) {
        array[iMergedA] = leftA[iSubA1];
        iSubA1++;
        iMergedA++;
    }
    while (iSubA2 < subA2) {
        array[iMergedA] = rightA[iSubA2];
        iSubA2++;
        iMergedA++;
    }
}

void heapSort(int arr[], int n)
{
   
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
 
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;

    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main()
{
    int size[] = {10,100,1000,10000};
    for(int i = 0; i < 4; i ++){
        int unsortedArray[size[i]];
        cout << "The current array size is: " << size[i] << endl;
        for(int j=0; j<size[i]; j++){
            unsortedArray[j] = rand() % 1000000;
        }
        
        auto start = high_resolution_clock::now();
        heapSort(unsortedArray, size[i]);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "Time taken by the heapSort algorithm: " << duration.count() << endl;

    }
    cout << endl;
    
    for(int i = 0; i < 4; i ++){
        int unsortedArray2[size[i]];
        cout << "The current array size is: " << size[i] << endl;
        for(int j=0; j<size[i]; j++){
            unsortedArray2[j] = rand() % 1000000;
        }
        
        auto start = high_resolution_clock::now();
        mergeSort(unsortedArray2,0, size[i]);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "Time taken by the mergeSort algorithm: " << duration.count() << endl;

    }
    cout << endl;
    
    for(int i = 0; i < 4; i ++){
        int unsortedArray3[size[i]];
        cout << "The current array size is: " << size[i] << endl;
        for(int j=0; j<size[i]; j++){
            unsortedArray3[j] = rand() % 1000000;
        }
        auto start = high_resolution_clock::now();
        quickSort(unsortedArray3,0, size[i]);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "Time taken by the quickSort algorithm: " << duration.count() << endl;

    }
    cout << endl;
}
