#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root;
    int left = (2 * root) + 1;
    int right = (2 * root) + 2 ;

    while (left< n && arr[left] > arr[largest]){
        largest = left;
    }

    while (right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if (largest != root){
        swap(arr[largest] , arr[root]);
        heapify(arr , n , largest);
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 1; i--){
        heapify(arr, n, i);
    }

    // extracting elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call the heapify function on the reduced heap
        heapify(arr, i, 0);
    }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    int arr_length =10 ;
    int heap_arr[arr_length] ;

   for(int i=0;i<arr_length;i++){
    heap_arr[i]=rand()%50;
   }

   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}