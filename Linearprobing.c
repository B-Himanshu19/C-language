#include<stdio.h>
int D,a[30],b[30],i,j,r;
int linear_prob(int k)
{
    r=(k+j)%D;
    if(b[r]==0||j>D)
    return r;
    else{
        j++;
        linear_prob(k);
    }
}
void hash()
{
    int k;
    for(i=0;i<D;i++)
    {
        j=0;
        k=a[i]%D;
        if(!b[k])
        b[k]=a[i];
        else
        b[linear_prob(k)]=a[i];
    }
}
int main()
{
    printf("enter D");
    scanf("%d",&D);
    printf("enter numbers ");
    for(i=0;i<D;i++)
    scanf("%d",&a[i]);
    hash();
    for(i=0;i<D;i++)
    printf("%d ",b[i]);
}
