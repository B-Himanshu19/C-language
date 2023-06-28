#include<stdio.h>
void main()
{
    int a[50],n,i,k;
    printf("\nenter the n value");
    scanf("%d",&n);
    printf("\nenter the %d elements",n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\n enter the searching element:");
    scanf("%d",&k);
    for(i=0;i<n;i++)
    if(k==a[i])
    break;
    if(i<n){
        printf("\n element found at index %d",i);
    }
        else{
        printf("\n element not found");
        return 0;
    }
}                    
