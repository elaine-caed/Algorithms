#include <iostream>
using namespace std;

struct stud
{
	double code = rand()%10;
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
	void combine();
};
void list::add()
{
	cell* p;
	p = new cell;
	cout << p->data.code << "; ";
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
		cout << p->data.code << "; ";
		p = p->next;
	}
	if (k == 0) { cout << "empty list" << endl; }
	else { cout << "end of list" << endl; }
}
void list::combine()
{
	cell* p;
	cell* p1;
	p = header;
	int k = 0;
	while (p != NULL)
	{
		k = k + 1;
		cout << p->data.code << endl;
		p = p->next;
		if (tail = NULL)
		{
			header = p1; 
			tail = p;
			tail->next = p1;
		}
	}
	if (k == 0) { cout << "empty list" << endl; }
	else { cout << "end of list" << endl; }
}
int main()
{
	int T;
	cout << "Enter number of elements in each list: ";
	cin >> T;
	list l;
	for (int i = 0; i < T; i++)
	{
		l.add();
	}
	cout << endl;
	for (int i = 0; i < T; i++)
	{
		l.add();
	}
	cout << endl;
	l.combine();
	return 0;
}
