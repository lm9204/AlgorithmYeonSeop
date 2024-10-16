#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string str;

// 1. 여는괄호
// 1.1 닫는괄호
// 2. *, /
// 3. + -
// while top > cur pop()

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> str;
	stack<char> s;
	vector<char> result;

	for (char ch : str)
	{
		if (ch == '(')
			s.push(ch);
		else if (ch == ')')
		{
			while(!s.empty() && s.top() != '(')
			{
				result.push_back(s.top());
				s.pop();
			}
			if (!s.empty()) s.pop();
		}
		else if (ch == '*' || ch == '/')
		{
			while (!s.empty() && (s.top() == '*' || s.top() == '/'))
			{
				result.push_back(s.top());
				s.pop();
			}
			s.push(ch);
		}
		else if (ch == '+' || ch == '-')
		{
			while (!s.empty())
			{
				if (s.top() == '(') break;
				result.push_back(s.top());
				s.pop();
			}
			s.push(ch);
		}
		else
			result.push_back(ch);
	}

	while (!s.empty())
	{
		result.push_back(s.top());
		s.pop();
	}

	for (char ch : result)
		cout << ch;

	return (0);
}