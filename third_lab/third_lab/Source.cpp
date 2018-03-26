#include <iostream>
#include <string>
#include <iomanip>
#include "windows.h"
using namespace std;

struct Node
{
	char point[20];    //- ����� ����������;
	int reis;        //- ����� �����;
	char name[12];    //- ������� ���������;
	char surname[12];    //- ���
	char patr[12];    //- ��������
	char date[12];  //- �������� ���� ������;
	Node * next;    // ��������� �� ��������� ������.
};

void Menu();
Node *addNode(Node *first); // - ���������� ������ � ������;
Node *deleteNode(Node *first); // - �������� ������ �� ��������� ������ �����
void outNode(Node *first); // - ����� ���� ������.
void outNodeNum(Node *first); // ����� ����� ������

int main()
{
	//setlocale(LC_ALL, "Russian");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Node *first = new Node;
	//int n = 1;
	//cout << "-------������ � ������-------\n\n";
	//cout << "������� ����� ���������� > ";
	//cin >> first->point;
	//cout << "������� ����� ����� > ";
	//cin >> first->reis;
	//cout << "������� ������� ��������� > ";
	//cin >> first->name;
	//cout << "������� ��� ��������� > ";
	//cin >> first->surname;
	//cout << "������� �������� ��������� > ";
	//cin >> first->patr;
	//cout << "������� ���� ������ > ";
	//cin >> first->date;
	//cout << "\n";
	//first->next = NULL;

	////////////////////////////////////////////////////////
	Node *first = new Node;  first->reis = 1021;  strcpy_s(first->name, 20, "�����"); strcpy_s(first->surname, 20, "����");  strcpy_s(first->patr, 20, "������"); strcpy_s(first->point, 20, "������");
	Node *f1 = new Node;     f1->reis = 20;       strcpy_s(f1->name, 20, "�������");  strcpy_s(f1->surname, 20, "����");     strcpy_s(f1->patr, 20, "���������"); strcpy_s(f1->point, 20, "�����������");
	Node *f2 = new Node;     f2->reis = 3010;     strcpy_s(f2->name, 20, "������");   strcpy_s(f2->surname, 20, "���������"); strcpy_s(f2->patr, 20, "���������"); strcpy_s(f2->point, 20, "�����");
	Node *f3 = new Node;     f3->reis = 4201;     strcpy_s(f3->name, 20, "���");      strcpy_s(f3->surname, 20, "����");      strcpy_s(f3->patr, 20, "����������"); strcpy_s(f3->point, 20, "������");

	first->next = f1;
	f1->next = f2;
	f2->next = f3;
	f3->next = NULL;
	////////////////////////////////////////////////////////
	int k = 5;
	while (k != 6)
	{
		switch (k)
		{
		case 1: first = addNode(first); break;
		case 2: outNode(first); break;
		case 3:	outNodeNum(first); break;
		case 4: first = deleteNode(first); break;
		case 5: Menu(); break;
		case 6: break;
		default: cout << "  ������! ����� �� 1 �� 6.\n";
		}
		cout << "\n������� ������ �����: ";
		cin >> k;
	}
	getchar(); // �����	
	return 0;
}


void Menu()
{
	system("cls");
	cout << "\n";
	cout << "1 - �������� ������\n";
	cout << "2 - ������� ��� ������\n";
	cout << "3 - ������� ������ �� ������ ����� � ���� ������\n";
	cout << "4 - ������� ������\n";
	cout << "5 - �������� �����\n";
	cout << "6 - �����\n";
}

Node *addNode(Node *first)
{
	cout << "______________________________________________\n";
	Node *pv = new Node;
	cout << "������ � ������: \n";
	cout << "������� ����� ���������� > ";
	cin >> pv->point;
	cout << "������� ����� ����� > ";
	cin >> pv->reis;
	cout << "������� ������� ��������� > ";
	cin >> pv->name;
	cout << "������� ��� ��������� > ";
	cin >> pv->surname;
	cout << "������� �������� ��������� > ";
	cin >> pv->patr;
	cout << "������� ���� ������ > ";
	cin >> pv->date;
	cout << "\n";
	pv->next = NULL;
	cout << "______________________________________________\n";
	if (first == NULL)
	{
		first = pv;
	}
	else
	{
		Node *p = first;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = pv;
	}
	return first;
}

void outNode(Node *first)
{
	//Node *pv = first;
	//while (pv)
	//{
	//	cout << "\n������ � ������ \n";
	//	cout << "\n����� ���������� > " << pv->point;
	//	cout << "\n����� ����� > "; cout << pv->reis;
	//	cout << "\n������� ��������� > " << pv->name;
	//	cout << "\n��� ��������� > " << pv->surname;
	//	cout << "\n�������� ��������� > " << pv->patr;
	//	cout << "\n���� ������ > " << pv->date << "\n\n\n";
	//	pv = pv->next;
	//}

	cout << setiosflags(ios::right);
	cout << "_________________________________________________________________\n";
	cout << "������ �� �������:\n";
	cout << "       �����  �����    �������      ���      ��������        ����\n";
	cout << "  ����������  �����  --------- ������ ��������� -----      ������\n";

	Node *pv = first;
	while (pv)
	{
		cout << setw(12) << pv->point << setw(7) << pv->reis << setw(11) << pv->name;
		cout << setw(10) << pv->surname << setw(13) << pv->patr << setw(12) << "12.11.2017" << endl;
		pv = pv->next;
	}
	cout << "_________________________________________________________________\n";
}

void outNodeNum(Node *first)
{
	int num;
	string dat;
	Node *pv = first;
	cout << "������� ����� �����: ";
	cin >> num;
	cout << "������� ����: ";
	cin >> dat;
	int n = 1, fl = 0;
	while (pv)
	{
		if (pv->reis == num && pv->date == dat)
		{
			outNode(pv);
			break;
		}
		pv = pv->next;
	}
}

Node *deleteNode(Node *first)
{
	cout << "______________________________________________\n";
	cout << "����� �����, ������ �� �������� �������: ";
	int num;
	cin >> num;

	Node *temp = first;
	int k = -1;
	int N = 0;
	while (temp)
	{
		if (temp->reis == num)
		{
			k = N;
		}
		temp = temp->next;
		N++;
	}
	N--;
	if (k != -1)
	{
		temp = first;
		// ���� ����� ������� 1-� ���� � �� ������������ ��� � ������
		if (k == 0 && N == 0)
		{
			delete first;
			cout << "  �������� ������ �������!\n";
			cout << "______________________________________________\n";
			return NULL;
		}
		// ���� ����� ������� 1-� ���� � �� �� ������������ � ������
		if (k == 0 && N > 0)
		{
			temp = temp->next;
			delete first;
			cout << "  �������� ������ �������!\n";
			cout << "______________________________________________\n";
			return temp;
		}
		// ���� ����� ������� ���� ���-�� � �������� ������, �� �� ����������
		Node *el = first;
		temp = first->next;
		while (temp->next)
		{
			if (temp->reis == num)
			{
				el->next = temp->next;
				delete temp;
				cout << "  �������� ������ �������!\n";
				cout << "______________________________________________\n";
				return first;
			}
			el = el->next;
			temp = temp->next;
		}
		// ���� ����� ������� ��������� ����
		el->next = NULL;
		delete temp;
		cout << "  �������� ������ �������!\n";
		cout << "______________________________________________\n";
		return first;
	}
	else
	{
		cout << "  ������ ����� ��� ��� ������ ����!\n";
		cout << "______________________________________________\n";
		return first;
	}
}