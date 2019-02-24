#include<iostream>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
using namespace std;

 typedef struct BiTNode
 {
     char data;
     struct BiTNode *lchild, *rchild;
 } BiTNode , *BiTree;

 bool CreateBiTree(BiTree &T)
 {

     char ch;
     cout<<"输入字符"<<endl;
     cin>>ch;
     if(ch == '0') T=NULL;
     else
     {
         if(!(T=(BiTNode*) malloc (sizeof(BiTNode))))  return false;
         T->data=ch;
         CreateBiTree(T->lchild);
         CreateBiTree(T->rchild);
     }
     return true;
 }

 typedef struct
 {
     BiTree *base;
     BiTree *top;
     int stacksize;
 }SqStack;

 bool InitStack(SqStack s)
 {
     s.base=(BiTree *) malloc(STACK_INIT_SIZE * sizeof(BiTree));
     if(!s.base)return false;
     s.top = s.base;
     s.stacksize = STACK_INIT_SIZE;
     return true;
 }

 bool Pop(SqStack&s,BiTree&e)
 {
     if(s.top == s.base) return false;
     e = * --s.top;
     return true;
 }

 bool StackEmpty(SqStack s)
 {
     if(s.base == s.top)return true;
     else
     {
         return false;
     }
 }

 bool visit(BiTree e)
 {
     cout<<e->data;
     return true;
 }

 SqStack s;


 bool PreOrderTraverse(BiTree T,bool(*visit)(BiTree e))
 {
     cout<<"先序遍历结果如下:"<<endl;
     InitStack(s);
     BiTree p; p=T;
     while(p|| !StackEmpty(s))
     {
         if(p)
         {
             Push(s,p) ; p = p->lchild;
         }
         else
         {
             Pop(s,p);
             cout<<p->data;
             p=p->rchild;
         }
     }
     return true;
 }

 bool InOrderTracerse(BiTree T,bool(*visit)(BiTree e))
 {
     if(T)
     {
         if((*visit)(T))
            if(InOrderTracerse(T->lchild,visit))
               if(InOrderTracerse(T->lchild,visit)) return true;
         return false;
     }
     else return true;
 }

 bool PosOrderTracerse(BiTree T,bool(*visit)(BiTree e))
 {
     if(T)
     {
         if(PosOrderTracerse(T->lchild , visit))
            if(PosOrderTracerse(T->lchild , visit))
              if((*visit)(T)) return true;
         return false;
     }
     else return true;
 }

 int main()
 {
     bool (*visit_point) (BiTree e);
     visit_point=visit;
     BiTree T;
     CreateBiTree(T);
     cout<<"二叉树构造完成！"<<endl<<endl<<endl;
     PreOrderTraverse(T,visit_point);
     cout<<endl;
     cout<<"中序遍历结果如下："<<endl;
     InOrderTracerse(T,visit_point);
     cout<<endl;
     cout<<"后序遍历结果如下："<<endl;
     PosOrderTracerse(T,visit_point);
     return true;
 }
