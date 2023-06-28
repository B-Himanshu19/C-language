#include<stdio.h>
int linearsearch(int a[],int l,int h,int k)
{
    if(l>h)
    return -1;
    if(k==a[l])
    return l;
    linearsearch(a,l+1,h,k);
}
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
    i=linearsearch(a,0,n-1,k);
    if(i!=-1)
    printf("\n Element found at index %d",i);
    else
    printf("\n Element not found");
    return 0;
}
