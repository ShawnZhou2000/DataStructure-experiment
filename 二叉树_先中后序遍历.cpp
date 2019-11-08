#include <iostream>
#include <cstdlib>
using namespace std;
typedef char datatype;
typedef struct bitnode {
	datatype data;
	bitnode* lchild, * rchild;

}*bittree;

void bintreeinit(bittree& bt) {
	bt = (bittree)malloc(sizeof(bitnode));
	bt->data = NULL;
	cout << "��������ʼ���ɹ���" << endl;
}

int bintreecreat(bittree& bt) {
	char ch;
	cin >> ch;
	if (ch == '#')
		bt = NULL;
	else {
		if (!(bt = (bittree)malloc(sizeof(bitnode))))
			exit(0);
		bt->data = ch;
		bintreecreat(bt->lchild);
		bintreecreat(bt->rchild);
	}
	return 0;
	cout << "���������н���һ���������Ѿ���ɣ�" << endl;
}

void binpretraverse(bittree& bt) {
	if (bt != NULL) {
		cout << bt->data << " ";
		binpretraverse(bt->lchild);
		binpretraverse(bt->rchild);
	}
}

void binintraverse(bittree& bt) {
	if (bt != NULL) {
		binintraverse(bt->lchild);
		cout << bt->data << " ";
		binintraverse(bt->rchild);
	}
}

void binposttraverse(bittree& bt) {
	if (bt != NULL) {
		binposttraverse(bt->lchild);
		binposttraverse(bt->rchild);
		cout << bt->data << " ";
	}
}

int bintreedepth(bittree bt) {
	int depthval;
	if (bt) {
		int depthLeft = bintreedepth(bt->lchild);
		int depthRight = bintreedepth(bt->rchild);
		depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
	}
	else depthval = 0;
	return depthval;
}

int bintreecount(bittree bt) {
	int node;
	if (bt) {
		int lchild = bintreecount(bt->lchild);
		int rchild = bintreecount(bt->rchild);
		node = lchild + rchild + 1;
	}
	else
		node = 0;
	return node;
}

void bintreeempty(bittree& bt) {
	if (bt->data == NULL)
		cout << "�ǿն�����!" << endl;
	else
		cout << "���ǿն�����!" << endl;
}

int main() {
	int opt;
	bittree bt;
	cout << "1.��ʼ��������\n" << "2.���������н���������\n" << "3.�ж϶������Ƿ�Ϊ��\n" << "4.�������������\n" << "5.�������������\n" << "6.�������������\n" << "7.������������\n" << "8.��������Ľ�����" << endl;
	while (1) {
		cout << "��������Ĳ�����(����-1�˳�)";
		cin >> opt;
		switch (opt) {
			case 1:
				bintreeinit(bt);
				cout << "��ʼ���ɹ�" << endl;
				break;
			case 2:
				cout << "������Ҫ�����Ķ�������" << endl;
				bintreecreat(bt);
				break;
			case 3:
				bintreeempty(bt);
				break;
			case 4:
				binpretraverse(bt);
				break;
			case 5:
				binintraverse(bt);
				break;
			case 6:
				binposttraverse(bt);
				break;
			case 7:
				cout << "�����������Ϊ��" << bintreedepth(bt) << endl;
				break;
			case 8:
				cout << "�������Ľ����Ϊ��" << bintreecount(bt) << endl;
				break;
			case -1:
				return 0;
				break;
			default:
				cout << "�����������������룺";
				cin >> opt;
				break;
		}
	}
	return 0;
}