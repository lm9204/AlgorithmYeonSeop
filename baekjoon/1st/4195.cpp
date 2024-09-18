#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int ranks[200001];
int parent[200001];
int nfriend[200001];
map<string, int> m;

int find(int x)
{
	if (parent[x] != x)
		parent[x] = find(parent[x]);
	return parent[x];
}

void	unionParent(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
	{
		if (ranks[a] > ranks[b])
		{
			parent[b] = a;
			nfriend[a] += nfriend[b];
		}
		else if (ranks[a] < ranks[b])
		{
			parent[a] = b;
			nfriend[b] += nfriend[a];
		}
		else
		{
			parent[b] = a;
			nfriend[a] += nfriend[b];
			ranks[a]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t, count;
	map<string, int>::iterator it;

	cin >> t;
	while (t--)
	{
		m.clear();
		count = 0;
		for (int i = 0; i <= 200000; ++i)
		{
			ranks[i] = 0;
			parent[i] = i;
			nfriend[i] = 1;
		}

		string str1, str2;
		int f, a, b;
		cin >> f;

		for (int i = 0; i < f; ++i)
		{
			cin >> str1 >> str2;
			it = m.find(str1);
			if (it == m.end())
			{
				m[str1] = ++count;
				a = count;
			}
			else
				a = it->second;
			it = m.find(str2);
			if (it == m.end())
			{
				m[str2] = ++count;
				b = count;
			}
			else
				b = it->second;

			unionParent(a, b);
			int root = find(a);
			cout << nfriend[root] << "\n";
		}
	}

	return (0);
}