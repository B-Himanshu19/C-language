#include<stdio.h>
/* Declaring an array, first element as low, and last element as high */
void quicksort(int array[25],int low,int high){
int x, y, p, temp;
if(low<high){
    p=low;
    x=low;
    y=high;
    while(x<y){
        while(array[x]<=array[p]&&x<high)
        x++;
            while(array[y]>array[p])
            y--;
            if(x<y){
                temp=array[x];
                array[x]=array[y];
                array[y]=temp;
            }
        }
        temp=array[p];
        array[p]=array[y];
        array[y]=temp;
        quicksort(array,low,y-1);
        quicksort(array,y+1,high);
    }
}
int main(){
    int x,count,array[25];
    printf("How many elements should the array have? (Max. - 25): ");
    scanf("%d",&count);
    printf("Enter %d elements for the array: ", count);
    for(x=0;x<count;x++)
    scanf("%d",&array[x]);
    quicksort(array,0,count-1);
    printf("After implementing quicksort the sorted order is: ");
    for(x=0;x<count;x++)
    printf(" %d",array[x]);
    return 0;
}
