#include <iostream>
using namespace std;
const int N = 5;
struct Deque
{
	int data[N];
	int last;
};
void Creation(Deque* D)
{
	D->last = 0;
}
void AddL(Deque* D)
{
	if (D->last == N)
	{
		cout << "Deque is full" << endl;
	}
	int value;
	cout << "Value: "; cin >> value;
	for (int i = D->last; i > 0; i--)
		D->data[i] = D->data[i - 1];
	D->data[0] = value;
	D->last++;
	cout << "Element added" << endl;
}
void Check(Deque* D)
{
	int k = 0;
	if (D->last % 2 == 0)
	{
		for (int i = 0; i < D->last / 2; i++)
		{
			if (D->last = D->data[i])
			{
				D->last--;
				k++;
			}
		}
		if (k == D->last / 2)
			cout << "Palindrom" << endl;
		else
			cout << "Not palindrom" << endl;
	}
	else
	{
		for (int i = 0; i < (D->last--) / 2; i++)
		{
			if (D->last = D->data[i])
			{
				D->last--;
				k++;
			}
		}
		if (k == (D->last--) / 2)
			cout << "Palindrom" << endl;
		else
			cout << "Not palindrom" << endl;
	}
}
int main()
{
	Deque D;
	Creation(&D);
	for (int i = 0; i < 5; i++)
	{
		AddL(&D);
	}
	Check(&D);
	return 0;
}