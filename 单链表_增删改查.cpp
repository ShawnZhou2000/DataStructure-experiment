#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;
typedef struct node {
	string data;
	node* next;
}listnode, *linklist;


listnode* locateNode(linklist head, string k) {
	listnode* p = head->next;
	while (p != NULL && p->data == k) {
		p = p->next;
	}
	return p;
}

linklist createListR1() {
	string ch;
	linklist head = new listnode;
	listnode* s = nullptr, * r = nullptr, * pp = nullptr;
	r = head;
	r->next = NULL;
	cout << "input # to end: " << endl;
	cout << "Please input node data:  ";
	cin >> ch;
	while (ch != "#") {
		pp = locateNode(head, ch);

		if (pp == NULL) {
			s = new listnode;
			s->data = ch;
			r->next = s;
			r = s;
			r->next = NULL;
		}
		cout << "input # to end: " << endl;
		cout << "Please input node data:  ";
		cin >> ch;
	}
	free(s);
	free(r);
	free(pp);
	return head;
}

linklist createList() {
	string ch;
	linklist head = nullptr, p = nullptr;
	head = new listnode;
	head->next = NULL;
	while (1) {
		cout << "input # to end: " << endl;
		cout << "Please input node data:  ";
		cin >> ch;
		if (ch != "#") {
			if (locateNode(head, ch) == NULL) {
				head->data = ch;
				// p = (linklist)malloc(sizeof(listnode));
				p = new listnode;
				p->next = head;
				head = p;
			}
		}
		else
			break;
	}
	free(p);
	return head;
}


void deleteList(linklist head, string k) {
	listnode* p = nullptr, * r = nullptr, * q = head;
	p = locateNode(head, k);
	if (p == NULL) {
		cerr << "position ERROR";
		throw(-1);
		exit(0);
	}
	while (q->next != p) {
		q = q->next;
	}
	r = q->next;
	q->next = r->next;
	free(r);
}

void printList(linklist head) {
	linklist p = head->next;
	while (p) {
		string s = p->data;
		cout << s << " -> ";
		p = p->next;
	}
	cout << endl;
}

void deleteAll(linklist head) {
	linklist p = head, r;
	while (p->next) {
		r = p->next;
		free(p);
		p = r;
	}
	free(p);
}

listnode* addNode(linklist head) {
	string ch;
	listnode* s = nullptr, * pp = nullptr;
	cout << "\nPlease input a new node data: ";
	cin >> ch;
	pp = locateNode(head, ch);
	if (pp == NULL) {
		s = new listnode;
		s->data = ch;
		s->next = head->next;
		head->next = s;
	}
	free(s);
	free(pp);
	return head;
}

int main() {
	string num, ch;
	linklist head;
	head = createList();

	printList(head);
	cout << "Delete node? (y/n):";
	cin >> num;
	if (num == "y" || num == "Y") {
		cout << "Please input delete data: ";
		cin >> ch;
		deleteList(head, ch);
		//printList(head);
	}
	cout << "Add node?(y/n):";
	cin >> num;
	if (num == "y" || num == "Y") {
		head = addNode(head);
	}
	//printList(head);
	system("pause");
	deleteAll(head);
	return 0;
}