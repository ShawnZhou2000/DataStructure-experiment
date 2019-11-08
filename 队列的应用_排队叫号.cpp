#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#define MAXSIZE 5
using namespace std;

typedef int ElementType;
typedef struct {
	ElementType patient[MAXSIZE];
	int front, rear;
}Queue;

map<int, int> ma;
int macount = 0;

bool check(int item) {
	bool flag = false;
	for (map<int, int>::iterator iter = ma.begin(); iter != ma.end(); iter++) {
		if (iter->second == item) {
			flag = true;
			break;
		}
	}
	if (flag) {
		return true;
	}
	else
		return false;
}

void AddQ(Queue* PtrQ) {
	int i, item;
	
	i = PtrQ->front;
	if ((PtrQ->rear + 1) % MAXSIZE == PtrQ->front) {
		cout << " >>�Ŷ��������࣬������ϲ��ˡ�" << endl;
		return;
	}

	while (1) {
		cout << " >>�����벡����:";
		cin >> item;
		
		if (check(item)) {
			cout << " >>�������ظ�������������" << endl;
			continue;
		}
		else
			break;

	}

	ma[++macount] = item;
	PtrQ->rear = (PtrQ->rear + 1) % MAXSIZE;
	PtrQ->patient[PtrQ->rear] = item;
	
}

void Treatment(Queue* PtrQ)
{
	int patient;
	if (PtrQ->front == PtrQ->rear)
	{
		cout << " >>û�����Ŷӿ���.\n";
		return;
	}
	else
	{
		PtrQ->front = (PtrQ->front + 1) % MAXSIZE;
		patient = PtrQ->patient[PtrQ->front];
		cout << " >>����" << patient << "����\n";
		for (map<int, int>::iterator iter = ma.begin(); iter != ma.end(); iter++) {
			if (iter->second == patient) {
				iter->second = NULL;
				break;
			}
		}
		return;
	}
}

void print(Queue* PtrQ)
{
	int i = PtrQ->front;
	if (PtrQ->front == PtrQ->rear)
	{
		printf(" >>û�������Ŷ�.\n");
		return;
	}
	else
	{
		printf(" >>�Ŷӵ�����:");
		while (i != PtrQ->rear)
		{
			cout << PtrQ->patient[(i + 1) % MAXSIZE] << " ";
			i++;
			i = i % MAXSIZE;
		}
		printf("\n");
	}
	return;
}
// �������ξ�������Ŷ�(��������)
void NoMoreQueue(Queue* PtrQ)
{
	int i;
	if (PtrQ->front == PtrQ->rear)
	{
		printf(" >>û���Ŷӵ���.\n");
		return;
	}
	else
	{
		i = PtrQ->front;
		printf(" >>���˰�����˳�����:");
		while (i % MAXSIZE != PtrQ->rear)
		{
			printf("%d ", PtrQ->patient[i + 1]);
			i++;
		}
		printf("\n");
	}
	return;
}
int main() {
	int flag = 1, sel;
	Queue* p;
	p = (Queue*)malloc(sizeof(Queue));
	p->front = 0;
	p->rear = 0;
	while (flag) {
		cout << "1:�Ŷ� 2:���� 3:�鿴�Ŷ� 4.�����Ŷ�,�������ξ��� 5:�°�\n��ѡ��:";
		cin >> sel;
		switch (sel) {
		case 1:
			
			AddQ(p);
			break;
		case 2:
			Treatment(p);
			break;
		case 3:
			print(p);
			break;
		case 4:
			NoMoreQueue(p);
			break;
		case 5:
			if (p->front != p->rear)
				cout << " >>���ŶӵĲ��������ҽ!����Ҫ�°���\n";
			else
				cout << " >>�Ѿ�û���ŶӵĲ���,����׼���°�!\n";
			flag = 0;
			break;
		}
	}
	return 0;
}