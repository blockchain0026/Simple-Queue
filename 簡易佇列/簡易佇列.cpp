// 簡易佇列.cpp : 定義主控台應用程式的進入點。
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
		cout << endl << "佇列已滿" << endl << endl;
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
		cout << endl << "佇列已空" << endl << endl;
		return false;
	}
	F->front = (F->front + 1) % MAX;
	*abc = F->inf[F->front];
	return true;
}
int main()
{
	cout << "【ProgramF】";
	int *ran = new int;
	char a[] = "add", b[] = "load", c[] = "del", *d;
	d = new char;
	queue *PF = new queue;
	cout << endl << "-- 佇列實作：簡易 --";
restart:
	cout << endl << endl << "請輸入指令：";
	cin >> d;

	if (strcmp(d, a) == 0)
	{
	keep:
		cout << endl << endl << "請輸入數字：";
		cin >> *ran;
		if (EnQueue(PF, *ran))
		{
			for (int i = 0;i < MAX;i++)
				cout << PF->inf[i] << endl << endl;
		}
		cout << "繼續輸入1 , 返回輸入2：";
		cin >> *ran;
		if (*ran == 1)
			goto keep;
		else
			goto restart;
	}
	if (strcmp(d, b) == 0)
	{
		if (DeQueue(PF, ran))
			cout << "讀取數字：" << *ran << endl;
		goto restart;
	}

	system("pause");
	return 0;
}


