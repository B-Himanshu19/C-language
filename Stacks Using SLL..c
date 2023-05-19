#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
}*top=NULL,*nn,*temp;
void push(int x)
{
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=x;
    if(top==NULL)
{
    top=nn;
    top->link=NULL;
}
else
{
    nn->link=top;
    top=nn;
}
}
int pop(void)
{
    int ele;
    if(top==NULL)
    return (-1);
    else
    {
        ele=top->data;
        temp=top;
        top=top->link;
        temp->link=NULL;
        free(temp);
        return(ele);
    }
}
void display(void)
{
    if(top==NULL)
    printf("stack is empty");
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->link;
        }
    }
}
int search(int x)
{
    int flag;
    if(top=NULL)
    return 0;
    else
    {
        temp=top;
        flag=1;
        while(temp!=NULL)
        {
            if(temp->data=x);
            {
                flag=2;
                break;
            }
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
            case 1:printf("enetr the data to be pushed\n");
            scanf("%d",&h);
            push(h);
            break;
            case 2:h=pop();
            printf("enter the data to be popped %d\n",h);
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
