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
	cout << "二叉树初始化成功！" << endl;
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
	cout << "按先序序列建立一个二叉树已经完成！" << endl;
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
		cout << "是空二叉树!" << endl;
	else
		cout << "不是空二叉树!" << endl;
}

int main() {
	int opt;
	bittree bt;
	cout << "1.初始化二叉树\n" << "2.按先序序列建立二叉树\n" << "3.判断二叉树是否为空\n" << "4.先序遍历二叉树\n" << "5.中序遍历二叉树\n" << "6.后序遍历二叉树\n" << "7.求二叉树的深度\n" << "8.求二叉树的结点个数" << endl;
	while (1) {
		cout << "请输入你的操作：(输入-1退出)";
		cin >> opt;
		switch (opt) {
			case 1:
				bintreeinit(bt);
				cout << "初始化成功" << endl;
				break;
			case 2:
				cout << "输入你要建立的二叉树：" << endl;
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
				cout << "二叉树的深度为：" << bintreedepth(bt) << endl;
				break;
			case 8:
				cout << "二叉树的结点数为：" << bintreecount(bt) << endl;
				break;
			case -1:
				return 0;
				break;
			default:
				cout << "输入有误，请重新输入：";
				cin >> opt;
				break;
		}
	}
	return 0;
}