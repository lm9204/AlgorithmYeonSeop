#include <iostream>
#include <algorithm>

using namespace std;

char alpha[16];
int l, c;

void	dfs(string str)
{
	if (str.length() == (size_t)l)
	{
		int v = 0, c = 0;
		for (int i = 0; i < l; ++i)
		{
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
				v++;
			else
				c++;
		}
		if (v > 0 && c > 1)
			cout << str << "\n";
		return ;
	}
	for (int i = 0; i < c; ++i)
	{
		if (str.find(alpha[i]) == string::npos && str.back() < alpha[i])
			dfs(str + alpha[i]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> l >> c;

	for (int i = 0; i < c; ++i)
		cin >> alpha[i];
	
	sort(alpha, alpha + c);
	dfs("");
	return (0);
}