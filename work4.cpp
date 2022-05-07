#include <iostream>
using namespace std;

struct stud
{
	double code = rand() % 100;
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
	cell* current;
	cell* count;
public:
	list() { header = NULL; tail = NULL; }
	void add();
	void print();
	void sort();
	void clear();
	void addlast(double k);
	bool remove(double k);
	void all();
	void swap(int a, int b);
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
	cell* count = 0;
	p = header;
	int k = 0;
	while (p != NULL)
	{
		k = k + 1;
		cout << p->data.code << "; ";
		p = p->next;
		count++;
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
void list::sort()
{
	cell* p = header;
	cell* p1 = header->next;
	cell* temp = new cell;
	while (p->next)
	{
		while (p1)
		{
			if ((p->data.code) > (p1->data.code))
			{
				temp->data.code = p1->data.code;
				p1->data.code = p->data.code;
				p->data.code = temp->data.code;
			}
			p1 = p1->next;
		}
		p = p->next;
		p1 = p->next;
	}
}
void list::clear()
{
	header = NULL;
	tail = NULL;
}
void list::addlast(double k)
{
	tail->next = new cell;
	tail = tail->next;
	tail->data.code = k;
	tail->next = NULL;
}
bool list::remove(double k)
{
	cell* previous = NULL;
	cell* current = header;
	while (current != NULL)
	{
		if (current->data.code == k)
		{
			if (previous != NULL)
			{
				previous->next = current->next;
				if (current->next == NULL)
				{
					tail = previous;
				}
				else
				{
					current->next->previous = previous;
				}
				count--;
			}
			else
			{
				if (count != 0)
				{
					
					header = header->next;
					count--;
					if (count == 0)
					{
						tail = NULL;
					}
					else
					{
						header->previous = NULL;
					}
				}
			}
			return true;
		}
			previous = current;
			current = current->next;
		}
	return false;
}
void list::all()
{
	cell* p = header;
	int k = 0;
	while (p != NULL)
	{
		k = k + 1;
		p = p->next;
	}
	if (k == 0) { cout << "empty list" << endl; }
	cout << "Total number of elements: " << k << endl;
}
void list::swap(int a, int b)
{

	cell* p = header;
	for (int i = 0; i < a; i++)
		p = p->next;
	cell* p1 = header;
	for (int i = 0; i < b; i++)
		p1 = p1->next;
    const int temp = p->data.code;
	p->data.code = p1->data.code;
	p1->data.code = temp;
}
int main()
{
	int T, m, p, h, y;
	cout << "Enter number of elements in list: ";
	cin >> T;
	list l;
	for (int i = 0; i < T; i++)
	{
		l.add();
	}
	cout << endl;
	cout << "Enter what should be done to the list (1-clear list, 2-add element in the end, 3-remove certain element, 4-find number of elements, 5-swap elements, 6-combine lists: ";
	cin >> m;
	switch (m) {
	case 1:
		l.clear();
		l.print();
		break;
	case 2:
		cout << "Enter number you want to add in the end: ";
		cin >> h;
		l.addlast(h);
		l.print();
		break;
	case 3:
		cout << "Enter number you want to remove: ";
		cin >> y;
		l.remove(y);
		l.print();
		break;
	case 4:
		l.all();
		break;
	case 5:
		int i, j;
		cout << "Enter position of numbers to swap: ";
		cin >> i >> j;
		l.swap(i, j);
		l.print();
		break;
	case 6:
		cout << "Enter number of elements in list: ";
		cin >> p;
		for (int i = 0; i < p; i++)
		{
			l.add();
		}
		cout << endl;
		l.combine();
		break;
	}
	return 0;
}
