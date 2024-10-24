#include <iostream>
#include <stack>

using namespace std;

int f[1000001];
int a[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		f[a[i]]++;
	}

	stack<int> s;
	stack<int> ans;

	for (int i = n - 1; i >= 0; --i)
	{
		while (!s.empty() && f[a[s.top()]] <= f[a[i]])
			s.pop();

		if (s.empty())
			ans.push(-1);
		else
			ans.push(a[s.top()]);
		s.push(i);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << ans.top() << " ";
		ans.pop();
	}

	return (0);
}