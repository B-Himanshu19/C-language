#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
}*f=NULL,*r=NULL,*nn,*temp;
void insert(int x)
{
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=x;
    if(f==NULL&&r==NULL)
    {
        f=nn;
        r=nn;
        nn->link=NULL;
    }
else
{
    r->link=nn;
    r=nn;
    r->link=NULL;
}
}
int Delete(void)
{
    int ele;
    if(f==NULL&&r==NULL)
        return(-1);
        else
        {
            temp=f;
            ele=f->data;
            f=f->link;
            temp->link=NULL;
            free(temp);
            return(ele);
        }
}
void display(void)
{
    if(f==NULL&&r==NULL)
    printf("queue is empty");
    else
    {
        temp=f;
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->link;
        }
    }
}
int search(int x)
{
    int flag=0;
    if(f==NULL&&r==NULL)
    return 0;
    else
    {
        temp=f;
        flag=1;
        while(temp!=NULL)
        {
            if(temp->data==x)
            flag=2;
            temp=temp->link;
        }
        return flag;
    }
}
int main()
{
    int choice,h,f;
    char ch;
    do
    {
        printf("1.push 2.pop 3.display 4.search\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enetr the data to be inserted\n");
            scanf("%d",&h);
            insert(h);
            break;
            case 2:h=Delete();
            printf("enter the data deleted %d\n",h);
            break;
            case 3:display();
            break;
            case 4:printf("enter the element to be searched");
            scanf("%d",&h);
            f=search(h);
            if(f==0)
            printf("stack is empty\n");
            else if(f==1)
            printf("element bot found\n");
            else
            printf("element is found\n");
            break;
            default:printf("wrong choice\n");
        }
        printf("continue on main y/n");
        //scanf("%c",&ch);
        fflush(stdin);
        ch=getchar();
    } while(ch=='y');
    fflush(stdin);
    return 0;
}
