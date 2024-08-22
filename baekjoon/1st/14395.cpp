#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

#define ll long long

ll s, t;
unordered_set<ll> v;
queue<pair<ll, string> > q;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> s >> t;
	if (s == t)
		cout << 0;
	else
	{	
		q.push({ s, "" });
		while (!q.empty())
		{
			ll cur = q.front().first;
			string str = q.front().second;
			q.pop();

			if (t == cur)
			{
				cout << str;
				return (0);
			}

			ll next = cur * cur;
			if (v.find(next) == v.end())
			{
				v.insert(next);
				q.push({ next, str + "*"});
			}

			next = cur + cur;
			if (v.find(next) == v.end())
			{
				v.insert(next);
				q.push({ next, str + "+"});
			}

			next = cur - cur;
			if (v.find(next) == v.end())
			{
				v.insert(next);
				q.push({ next, str + "-"});
			}

			if (cur == 0) continue;
			next = cur / cur;
			if (v.find(next) == v.end())
			{
				v.insert(next);
				q.push({ next, str + "/"});
			}
		}
		cout << -1;
	}
	return (0);
}