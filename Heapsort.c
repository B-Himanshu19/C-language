#include <stdio.h>
void heapify(int arr[], int n, int i) {
    int temp;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    int temp;
    for (int i = n/2 -1; i>= 0; i--)
        heapify(arr, n, i);
    for (int i = n-1; i>= 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    printf("Given array is: \n");
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
    printf("\n");
    heapSort(arr, n);
    printf("\nSorted array is: \n");
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
    return 0;
}
