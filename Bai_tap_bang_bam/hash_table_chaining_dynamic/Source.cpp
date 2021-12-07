
#include <iostream>
using namespace std;

struct node {
	int val;
	node* next;
};

struct list {
	node* head;
	node* tail;
};

struct hash_table {
	int m;
	list* T;
	int n;
};

void init_list(list& t) {
	t.head = t.tail = NULL;
}
node* get_node(int x) {
	node* p = new node;
	p->val = x;
	p->next = NULL;
	return p;
}
void add_tail(list& l, int x) {
	if (l.head == NULL) l.head = l.tail = get_node(x);
	else {
		node* p = get_node(x);
		l.tail->next = p;
		l.tail = p;
	}
}
void insert_in_list(hash_table& h, int x) {
	int k = x % h.m;
	add_tail(h.T[k], x);
}
void double_size_in_list(hash_table& T) {
	hash_table temp;
	temp.m = T.m * 2 + 1;
	temp.n = 0;

	temp.T = new list[temp.m];
	for (int i = 0; i < temp.m; i++) init_list(temp.T[i]);
	for (int i = 0; i < T.m; i++) {
		for (auto p = T.T[i].head; p != nullptr;) {
			auto q = p;
			insert_in_list(temp, p->val);
			p = p->next;
			delete q;
		}
	}
	delete T.T;
	T = temp;
}
node* find(list l, int x) {
	node* p = l.head;
	while (p != NULL) {
		if (p->val == x) return p;
		p = p->next;
	}
	return NULL;
}
void insert(hash_table& h, int x) {
	if (h.n >= h.m) double_size_in_list(h);
	int k = x % h.m;
	add_tail(h.T[k], x);
	h.n += 1;
}
/* ---------------------- */
void double_size(hash_table& T) {
	hash_table temp;
	temp.m = T.m * 2 + 1;
	temp.n = 0;

	temp.T = new list[temp.m];
	for (int i = 0; i < temp.m; i++) init_list(temp.T[i]);
	for (int i = 0; i < T.m; i++) {
		for (auto p = T.T[i].head; p != nullptr;) {
			auto q = p;
			insert(temp, p->val);
			p = p->next;
			delete q;
		}
	}
	delete T.T;
	T = temp;
}

bool search(hash_table T, int x) {
	int k = x % T.m;
	return find(T.T[k], x) != nullptr;
}

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	hash_table T;
	T.n = 0; T.m = 10;
	T.T = new list[T.m];
	for (int i = 0; i < T.m; i++) init_list(T.T[i]);



	int x, ms, i = 1;
	do {
		cin >> x;
		if (x == 0) break;
		cin >> ms;
		if (x == 1) insert(T, ms);
		else if (x == 2) cout << search(T, ms) << "\n";

		// cerr << " debug " << i++ << " " << x << " " << ms << endl;
	} while (x > 0);
}
