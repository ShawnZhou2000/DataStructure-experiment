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
		cout << "比较的元素为：" << st.elem[i] << endl;
	}
	if (!EQ(st.elem[i], key)) {
		cout << "查找该元素，比较的次数为：" << k << endl;
		cout << "查找结果：元素" << key << "未找到" << endl;
		j = TableInsert(st, st.length + 1, key);
		return 1;
	}
	else {
		k++;
		cout << "比较的元素为：" << st.elem[i] << endl;
		cout << "查找该元素，比较的次数为：" << k << endl;
		cout << "查找结果：元素" << key << "已找到，位于位置" << i << endl;
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
			cout << "比较的元素为：" << st.elem[mid] << endl;
			cout << "查找该元素，比较的次数为：" << k << endl;
			cout << "查找结果：元素" << key << "已找到，位于位置" << mid << endl;
			return 0;
		}
		else if (LT(key, st.elem[mid])) {
			k++;
			cout << "比较的元素为：" << st.elem[mid] << endl;
			high = mid - 1;
		}
		else if (MT(key, st.elem[mid])) {
			k++;
			cout << "比较的元素为：" << st.elem[mid] << endl;
			low = mid + 1;
		}
	}
	if (!EQ(key, st.elem[mid])) {
		cout << "查找该元素，比较的次数为：" << k << endl;
		if (LT(key, st.elem[mid])) {
			j = TableInsert(st, mid + 1, key);
		}
		else if (MT(key, st.elem[mid])) {
			j = TableInsert(st, st.length + 1, key);
		}
	}
	cout << "查找结果：元素" << key << "未找到" << endl;
	return 1;
}

int Menu() {
	int choice;
	cout << "*****************************************" << endl;
	cout << "\t1.新建静态查找表" << endl;
	cout << "\t2.输出静态查找表" << endl;
	cout << "\t3.顺序查找" << endl;
	cout << "\t4.二分查找" << endl;
	cout << "\t5.退出" << endl;
	cout << "*****************************************" << endl;
	cout << "请选择：";
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
			cout << "请输入表L的元素个数n的值:";
			cin >> n;
			initTable(l);
			cout << "请输入顺序表的" << n << "个元素：";
			for (int j = 1; j <= n; j++) {
				cin >> k;
				i = TableInsert(l, j, k);
			}
			cout << "操作成功，顺序表已建立" << endl;
			is_created = true;
			system("pause");
			system("cls");
			break;
		case 2:
			if (!is_created) {
				cout << "错误，你还未建立查找表！" << endl;
			}
			else {
				cout << "顺序表L的元素分别为：";
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
				cout << "错误，你还未建立查找表！" << endl;
			}
			else {
				cout << "请输入查找的元素的值m（顺序查找）：";
				cin >> m;
				if (Search_Seq(l, m))
					l.length++;
				cout << "顺序查找已完成" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 4:
			if (!is_created) {
				cout << "错误，你还未建立查找表！" << endl;
			}
			else {
				cout << "请输入查找的元素的值m（二分查找）：";
				cin >> m;
				if (Search_Bin(l, m))
					l.length++;
				cout << "二分查找已完成" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "结束程序" << endl;
			system("pause");
			exit(0);
		default:
			cout << "输入有误，请重新输入！\n" << endl;
			system("cls");
			goto st;
			break;
		}
	}
	return 0;
}