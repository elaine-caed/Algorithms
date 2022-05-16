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
bool Full(Deque* D)
{
	if (D->last == 0) return true;
	else return false;
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
	cout << endl << "Element added" << endl;
}
void AddR(Deque* D)
{
	if (D->last == N)
	{
		cout << "Deque is full" << endl; 
	}
	int value;
	cout << "Value: "; cin >> value;
	D->data[D->last++] = value;
	cout << endl << "Element added" << endl;
}
void DeleteL(Deque* D)
{
	for (int i = 0; i < D->last; i++)
		D->data[i] = D->data[i + 1]; D->last--;
}
void DeleteR(Deque* D)
{
	D->last--;
}
int OutputL(Deque* D)
{
	return D->data[0];
}
int OutputR(Deque* D)
{
	return D->data[D->last - 1];
}
int Size(Deque* D)
{
	return D->last;
}
int main()
{
	Deque D;
	Creation(&D);
	char number;
	do
	{
		cout << "1. Add element to the start" << endl;
		cout << "2. Add element in the end" << endl;
		cout << "3. Delete first element" << endl;
		cout << "4. Delete last element" << endl;
		cout << "5. Output first element" << endl;
		cout << "6. Output last element" << endl;
		cout << "7. Show size of deque" << endl;
		cout << "0. End" << endl;
		cout << "Enter number of command: "; cin >> number;
		switch (number)
		{
		case '1': AddL(&D);
			break;
		case '2': AddR(&D);
			break;
		case '3':
			if (Full(&D)) cout << endl << "Deque is empty" << endl;
			else
			{
				DeleteL(&D);
				cout << endl << "Element deleted" << endl;
			} break;
		case '4':
			if (Full(&D)) cout << endl << "Deque is empty" << endl;
			else
			{
				DeleteR(&D);
				cout << endl << "Element deleted" << endl;
			} break;
		case '5':
			if (Full(&D)) cout << endl << "Deque is empty" << endl;
			else cout << "First element: " << OutputL(&D) << endl;
			break;
		case '6':
			if (Full(&D)) cout << endl << "Deque is empty" << endl;
			else cout << "Last element: " << OutputR(&D) << endl;
			break;
		case '7':
			if (Full(&D)) cout << endl << "Deque is empty" << endl;
			else cout << "Size of deque: " << Size(&D) << endl;
			break;
		case '0': break;
		default: cout << endl << "Command not defined";
			break;
		}
	} while (number != '0');
	return 0;
}