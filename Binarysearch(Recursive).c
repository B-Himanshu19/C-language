int binarysearch(int a[],int l,int h,int k)
{
    int m;
    if(l>h)
    return -1;
    m=(l+h)/2;
    if(k==a[m])
    return m;
    else if(k<a[m])
    binarysearch(a,l,m-1,k);
    else
    binarysearch(a,m+1,h,k);
}
 void main()
 {
     int a[50],n,i,k;
     printf("\n enter the value:");
     scanf("%d",&n);
     printf("\n enter the %d sorted elements",n);
     for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     printf("\n enter the searching elements:");
     scanf("%d",&k);
    i=binarysearch(a,0,n-1,k);
    if(i!=-1)
    printf("\n element found at the index %d",i);
    else
    printf("\n element not found");
    return 0;
 }
