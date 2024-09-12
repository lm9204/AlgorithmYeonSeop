#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	bool flag = true;
	int cur = 0;

	while (flag && cur < s.size())
	{
		if (s[cur] == '0')
		{
			if (cur + 1 < s.size() && s[cur + 1] == '1')
				cur += 2;
			else
				flag = false;
		}
		else
		{
			int zero = 0;
			while (cur < s.size() && s[++cur] == '0') zero++;
			if (zero < 2 || cur == s.size()) flag = false;
			else
			{
				cur++;
				while (1)
				{
					if (cur >= s.size() || s[cur] == '0') break;
					if (cur + 2 < s.size() && s.substr(cur, 3) == "100") break;
					cur++;
				}
			}
		}
	}
	cout << (flag ? "SUBMARINE" : "NOISE");
	return (0);
}