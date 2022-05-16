#include <iostream>
using namespace std;
struct comp
{
	int Data;
	comp* next;
};
void push(comp** top, int D)
{
	comp* q;
	q = new comp();
	q->Data = D;
	if (top == NULL)
	{
		*top = q;
	}
	else
	{
		q->next = *top;
		*top = q;
	}
}
void print(comp* top)
{
	comp* q = top;
	while (q) {
		printf_s("%i", q->Data);
		q = q->next;
	}
}
void main()
{
	comp* top = NULL;
	comp* top1 = NULL;
	int k;
	int x;
	cout << "Enter number of elements: ";
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cout << "Enter element: ";
		cin >> x;
		if (x % 2 == 0)
			push(&top, x);
		else
			push(&top1, x);
	}
	print(top);
	cout << endl;
	print(top1);
}