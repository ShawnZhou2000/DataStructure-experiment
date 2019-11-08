#include <iostream>
#include <cstdio>
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

typedef struct SqStack {
	int* base;
	int* top;
	int stacksize;
}SqStack;

void InitStack(SqStack* s) {
	s->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!s->base)
		exit(OVERFLOW);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;

}

bool IsStackEmpty(SqStack s) {
	return s.top == s.base;
}

int StackLength(SqStack s) {
	return s.top - s.base;
}

void Push(SqStack* s, int e) {
	if (s->top - s->base >= s->stacksize) {
		s->base = (int*)realloc(s->base, (s->stacksize + STACK_INCREMENT) * sizeof(int));
		if (!s->base)
			exit(1);
		s->top = s->base + s->stacksize; s->stacksize += STACK_INCREMENT;
	}
	*(s->top)++ = e;
}

int Pop(SqStack* s, int* e) {
	if (s->top == s->base)
		return ERROR;
	*e = *--s->top;
	return OK;
}

void conversion_16() {
	SqStack s;
	int n; 
	int e;
	InitStack(&s); 
	cout << "将10进制数n转换为16进制数\n请输入n(n > 0): ";
	cin >> n; 
	while (1) {
		if (n < 0) {
			cout << "输入错误，请重新输入:";
			cin >> n;
		}
		if (n == 0) {
			cout << "0";
			return;
		}
		else {
			break;
		}
	}
	while (n) { 
		Push(&s, n % 16); 
		n = n / 16;
	}
	while (!IsStackEmpty(s)) { 
		Pop(&s, &e); 
		if (e <= 9)
			cout << e;
		else
			cout << (char)(e + 55); 
	}
	cout << endl;
}

void conversion_8() {
	SqStack s;
	int n;
	int e;
	InitStack(&s);
	cout << "将10进制数n转换为8进制数\n请输入n(n > 0): ";
	cin >> n;
	while (1) {
		if (n < 0) {
			cout << "输入错误，请重新输入:";
			cin >> n;
		}
		if (n == 0) {
			cout << "0";
			return;
		}
		else {
			break;
		}
	}
	while (n) {
		Push(&s, n % 8);
		n = n / 8;
	}
	while (!IsStackEmpty(s)) {
		Pop(&s, &e);
		cout << e;
	}
	cout << endl;
}

void conversion_2() {
	SqStack s;
	SqStack t;
	int n;
	int e;
	InitStack(&s);
	InitStack(&t);
	cout << "将10进制数n转换为2进制数\n请输入n(n > 0): ";
	cin >> n;
	while (1) {
		if (n < 0) {
			cout << "输入错误，请重新输入:";
			cin >> n;
		}
		if (n == 0) {
			cout << "0";
			return;
		}
		else {
			break;
		}
	}
	while (n) {
		Push(&s, n % 2);
		n = n / 2;
	}
	while (!IsStackEmpty(s)) {
		Pop(&s, &e);
		Push(&t, e);
	}

	int cnt = 0;
	while (!IsStackEmpty(t)) {
		Pop(&t, &e);
		cnt++;
		Push(&s, e);
		if (cnt == 4) {
			Push(&s, -1);
			cnt = 0;
		}
	}
	while (!IsStackEmpty(s)) {
		Pop(&s, &e);
		cout << (e == -1 ? ' ' : (char)(e + 48));
	}

	cout << endl;
}

int main() {
	conversion_16();
	conversion_8();
	conversion_2();
	system("pause");
	return 0;
}