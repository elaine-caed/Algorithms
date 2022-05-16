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
void delete_key(comp** top, int N) 
{
	comp* q = *top;
	comp* prev = NULL;
	while (q != NULL) 
	{
		if (q->Data == N) 
		{
			if (q == *top) 
			{
				*top = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
			else
			{
				prev->next = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
		}
		prev = q;
		q = q->next;
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
	int k;
	double x;
	cout << "Enter number of elements: ";
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cout << "Enter element: ";
		cin >> x;
		push(&top, x);
	}
	print(top);
}
