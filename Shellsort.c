#include <stdio.h>
void shellsort(int arr[], int num) {
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2) {
        for (j = i; j < num; j++) {
            for (k = j - i; k >= 0; k = k - i) {
                if (arr[k + i] >= arr[k])
                    break;
                else {
                    tmp = arr[k];
                    arr[k] = arr[k + i];
                    arr[k + i] = tmp;
                }
            }
        }
    }
}
int main() {
    int num;
    printf("Enter the total number of elements: ");
    scanf("%d", &num);
    int arr[num];
    printf("Enter %d numbers: ", num);
    for (int k = 0; k < num; k++){
    scanf("%d", &arr[k]);
    }
    printf("Given array: ");
    for (int k = 0; k < num; k++)
    printf("%d ", arr[k]);
    shellsort(arr, num);
    printf("\nSorted array: ");
    for (int k = 0; k < num; k++)
    printf("%d ", arr[k]);
    printf("\n");
    return 0;
}
