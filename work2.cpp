#include <iostream>
using namespace std;
struct stud
{
	int code;
	char surname[20];
	int baggage_number;
	double baggage_weight;
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
};
void list::add()
{
	cell* p;
	p = new cell;
	cout << "input code" << endl;
	cin >> p->data.code;
	cout << "input surname" << endl;
	cin >> p->data.surname;
	cout << "input number of baggage" << endl;
	cin >> p->data.baggage_number;
	cout << "input weight of baggage" << endl;
	cin >> p->data.baggage_weight;
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
		cout << p->data.code << "  " << p->data.surname << "  " << p->data.baggage_number << "  " << p->data.baggage_weight << endl;
		p = p->next;
	}
	if (k == 0) { cout << "empty list" << endl; }
	else { cout << "end of list" << endl; }
}
int main()
{
	int T;
	cout << "Enter number of passangers: ";
	cin >> T;
	list l;
	for (int i = 0; i < T; i++)
	{
		l.add();
		cout << endl;
	}
	l.print();
	return 0;
}