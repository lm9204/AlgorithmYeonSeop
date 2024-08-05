#include <iostream>
#include <set>
#include <string>

using namespace std;

void	solution()
{
	int n;
	cin >> n;

	set<string> arr;

	for (int i = 0; i < n; ++i)
	{
		string num;
		cin >> num;
		arr.insert(num);
	}

	auto cur = arr.begin();
	auto next = ++(arr.begin());
	while (next != arr.end())
	{
		string target = *cur;
		string search = *next;
		int i = 0;
		for (; i < target.length(); ++i)
		{
			if (target[i] != search[i])
				break ;
		}
		if (target[i] == '\0')
		{
			cout << "NO" << endl;
			return;
		}
		cur++;
		next++;
	}
	cout << "YES" << endl;	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;

	cin >> t;
	for (int i = 0; i < t; ++i)
		solution();
}