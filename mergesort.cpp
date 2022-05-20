// Merge sort program in C++
#include <iostream>
using namespace std;

// Merge the two subarrays L and M into the array

void merge(int array[], int c, int d, int o) {

  // Create L ← A[c..d] and M ← A[d+1..o]
  int n1 = d - c + 1;
  int n2 = o - d;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = array[c + i];
  for (int j = 0; j < n2; j++)
    M[j] = array[d + 1 + j];

  // Maintain current index of sub-arrays and main array

  int i, j, k;
  i = 0;
  j = 0;
  k = c;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[c..o]

while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[c..o]

  while (i < n1) {
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    array[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them

void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // n is the point where the array is divided into two subarrays

    int n = l + (r - l) / 2;

    mergeSort(arr, l, n);
    mergeSort(arr, n + 1, r);

    // Merge the sorted subarrays

    merge(arr, l, n, r);
  }
}

// Print the array

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Driver program
int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}
