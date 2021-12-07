#include <iostream>
#include <string>
using namespace std;
struct node {
	string val;
	node* next;
};
struct stack {
	node* head;
};
node* getnode(string x) {
	node* p = new node;
	p->val = x;
	p->next = NULL;
	return p;
}
void push(stack& s, string x) {
	//FILO => them dau
	node* p = getnode(x);
	if (s.head == NULL) s.head = p;
	else {
		p->next = s.head;
		s.head = p;
	}
}
void pop(stack& s) {
	// xoa dau tien
	if (s.head == NULL);
	else {
		auto p = s.head;
		s.head = p->next;
		delete p;
	}
}
void xu_ly(string a, stack &s) {
	string b;
	s.head = NULL;
	for (int i = 0; i < a.length(); i++) {
		b = "";
		while (i < a.length() && a[i] == '/') i++;
		while (i < a.length() && a[i] != '/') {
			b += a[i];
			i++;
		}
		if (b == ".." && s.head!=NULL) {
			pop(s);
		}
		else if ( b!= ".."&&b != "." && b != "")  {
			push(s, b);
		}
	}
}
void duong_dan(string a, stack &s) {
	xu_ly(a, s);
	stack r; r.head = NULL;
	string b="";
	while (s.head != NULL) {
		push(r, s.head->val);
		pop(s);
	}
	while (r.head != NULL) {
		b += "/" + r.head->val;
		pop(r);
	}
	cout << b << "\n";
}
int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	string a; stack s;
	do {
		cin >> a;
		if (a != "END") duong_dan(a, s);
	} while (a != "END");
	return 0;
}