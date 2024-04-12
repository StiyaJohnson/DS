#include <stdio.h>
 
// Function to swap the position of two elements
 
void swap(int* a, int* b)
{
 
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// To heapify a subtree rooted with node i
// which is an index in arr[].
// N is size of heap
void heapify(int arr[], int N, int i)
{
    // Find largest among root,
    // left child and right child
 
    // Initialize largest as root
    int largest = i;
 
    
    int left = 2 * i ;
 
    
    int right = 2 * i + 1;
 
    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
 
        largest = left;
 
    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])
 
        largest = right;
 
    // Swap and continue heapifying
    // if root is not largest
    // If largest is not root
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int arr[], int N)
{
 
    // Build max heap
    for (int i = N / 2 ; i >= 1; i--)
 
        heapify(arr, N, i);
 
    // Heap sort
    for (int i = N ; i >= 1; i--) {
 
        swap(&arr[1], &arr[i]);
 
        // Heapify root element
        // to get highest element at
        // root again
        heapify(arr, i, 1);
    }
}
 

void printArray(int arr[], int N)
{
    for (int i = 1; i <= N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 

int main()
{

    int i,N,arr[100];
    printf("Enter the no of elements in the array : ");
    scanf("%d",&N);
    printf("Enter the elements : \n");
    for(i=1;i<=N;i++) 
    {
        scanf("%d",&arr[i]);
    }
 
    // Function call
    heapSort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);
}
 
