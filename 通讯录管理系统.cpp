
#include<iostream>
using namespace std;
#include<string>
#define MAX 1000 //�������

struct person
{
	string name;
	long long number;
};

void showMenu()
{
	cout << "****************************" << endl;
	cout << "*****  1�������ϵ��   *****" << endl;
	cout << "*****  2����ʾ��ϵ��   *****" << endl;
	cout << "*****  3��ɾ����ϵ��   *****" << endl;
	cout << "*****  4��������ϵ��   *****" << endl;
	cout << "*****  5���޸���ϵ��   *****" << endl;
	cout << "*****  6�������ϵ��   *****" << endl;
	cout << "*****  0���˳�ͨѶ¼   *****" << endl;
	cout << "****************************" << endl;
}

void cls()    //����
{
	system("pause");
	system("cls");
	showMenu();
}

void creatPer(person per[], int* j)
{
	cout << "������������";
	cin >> per[*j].name;
	cout << "������绰���룺";
	cin >> per[*j].number;
	*j += 1;
	cout << "��ӳɹ���" << endl;
	cls();
}

void printPer(person per[], int j)
{
	int i;
	if (j != 0)
		for (i = 0; i < j; i++)
			cout << "������" << per[i].name << " �绰��" << per[i].number << endl;
	else
		cout << "����ϵ��" << endl;
	cls();
}

void delPer(person per[], int* j)
{
	int i, k = 0;
	string delname;
	cout << "��������Ҫɾ������ϵ�ˣ�";
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
		cout << "ɾ���ɹ���" << endl;
	}
	else
		cout << "���޴��ˣ�" << endl;
	cls();
}

void findPer(person per[], int j)
{
	int i, k = 0;
	string cname;
	cout << "������Ҫ���ҵ���ϵ�ˣ�";
	cin >> cname;
	for (i = 0; i < j; i++)
		if (cname == per[i].name)
		{
			cout << "������" << per[i].name << " �绰��" << per[i].number << endl;
			k++;
		}
	if (k == 0)
		cout << "���޴��ˣ�" << endl;
	cls();
}

void modifyPer(person per[], int j)
{
	int i, k = 0;
	string cname;
	cout << "ѡ����Ҫ�޸ĵ���ϵ�ˣ�";
	cin >> cname;
	for (i = 0; i < j; i++)
		if (per[i].name == cname)
		{
			cout << "������Ҫ�޸ĵ�������";
			cin >> per[i].name;
			cout << "������Ҫ�޸ĵĵ绰��";
			cin >> per[i].number;
			k++;
			cout << "�޸ĳɹ���" << endl;
		}
	if (k == 0)
		cout << "���޴��ˣ�" << endl;
	cls();
}

void clearPer(person per[], int* j)
{
	*j = 0;
	cout << "����գ�" << endl;
	cls();
}


int main()
{
	int j, a;
	j = 0; //ͨѶ¼����
	a = 1; //���빦��ѡ��
	person per[MAX]; //��ϵ������
	showMenu(); //��ʾ�˵�
	while (a != 0) {
		cout << "��ѡ���ܣ�";
		cin >> a;
		if (a == 0)
		{
			cout << "��ӭ�´�ʹ�ã�";
			return 0;
		}
		else if (a == 1)
			if (j < MAX)
				creatPer(per, &j); //�����ϵ�˺���
			else
			{
				cout << "��ϵ��������" << endl;
			}
		else if (a == 2)
			printPer(per, j); //��ʾ��ϵ�˺���
		else if (a == 3)
			delPer(per, &j); //ɾ����ϵ�˺���
		else if (a == 4)
			findPer(per, j); //������ϵ��
		else if (a == 5)
			modifyPer(per, j); //�޸���ϵ��
		else if (a == 6)
			clearPer(per, &j); //�����ϵ�˺���
	}
}