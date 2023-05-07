
#include<iostream>
using namespace std;
#include<string>
#define MAX 1000 //最大人数

struct person
{
	string name;
	long long number;
};

void showMenu()
{
	cout << "****************************" << endl;
	cout << "*****  1、添加联系人   *****" << endl;
	cout << "*****  2、显示联系人   *****" << endl;
	cout << "*****  3、删除联系人   *****" << endl;
	cout << "*****  4、查找联系人   *****" << endl;
	cout << "*****  5、修改联系人   *****" << endl;
	cout << "*****  6、清空联系人   *****" << endl;
	cout << "*****  0、退出通讯录   *****" << endl;
	cout << "****************************" << endl;
}

void cls()    //清屏
{
	system("pause");
	system("cls");
	showMenu();
}

void creatPer(person per[], int* j)
{
	cout << "请输入姓名：";
	cin >> per[*j].name;
	cout << "请输入电话号码：";
	cin >> per[*j].number;
	*j += 1;
	cout << "添加成功！" << endl;
	cls();
}

void printPer(person per[], int j)
{
	int i;
	if (j != 0)
		for (i = 0; i < j; i++)
			cout << "姓名：" << per[i].name << " 电话：" << per[i].number << endl;
	else
		cout << "无联系人" << endl;
	cls();
}

void delPer(person per[], int* j)
{
	int i, k = 0;
	string delname;
	cout << "请输入您要删除的联系人：";
	cin >> delname;
	for (i = 0; i < *j; i++)
		if (per[i].name == delname)
		{
			k++;
			break;
		}
	if (k != 0)
	{
		for (; i < *j; i++)
			per[i] = per[i + 1];
		*j -= 1;
		cout << "删除成功！" << endl;
	}
	else
		cout << "查无此人！" << endl;
	cls();
}

void findPer(person per[], int j)
{
	int i, k = 0;
	string cname;
	cout << "输入您要查找的联系人：";
	cin >> cname;
	for (i = 0; i < j; i++)
		if (cname == per[i].name)
		{
			cout << "姓名：" << per[i].name << " 电话：" << per[i].number << endl;
			k++;
		}
	if (k == 0)
		cout << "查无此人！" << endl;
	cls();
}

void modifyPer(person per[], int j)
{
	int i, k = 0;
	string cname;
	cout << "选择您要修改的联系人：";
	cin >> cname;
	for (i = 0; i < j; i++)
		if (per[i].name == cname)
		{
			cout << "输入您要修改的姓名：";
			cin >> per[i].name;
			cout << "输入您要修改的电话：";
			cin >> per[i].number;
			k++;
			cout << "修改成功！" << endl;
		}
	if (k == 0)
		cout << "查无此人！" << endl;
	cls();
}

void clearPer(person per[], int* j)
{
	*j = 0;
	cout << "已清空！" << endl;
	cls();
}


int main()
{
	int j, a;
	j = 0; //通讯录人数
	a = 1; //进入功能选择
	person per[MAX]; //联系人数组
	showMenu(); //显示菜单
	while (a != 0) {
		cout << "请选择功能：";
		cin >> a;
		if (a == 0)
		{
			cout << "欢迎下次使用！";
			return 0;
		}
		else if (a == 1)
			if (j < MAX)
				creatPer(per, &j); //添加联系人函数
			else
			{
				cout << "联系人已满！" << endl;
			}
		else if (a == 2)
			printPer(per, j); //显示联系人函数
		else if (a == 3)
			delPer(per, &j); //删除联系人函数
		else if (a == 4)
			findPer(per, j); //查找联系人
		else if (a == 5)
			modifyPer(per, j); //修改联系人
		else if (a == 6)
			clearPer(per, &j); //清空联系人函数
	}
}