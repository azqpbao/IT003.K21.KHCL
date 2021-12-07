#include <iostream>
//using namespace std;
struct node {
	int val;
	node* next;
};
struct stack {
	node* top;
};
node* getNode(int x) {
	node* p = new node;
	if (p == NULL) {
		return NULL;
	}
	p->val = x;
	p->next = NULL;
	return p;
}
void init(stack& s) {
	s.top = NULL;
}
bool Is_Empty(stack s) {
	if (s.top == NULL) {
		/*cout << "EMPTY" << endl;*/
		return true;
	}
	return false;
}
void push(stack& s, int x) {
	node* p = getNode(x);
	if (p == NULL) {
		std::cout << "EMPTY" << std::endl;
		std::cout << "STACK: " << std::endl;
	}
	if (s.top == NULL) {
		s.top = p;
		std::cout << "pushed" << std::endl;
		std::cout << "STACK: ";
		for (node* it = s.top; it != NULL; it = it->next) {
			std::cout << it->val<< " ";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "pushed" << std::endl ;
		std::cout << "STACK: ";
		p->next = s.top;
		s.top = p;
		for (node* it = s.top; it != NULL; it = it->next) {
			std::cout << it->val << " ";
		}
		std::cout << std::endl;
	}
}
void pop(stack& s, int& x) {
	if (Is_Empty(s) == true) {
		std::cout << "EMPTY" << std::endl;
		std::cout << "STACK: " << std::endl;
	}
	else {
		x = s.top->val;
		auto p = s.top;
		s.top = p->next;
		std::cout << x << std::endl;
		std::cout << "STACK: ";
		for (node* it = s.top; it != NULL; it = it->next) {
			std::cout << it->val << " ";
		}
		std::cout << std::endl;

	}
}
void top(stack s, int& x) {
	if (Is_Empty(s) == true) {
		std::cout << "EMPTY" << std::endl;
		std::cout << "STACK: " << std::endl;
	}
	else {
		x = s.top->val;
		std::cout << x << std::endl;
		std::cout << "STACK: ";
		for (node* it = s.top; it != NULL; it = it->next) {
			std::cout << it->val << " ";
		}
		std::cout << std::endl;
	}
}
int main() {
	stack s; init(s);
	int  x, a;
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	do {
		std::cin >> x;
		switch (x) {
		case 1:
			std::cin >> a;
			push(s, a);
			break;
		case 2:
			pop(s, a);
			break;
		case 3:
			top(s, a);
			break;
		}
	} while (x != 4);
	return 0;
}