#include <iostream>

using namespace std;

int visit[26] = { 0 };
char str[1001];

void	dfs(string str, int x)
{
	if (x == str.size())
	{
		cout << str << "\n";
		return ;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (visit[i] > 0)
		{
			visit[i]--;
			str[x] = i + 'a';
			dfs(str, x + 1);
			visit[i]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	string x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		for (int j = 0; j < x.size(); ++j)
			visit[x[j] - 'a']++;
		dfs(x, 0);
		fill_n(visit, 26, 0);
	}
	return (0);
}