#include <iostream>
#include <string>

using namespace std;

int ans;

void	p(string str, int fr, int ed, int flag)
{
	while (fr < ed)
	{
		if (str[fr] == str[ed]) fr++, ed--;
		else
		{
			if (flag == 1)
			{
				if (ans == -1)
					ans = 2;
				return;
			}
			p(str, fr + 1, ed, flag + 1);
			p(str, fr, ed - 1, flag + 1);
			return ;
		}
	}
	ans = flag;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	string str;
	for (int i = 0; i < t; ++i)
	{
		cin >> str;
		ans = -1;
		p(str, 0, str.length() - 1, 0);
		cout << ans << endl;
	}
	return (0);
}