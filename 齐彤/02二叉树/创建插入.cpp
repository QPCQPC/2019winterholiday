#include<iostream>
using namespace std;

class Tree
{
public:
    int num=0;
    Tree *lchild=NULL;
    Tree *rchild=NULL;
};
void ct(Tree *T)
{
    int c;
    cin>>c;
    if(c==0)
    {
        T=NULL;
    }
    else
    {
        Tree *s1=new Tree;
        Tree *s2=new Tree;
        T->lchild=s1;
        T->rchild=s2;
        T->num=c;
        ct(T->lchild);
        ct(T->rchild);
    }
}
void tu(Tree *t)
{
    if(t!=NULL)
    {
        cout<<t->num<<' ';
        tu(t->lchild);
        tu(t->rchild);
    }
}
void too(Tree* &t,Tree *p)
{
    if(t==NULL)
        t=p;
    else if(p->num<t->num)
        too(t->lchild,p);
    else
        too(t->rchild,p);
}
int main()
{
    int a,b;
    Tree *T=new Tree;
    cin>>a;
    if(a==1)
    {
        cout<<"put you want tree,0 is kongjiedian"<<endl;
        ct(T);
        char d;
        d=T->lchild->num;
        cout<<d<<endl;
        tu(T);
    }
    cin>>b;
    if(b==2)
    {
        cout<<"put you want charu"<<endl;
        int c;
        cin>>c;
        Tree *s=new Tree;
        s->num=c;
        too(T,s);
        tu(T);
    }
    return 0;
}
