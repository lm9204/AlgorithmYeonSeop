#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int flag = 0;

void	insert(string s, string t, int A, int B)
{
	if (flag || (A == 0 && B == 0))
	{
		if (!flag && s == t)
			flag = 1;
		return;
	}

	if (A > 0 && t.back() == 'A')
	{
		t.pop_back();
		insert(s, t, A - 1, B);
		t.push_back('A');
	}
	if (B > 0 && t.front() == 'B')
	{
		reverse(t.begin(), t.end()); 
		t.pop_back();
		insert(s, t, A, B - 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s, t;
	cin >> s >> t;
	int A = 0, B = 0;

	for (int i = 0; i < t.length(); ++i)
	{
		if (t[i] == 'A')
			A++;
		else
			B++;
		if (i < s.length())
		{
			if (s[i] == 'A')
				A--;
			if (s[i] == 'B')
				B--;
		}
	}
	insert(s, t, A, B);
	cout << flag;
	return (0);
}