#include <iostream>
#include <string>
using namespace std;
struct node {
	char val;
	node* next;
};
struct stack {
	node* head;
};
node* getNode(char x) {
	node* p = new node;
	if (p == NULL) return NULL;
	p->val = x;
	p->next = NULL;
	return p;
}
void init(stack& s) {
	s.head = NULL;
}
bool  Is_Empty(stack s) {
	if (s.head == NULL) return true;
	return false;
}
void push(stack& s, char x) {
	node* p = getNode(x);
	if (s.head == NULL) s.head = p;
	else {
		p->next = s.head;
		s.head = p;
	}
}
void pop(stack& s) {
	if (s.head == NULL);
	else {
		auto p = s.head;
		s.head = p->next;
		delete p;
	}
}
char top(stack s) {
	if (s.head == NULL) return NULL;
	else {
		return s.head->val;
	}
}
bool Kiem_Tra_Dau_Ngoac(string a, stack s) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '[' || a[i] == '(' || a[i] == '{') {
			push(s, a[i]);
		}
		else {
			if (Is_Empty(s) == 1) return false;
			else {
				if (a[i] == ']') {
					if (top(s) != '[') return false;
				}
				if (a[i] == ')') {
					if (top(s) != '(') return false;
				}
				if (a[i] == '}') {
					if (top(s) != '{')return false;
				}
				pop(s);
			}
		}
	}
	if (Is_Empty(s) == 1) return true;
	return false;
}
int main() {
	string a;
	stack s; init(s);
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	do {
		cin >> a;
		if (a != "END") {
			if (Kiem_Tra_Dau_Ngoac(a, s) == 1) cout << "TRUE" << endl;
			else cout << "FALSE" << endl;
		}
	} while (a != "END");
	return 0;
}