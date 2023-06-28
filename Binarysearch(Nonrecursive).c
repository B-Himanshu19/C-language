#include<stdio.h>
void main()
{
    int a[50],n,i,k,l,h,m;
    printf("\n enter the n value:");
    scanf("%d",&n);
    printf("\n enter the %d elements",n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\n enter the searching element:");
    scanf("%d",&k);
    l=0;
    h=n-1;
    while(l<=h)
    {
        m=(l+h)/2;
        if(k==a[m])
        break;
        else if(k<a[m])
        h=m-1;
        else
        l=m+1;
    }
    if(l<=h)
    printf("\n element found at index: %d",m);
    else
    printf("\n element not found");
    return 0;
}
