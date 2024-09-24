#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>

using namespace std;

vector<pair<int, int> > brackets;
set<string> ans;
stack<int> s;
string input;

void 	dfs(vector<pair<int, int> >::iterator idx)
{
	for (auto it = idx; it != brackets.end(); ++it)
	{
		auto [fr, ed] = *it;
		input[fr] = '@';
		input[ed] = '@';
		dfs(++it);
		string tmp = input;
		while (tmp.find("@") != string::npos)
			tmp.erase(tmp.find("@"), 1);
		ans.insert(tmp);
		input[fr] = '(';
		input[ed] = ')';
		--it;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> input;

	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == '(')
			s.push(i);
		else if (input[i] == ')' && s.size() >= 1)
		{
			int idx = s.top(); s.pop();
			brackets.push_back({idx, i});
		}
	}
	dfs(brackets.begin());
	for (auto it = ans.begin(); it != ans.end(); ++it)
		if (*it != input)
			cout << *it << "\n";

	return (0);
}