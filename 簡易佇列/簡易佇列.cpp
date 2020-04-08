// ²����C.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#define MAX 5
using namespace std;

typedef struct Queue
{
	int front = 0;
	int inf[MAX];
	int rear = 0;
}queue;

int EnQueue(queue *F, int abc)
{
	if (((F->rear) + 1) % MAX == F->front)
	{
		cout << endl << "��C�w��" << endl << endl;
		return false;
	}
	F->rear = (F->rear + 1) % MAX;
	F->inf[F->rear] = abc;
	return true;
}

int DeQueue(queue *F, int *abc)
{
	if (F->front == F->rear)
	{
		cout << endl << "��C�w��" << endl << endl;
		return false;
	}
	F->front = (F->front + 1) % MAX;
	*abc = F->inf[F->front];
	return true;
}
int main()
{
	cout << "�iProgramF�j";
	int *ran = new int;
	char a[] = "add", b[] = "load", c[] = "del", *d;
	d = new char;
	queue *PF = new queue;
	cout << endl << "-- ��C��@�G²�� --";
restart:
	cout << endl << endl << "�п�J���O�G";
	cin >> d;

	if (strcmp(d, a) == 0)
	{
	keep:
		cout << endl << endl << "�п�J�Ʀr�G";
		cin >> *ran;
		if (EnQueue(PF, *ran))
		{
			for (int i = 0;i < MAX;i++)
				cout << PF->inf[i] << endl << endl;
		}
		cout << "�~���J1 , ��^��J2�G";
		cin >> *ran;
		if (*ran == 1)
			goto keep;
		else
			goto restart;
	}
	if (strcmp(d, b) == 0)
	{
		if (DeQueue(PF, ran))
			cout << "Ū���Ʀr�G" << *ran << endl;
		goto restart;
	}

	system("pause");
	return 0;
}


