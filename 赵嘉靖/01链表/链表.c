#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node *next;
};

int main()
{
    struct node *head;  //链表开始位置
    head=NULL;
    struct node *p1,*p2;
    int i=1;
    p1=p2=(struct node*)malloc(sizeof(struct node));
    printf("请输入值，值小于等于0结束,存放地址为:p1_ADDR= %d\n",p1);
    scanf("%d",&p1->num);
    p1->no=i;
    p1->next=NULL;
    while(p1->num>0)
    {
        if(head==NULL)
            head=p1;
        else
            p2->next=p1;
        p2=p1;

        p1=(struct node*)malloc(sizeof(struct node));
        i=i+1;
        printf("请输入值，值小于等于0结束，存放地址为:p%d_ADDR= %d\n",i,p2);
        scanf("%d",&p1->num);
        p1->no=i;
    }
    free(p1);
    p1=NULL;
    p2->next=NULL;
    printf("链表输入结束(END)\n");
    getchar();
    return 0;
}
