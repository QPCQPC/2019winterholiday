#include<iostream>
using namespace std;
class alter
{
public:
    string text;
    alter *next;
    void add(string t,alter *p)
    {
        while(p->next)
        {
            p=p->next;
        }
        alter *s=new alter;
        s->next=p->next;
        p->next=s;
        s->text=t;
        cout<<"添加成功"<<endl;
    }
    void del(alter *p,string t)
    {
        alter *n,*m=p;
        while(m->next)
        {
            if(m->text==t)
            {
                n=m;
                break;
            }
            else
                m=m->next;
        }
        m=p;
        while(m->next!=n)
        {
            m=m->next;
        }
        m->next=m->next->next;
        cout<<"删除成功"<<endl;
    }
    void alt(alter *p,string t,string a)
    {
        alter *m=p;
        while(m->next)
        {
            if(m->text==t)
                break;
            else
                m=m->next;
        }
        m->text=a;
        cout<<"修改成功"<<endl;
    }
};
int main()
{
    alter l;
    alter *p,*h=new alter;
    h->text="NULL";
    int a;
    cout<<"显示所有请输0，添加请输1，删除请输2.修改请输3"<<endl;
    while(cin>>a)
    {
        string t,s;
        switch(a)
        {
            case 0:
                {
                    p=h;
                    while(p)
                    {
                        cout<<p->text<<endl;
                        p=p->next;
                    }
                    break;
                }
            case 1:
                {
                    cin>>t;
                    l.add(t,h);
                    break;
                }
            case 2:
                {
                    cin>>t;
                    l.del(h,t);
                    break;
                }
            case 3:
                {
                    cout<<"请输修改前的内容"<<endl;
                    cin>>t;
                    cout<<"请输修改后的内容"<<endl;
                    cin>>s;
                    l.alt(h,t,s);
                    break;
                }
            default :
                cout<<"输入有误"<<endl;
        }
        cout<<"显示所有请输0，添加请输1，删除请输2.修改请输3"<<endl;
    }

}
