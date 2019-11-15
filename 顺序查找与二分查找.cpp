#include <iostream>
#include <cstdio>
#include <windows.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 15
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define MT(a,b) ((a) > (b))
#define LQ(a,b) ((a) <= (b))
#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;

typedef int ElemType;
typedef struct {
	ElemType* elem;
	int length;
	int listsize;

}SSTable;

int initTable(SSTable &l) {
	l.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!l.elem)
		exit(OVERFLOW);
	l.length = 0;
	l.listsize = LIST_INIT_SIZE;
	return OK;
}

int TableInsert(SSTable& l, int i, ElemType e) {
	ElemType* newbase, * q, * p;
	if (i < 1 || i >(l.length + 1))
		return ERROR;
	if (l.length >= l.listsize) {
		newbase = (ElemType*)realloc(l.elem, (l.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);
		l.elem = newbase;
		l.listsize += LISTINCREMENT;

	}
	q = l.elem + i - 1;
	for (p = l.elem + l.length - 1; p >= q; --p) {
		*(p + 1) = *p;
	}
	*q = e;
	++l.length;
	return OK;
}

int Search_Seq(SSTable st, ElemType key) {
	int i, j, k = 0;
	for (i = st.length - 1; !EQ(st.elem[i], key) && i >= 0; --i) {
		k++;
		cout << "�Ƚϵ�Ԫ��Ϊ��" << st.elem[i] << endl;
	}
	if (!EQ(st.elem[i], key)) {
		cout << "���Ҹ�Ԫ�أ��ȽϵĴ���Ϊ��" << k << endl;
		cout << "���ҽ����Ԫ��" << key << "δ�ҵ�" << endl;
		j = TableInsert(st, st.length + 1, key);
		return 1;
	}
	else {
		k++;
		cout << "�Ƚϵ�Ԫ��Ϊ��" << st.elem[i] << endl;
		cout << "���Ҹ�Ԫ�أ��ȽϵĴ���Ϊ��" << k << endl;
		cout << "���ҽ����Ԫ��" << key << "���ҵ���λ��λ��" << i << endl;
		return 0;
	}
}

int Search_Bin(SSTable st, ElemType key) {
	int low, high, mid, j, k = 0;
	low = 0;
	high = st.length - 1;
	mid = 0;
	while (low <= high) {
		mid = (low + high) >> 1;
		if (EQ(key, st.elem[mid])) {
			k++;
			cout << "�Ƚϵ�Ԫ��Ϊ��" << st.elem[mid] << endl;
			cout << "���Ҹ�Ԫ�أ��ȽϵĴ���Ϊ��" << k << endl;
			cout << "���ҽ����Ԫ��" << key << "���ҵ���λ��λ��" << mid << endl;
			return 0;
		}
		else if (LT(key, st.elem[mid])) {
			k++;
			cout << "�Ƚϵ�Ԫ��Ϊ��" << st.elem[mid] << endl;
			high = mid - 1;
		}
		else if (MT(key, st.elem[mid])) {
			k++;
			cout << "�Ƚϵ�Ԫ��Ϊ��" << st.elem[mid] << endl;
			low = mid + 1;
		}
	}
	if (!EQ(key, st.elem[mid])) {
		cout << "���Ҹ�Ԫ�أ��ȽϵĴ���Ϊ��" << k << endl;
		if (LT(key, st.elem[mid])) {
			j = TableInsert(st, mid + 1, key);
		}
		else if (MT(key, st.elem[mid])) {
			j = TableInsert(st, st.length + 1, key);
		}
	}
	cout << "���ҽ����Ԫ��" << key << "δ�ҵ�" << endl;
	return 1;
}

int Menu() {
	int choice;
	cout << "*****************************************" << endl;
	cout << "\t1.�½���̬���ұ�" << endl;
	cout << "\t2.�����̬���ұ�" << endl;
	cout << "\t3.˳�����" << endl;
	cout << "\t4.���ֲ���" << endl;
	cout << "\t5.�˳�" << endl;
	cout << "*****************************************" << endl;
	cout << "��ѡ��";
	cin >> choice;
	return choice;
}

void print(ElemType& c) {
	cout << c << " ";
}

int main() {
	SSTable l;
	int i, k, m, n, ch = 0;
	bool is_created = false;
	while (ch != 5) {
		st:
		ch = Menu();
		switch (ch) {
		case 1:
			cout << "�������L��Ԫ�ظ���n��ֵ:";
			cin >> n;
			initTable(l);
			cout << "������˳����" << n << "��Ԫ�أ�";
			for (int j = 1; j <= n; j++) {
				cin >> k;
				i = TableInsert(l, j, k);
			}
			cout << "�����ɹ���˳����ѽ���" << endl;
			is_created = true;
			system("pause");
			system("cls");
			break;
		case 2:
			if (!is_created) {
				cout << "�����㻹δ�������ұ�" << endl;
			}
			else {
				cout << "˳���L��Ԫ�طֱ�Ϊ��";
				for (i = 0; i < l.length; i++) {
					print(l.elem[i]);
				}
				cout << endl;
			}
			system("pause");
			system("cls");
			break;
		case 3:
			if (!is_created) {
				cout << "�����㻹δ�������ұ�" << endl;
			}
			else {
				cout << "��������ҵ�Ԫ�ص�ֵm��˳����ң���";
				cin >> m;
				if (Search_Seq(l, m))
					l.length++;
				cout << "˳����������" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 4:
			if (!is_created) {
				cout << "�����㻹δ�������ұ�" << endl;
			}
			else {
				cout << "��������ҵ�Ԫ�ص�ֵm�����ֲ��ң���";
				cin >> m;
				if (Search_Bin(l, m))
					l.length++;
				cout << "���ֲ��������" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "��������" << endl;
			system("pause");
			exit(0);
		default:
			cout << "�����������������룡\n" << endl;
			system("cls");
			goto st;
			break;
		}
	}
	return 0;
}