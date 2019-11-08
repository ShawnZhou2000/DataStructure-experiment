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
		cout << " >>排队人数过多，请先诊断病人。" << endl;
		return;
	}

	while (1) {
		cout << " >>请输入病历号:";
		cin >> item;
		
		if (check(item)) {
			cout << " >>病历号重复，请重新输入" << endl;
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
		cout << " >>没人在排队看病.\n";
		return;
	}
	else
	{
		PtrQ->front = (PtrQ->front + 1) % MAXSIZE;
		patient = PtrQ->patient[PtrQ->front];
		cout << " >>病人" << patient << "就诊\n";
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
		printf(" >>没有人在排队.\n");
		return;
	}
	else
	{
		printf(" >>排队的人有:");
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
// 余下依次就诊，不再排队(遍历队列)
void NoMoreQueue(Queue* PtrQ)
{
	int i;
	if (PtrQ->front == PtrQ->rear)
	{
		printf(" >>没有排队的人.\n");
		return;
	}
	else
	{
		i = PtrQ->front;
		printf(" >>病人按以下顺序就诊:");
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
		cout << "1:排队 2:就诊 3:查看排队 4.不再排队,余下依次就诊 5:下班\n请选择:";
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
				cout << " >>请排队的病人明天就医!现在要下班了\n";
			else
				cout << " >>已经没有排队的病人,现在准备下班!\n";
			flag = 0;
			break;
		}
	}
	return 0;
}