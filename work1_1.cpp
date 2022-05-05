#include <iostream>
using namespace std;
struct stud
{
	double a = rand()%10;
};
struct cell
{
	stud data;
	cell* previous;
	cell* next;
};
class list
{
public:
	cell* header;
	cell* tail;
public:
	list() { header = NULL; tail = NULL; }
	void add();
	void print();
	void find();
	void add_beg();
	void insert();
	void deletion();
	void combine();
};
void list::add()
{
	cell* p;
	p = new cell;
	cout << "input data" << endl;
	cin >> p->data.a;
	if (header == NULL)
	{
		header = p; tail = p; tail->next = NULL; header->previous = NULL;
	}
	else
	{
		p->next = NULL;
		p->previous = tail;
		tail->next = p;
		tail = p;
	}
}
void list::print()
{
	cell* p;
	p = header;
	int k = 0;
	while (p != NULL)
	{
		k = k + 1;
		cout << p->data.a << "  " << endl;
		p = p->next;
	}
	if (k == 0) { cout << "empty list" << endl; }
	else { cout << "end of list" << endl; }
}
void list::find()
{
	cell* p;
	p = header;
	while (p != NULL)
	{
		if (p == tail) { p; }
		p = p->next;
	}
}
void list::insert()
{
	cell* p;
	p = header;
	p->data.a = tail->data.a;
	if (p == 0) 
	{
		p->next = 0;
		header = p;
		return;
	}
	if (p->data.a >= p->data.a)
	{
		p->next = p;
		header = p;
		return;
	}
	cell* t1 = p->next;
	while (t1)
	{
		if (p->data.a < p->data.a && p->data.a <= t1->data.a)
		{ 
			p->next = p;
			p->next = t1;
			return;
		}
		p = t1;
		t1 = t1->next;
	}
	p->next = p;
	p->next = 0;
}
void list::deletion()
{
	cell* p;
	p = header;
	if (header == NULL) 
	{
		return;
	}
	if (p->data.a == tail->data.a)
	{
		header = p->next;
		delete p;
		return;
	}
	cell* t1 = p->next;
	while (t1)
	{
		if (t1->data.a == tail->data.a)
		{
			p->next = t1->next;
			delete t1;
			return;
		}
		p = t1;
		t1 = t1->next;
	}
}
int main()
{
	list l;
	l.add();
	l.print();
	l.find();
	l.insert();
	l.deletion();
	return 0;
}