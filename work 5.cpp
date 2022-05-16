/*
#include <iostream> 
#include <stack> 
using namespace std;
int priority(char oper)
{
	if (oper == '+' || oper == '-')
		return 1;
	if (oper == '*' || oper == '/')
		return 2;
}
int main() {
	string pharse, prn;
	cin >> pharse;
	stack<char> tmp;
	stack <double> result;
	for (int i = 0; i < pharse.size(); i++)
	{
		if (isdigit(pharse[i]))
			prn.push_back(pharse[i]);
		else
		{
			prn.push_back(' ');
			while (!tmp.empty() && priority(pharse[i]) <= priority(tmp.top()))
			{
				prn.push_back(tmp.top());
				tmp.pop();
			}
			tmp.push(pharse[i]);
		}
	}
	while (!tmp.empty())
	{
		prn.push_back(tmp.top());
		tmp.pop();
	}
	for (int i = 0; i < prn.size(); i++)
	{
		if (isdigit(prn[i]))
		{
			double num = double(prn[i] - '0');
			for (++i; isdigit(prn[i]) && i < prn.size(); i++)
			{
				num *= 10; num += double(prn[i] - '0');
			}
			result.push(num);
			if (prn[i] != ' ')
				i--;
		}
		else
		{
			double r = result.top();
			result.pop();
			double l = result.top();
			result.pop();
			switch (prn[i])
			{
			case'+':
				result.push(l + r);
				break;
			case'-':
				result.push(l - r);
				break;
			case'*':
				result.push(l * r);
				break;
			case'/':
				result.push(double(l / r));
				break;
			}
		}
	}
	cout << "=" << result.top() << endl;
}
*/
#include <iostream>
#include <stack>
using namespace std;

int steck(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

void ConvertToPostFix(string s)
{

	stack<char> st;

	string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			result += c;

		else if (c == '(')
			st.push('(');

		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop();
		}

		else {
			while (!st.empty()
				&& steck(s[i]) <= steck(st.top())) {
				if (c == '^' && st.top() == '^')
					break;
				else {
					result += st.top();
					st.pop();
				}
			}
			st.push(c);
		}
	}

	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}

int main()
{
	string exp = "(A-B-C)/D-E*F";
	ConvertToPostFix(exp);
	string exp1 = "(A+B)*C-(D+E)/F";
	ConvertToPostFix(exp1);
	string exp2 = "A/(B-C)+D*(E-F)";
	ConvertToPostFix(exp2);
	string exp3 = "(A*B+C)/D-F/E";
	ConvertToPostFix(exp3);
	return 0;
}