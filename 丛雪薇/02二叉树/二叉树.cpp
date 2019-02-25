#include<iostream>
using namespace std;
class BT
{
public:
    char data;                    //构造未知数
    BT *lchild,*rchild;
    void creat(BT* &t)            //树的创建
    {
        char s;
        cin>>s;
        if(s=='^')                //当遇到^时，令树的根节点为NULL，从而结束该分支的递归

            t=NULL;
        else
        {
            t=new BT;
            t->data=s;
            creat(t->lchild);
            creat(t->rchild);
        }
    }
    void preorder(BT *t)         //先序遍历
    {
        if(t)
        {
            cout<<t->data<<" ";
            preorder(t->lchild);
            preorder(t->rchild);
        }
    }
    void inorder(BT *t)         //中序遍历
    {
        if(t)
        {
            inorder(t->lchild);
            cout<<t->data<<" ";
            inorder(t->rchild);
        }
    }
    void postorder(BT *t)         //后序遍历
    {
        if(t)
        {
            postorder(t->lchild);
            postorder(t->rchild);
            cout<<t->data<<" ";
        }
    }
    void Insert(BT* &t,int a)    //插入函数
    {
        if(t)
        {
            if(t->data<a)
                Insert(t->rchild,a);
            else
                Insert(t->lchild,a);
        }
        else
        {
            t=new BT;
            t->data=a;
            t->lchild=NULL;
            t->rchild=NULL;
        }
    }
};
int main()
{
    BT b;
    BT *t;
    char a;
    b.creat(t);
    cout<<"二叉树创建完成"<<endl;
    cout<<"前序遍历为："<<endl;
    b.preorder(t);
    cout<<endl;
    cout<<"中序遍历为："<<endl;
    b.inorder(t);
    cout<<endl;
    cout<<"后序遍历为："<<endl;
    b.postorder(t);
    cout<<endl;
    cout<<"输入想插入的数:";
    cin>>a;
    b.Insert(t,a);
    cout<<"插入后前序遍历为："<<endl;
    b.preorder(t);
}
