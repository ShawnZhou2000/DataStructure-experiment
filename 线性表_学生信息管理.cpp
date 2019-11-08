#include <iostream>
#include <cstdio>   
#include <string>
#include <Windows.h>
#define OK 1  
#define ERROR 0  
#define OVERFLOW -2  
#define MAXSIZE 100  
using namespace std;
typedef int Status; // 定义函数返回值类型  

typedef struct {
	string num; // 学号  
	string name; // 姓名  
	double grade = 0.0; // 成绩   

}student;

typedef student ElemType;

typedef struct {
	ElemType* elem; // 存储空间的基地址   
	int length; // 当前长度   

} SqList;

Status InitList(SqList* L) { // 构造空的顺序表 L   
	L->elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	if (!L->elem)  
		exit(OVERFLOW);
	L->length = 0;
	return OK;
}

ElemType GetElem(SqList& L, int i) { // 访问顺序表，找到 i位置，返回给 e  
	return L.elem[i];
}

int Search(SqList& L, string str) { // 根据名字查找，返回该同学在顺序表中的编号   
	for (int i = 1; i <= L.length; i++) {
		if (L.elem[i].name == str)
			return i;
	}
	return 0;
}

Status ListInsert(SqList& L, int i, ElemType e) { // 在 i位置插入某个学生的信息   
	if ((i < 1) || (i > L.length + 1)) 
		return ERROR;
	if (L.length == MAXSIZE)   
		return ERROR;
	for (int j = L.length; j >= i; j--) {
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i] = e;
	++L.length;
	return OK;
}

Status ListDelete(SqList& L, int i) { // 在顺序表中删除 i位置的学生信息   
	if ((i < 1) || (i > L.length))   
		return ERROR;
	for (int j = i; j <= L.length; j++) {
		L.elem[j] = L.elem[j + 1];
	}
	--L.length;
	return OK;
}

void Input(ElemType* e) {
	cout << "姓名：";
	cin >> e->name;
	cout << "学号";
	cin >> e->num;
	cout << "成绩：";
	cin >> e->grade;
	cout << "输入完成！\n\n";
}

void Output(ElemType* e) {
	cout << "\t" << e->name << "\t" << e->num << "\t" << e->grade << endl;
}

void PrintList() {
	cout << "\n\t\t\t\t\t\t学生成绩管理系统" << endl;
	cout << "\t\t\t\t=========================================================" << endl;
	cout << "\t\t\t\t|\t\t1. 构造顺序表\t\t\t\t|\n";
	cout << "\t\t\t\t|\t\t2. 录入学生信息\t\t\t\t|\n";
	cout << "\t\t\t\t|\t\t3. 显示学生信息\t\t\t\t|\n";
	cout << "\t\t\t\t|\t\t4. 输入姓名，查找该学生\t\t\t|\n";
	cout << "\t\t\t\t|\t\t5. 显示某位置该学生信息\t\t\t|\n";
	cout << "\t\t\t\t|\t\t6. 在指定位置插入学生信息\t\t|\n";
	cout << "\t\t\t\t|\t\t7. 在指定位置删除学生信息\t\t|\n";
	cout << "\t\t\t\t|\t\t8. 统计学生个数\t\t\t\t|\n";
	cout << "\t\t\t\t|\t\t0. 退出\t\t\t\t\t|\n";
	cout << "\t\t\t\t=========================================================" << endl;
}

int main() {
	SqList L = SqList();
	ElemType a, b, c, d;
	int x = 0, choose;
	string s;
	bool isCreated = false;
	
	system("COLOR 71");
	system("TITLE 学生成绩管理系统");

	while (1) {
		PrintList();
		cout << "请选择对应的项目编号：" << endl;
		while (1) {
			cin >> choose;
			if (!((choose >= 1 && choose <= 8) || (choose == 0))) {
				system("cls");
				PrintList();
				cout << "输入有误！请重新输入：";
			}
			else
				break;
		}

		if (choose == 0)   
			break;

		switch (choose) {
		case 1:
			if (InitList(&L)) {
				cout << "成功建立顺序表\n\n";
				system("pause");
				system("cls");
				isCreated = true;
			}
			else {
				cout << "顺序表建立失败\n\n";
				system("pause");
				system("cls");
			}
			break;
		case 2:
			if (!isCreated) {
				cout << "错误，未建立顺序表" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "请输入要录入学生的人数（小于" << MAXSIZE << "）:";
			cin >> x;
		
			for (int i = 1; i <= x; i++) {
				cout << "第" << i << "个学生：" << endl;
				Input(&L.elem[i]);
			}
			L.length = x;
			cout << "所有的学生信息录入完成了！" << endl;
			system("pause");
			system("cls");
			
			break;
		case 3:
			if (!isCreated) {
				cout << "错误，未建立顺序表" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "\t" << "姓名" << "\t" << "学号" << "\t" << "成绩" << endl;
			for (int i = 1; i <= x; i++) {
				a = GetElem(L, i);
				Output(&a);
			}
			system("pause");
			system("cls");
			break;
		case 4:
			if (!isCreated) {
				cout << "错误，未建立顺序表" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "请输入要查找的学生姓名：";
			cin >> s;
			if (Search(L, s))
				Output(&L.elem[Search(L, s)]);
			else
				cout << "对不起，查无此人" << endl;
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			if (!isCreated) {
				cout << "错误，未建立顺序表" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "请输入要查询的位置:";
			int id1;
			cin >> id1;
			b = GetElem(L, id1);
			Output(&b);
			system("pause");
			system("cls");
			break;
		case 6:
			if (!isCreated) {
				cout << "错误，未建立顺序表" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "请输入要插入的位置:";
			int id2;
			cin >> id2;
			cout << "请输入学生信息:" << endl;
			Input(&c);
			if (ListInsert(L, id2, c)) {
				x++;
				cout << "插入成功" << endl;
			}
			else {
				cout << "插入失败" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 7:
			if (!isCreated) {
				cout << "错误，未建立顺序表" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "请输入要删除的位置:";
			int id3;
			cin >> id3;
			if (ListDelete(L, id3)) {
				x--;
				cout << "删除成功" << endl;		
			}
			else {
				cout << "删除失败" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 8:
			if (!isCreated) {
				cout << "错误，未建立顺序表" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "已录入的学生个数为:" << L.length << "\n" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	cout << "\n\n谢谢您的使用，请按任意键退出\n\n\n";
	system("pause");
	return 0;
}
