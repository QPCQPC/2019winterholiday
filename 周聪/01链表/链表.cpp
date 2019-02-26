#include<iostream>
#include<string>
using namespace std;

class LB {
public:
	long long number;
	string name;
	string sex;
	LB *next;
};

int Creat_LB(LB *H, int n) {
	int i;
	LB *p = H;
	for (i = 1; i <= n; i++) {
		LB *s = new LB;
		cout << "请输入第" << i << "人的信息 :" << endl;
		cout << "姓名 : ";
		cin >> s->name ;
		cout << "电话号 : ";
		cin >> s->number;
		cout << "性别 :";
		cin >> s->sex;
		s->next = NULL;
		p->next = s;
		p = p->next;
	}
	return i;
}

void show_1(LB *H, string name) {
	LB *p = H;
	while (p) {
		if (name == p->name) {
			cout << p->name << " 的电话号是 : " << p->number << endl;
			break;
		}
		else
			p = p->next;
		if (p == NULL) {
			cout << "无相关信息" << endl;
			break;
		}
	}
}

void show_2(LB *H, string name) {
	LB *p = H;
	while (p) {
		if (name == p->name) {
			cout << p->name  << " " << p->sex << " 的电话号是 : " << p->number << endl;
			break;
		}
		else
			p = p->next;
		if (p == NULL) {
			cout << "无相关信息" << endl;
			break;
		}
	}
}

void show_3(LB *H) {
	LB *p = H->next;
	while (p) {
		cout << p->name << " " << p->sex << " 的电话号是 : " << p->number << endl;
		p = p->next;
	}
}

void add(LB *H, int i) {
	LB *p = H;
	LB *s = new LB;
	while (p->next)
		p = p->next;
	s->next = NULL;
	p->next = s;
	cout << "请输入新添加的第" << i << "人的信息 :" << endl;
	cout << "姓名 : ";
	cin >> s->name;
	cout << "电话号 : ";
	cin >> s->number;
	cout << "性别 :";
	cin >> s->sex;
	cout << "添加成功!" << endl;
}

void del(LB *H) {
	string name;
	LB *p = H;
	cout << "请输入你想删除的人的姓名";
	cin >> name;
	while (p) {
		if (name == p->next->name) {
			p->next = p->next->next;
			cout << "删除成功!" << endl;
			break;
		}
		else {
			p = p->next;
		}
		if (p == NULL) {
			cout << "无相关信息" << endl;
			break;
		}
	}

}

void change(LB *H,string name) {
	LB *p = H;
	while (p) {
		if (name == p->name) {
			cout << "请输入修改后信息 : " << endl;
			cout << "姓名 : ";
			cin >> p->name;
			cout << "电话号 : ";
			cin >> p->number;
			cout << "性别 :";
			cin >> p->sex;
			cout << "添加成功!" << endl;
			break;
		}
		else
			p = p->next;
		if (p == NULL) {
			cout << "无相关信息" << endl;
			break;
		}
	}
}
int main() {
	int i, t = 0;
	string name, j;
	LB *H = new LB;
	cout << "请编辑您的电话簿信息 :" << endl;
	cout << "请输入需要存入的联系人数 :";
	cin >> i;
	Creat_LB(H, i);
	while (t != 8) {
		cout << "**************************************" << endl;
		cout << "电话簿以创建完成，请输入您想执行的功能" << endl;
		cout << "1 查找 2 添加 3 删除 4 显示 5 显示全部" << endl;
		cout << "			6 修改 8结束		   	   " << endl;
		cout << "**************************************" << endl;
		cin >> t;
		if (t == 1) {
			cout << "请输入您想查找的人 :" << endl;
			cin >> name;
			show_1(H, name);
		}
		if (t == 2) {
			add(H, i);
		}
		if (t == 3)
			del(H);
		if (t == 4) {
			cout << "请输入您想显示的人 :" << endl;
			cin >> name;
			show_2(H, name);
		}
		if (t == 5) {
			cout << "全部联系人的信息如下 : " << endl;
			show_3(H);
		}
		if (t == 6) {
			cout << "请输入要修改的联系人的姓名 : ";
			cin >> name;
			change(H, name);
		}
		if (t == 8)
			cout << "程序即将关闭" << endl;
	}
	return 0;
}
