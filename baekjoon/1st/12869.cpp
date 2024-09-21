#include <iostream>
#include <algorithm>
#include <climits>
#include <tuple>
#include <queue>

using namespace std;

int n, minimum = INT_MAX;
int scv[4], hp[3] = {9, 3, 1};
// 0: 0 1 2
// 1: 0 2 1
// 2: 1 0 2
// 3: 1 2 0
// 4: 2 0 1
// 5: 2 1 0
int idx[6][3] = {
	{0, 1, 2}, {0, 2, 1},
	{1, 0, 2}, {1, 2, 0},
	{2, 0, 1}, {2, 1, 0}
};
bool visited[61][61][61];

void	bfs()
{
	queue<tuple<int, int, int, int> > q;

	int scv2 = (n >= 2) ? scv[1] : 0;
	int scv3 = (n == 3) ? scv[2] : 0;
	visited[scv[0]][scv2][scv3] = 0;
	auto d = make_tuple(scv[0], scv2, scv3, 0);
	q.push(d);

	while (!q.empty())
	{
		int sc1 = get<0>(q.front());
		int sc2 = get<1>(q.front());
		int sc3 = get<2>(q.front());
		int r = get<3>(q.front());
		q.pop();

		if (sc1 == 0 && sc2 == 0 && sc3 == 0)
		{
			minimum = min(minimum, r);
			continue;
		}

		for (int i = 0; i < 6; ++i)
		{
			int nsc1 = (sc1 - hp[idx[i][0]] < 0) ? 0 : sc1 - hp[idx[i][0]];
			int nsc2 = (sc2 - hp[idx[i][1]] < 0) ? 0 : sc2 - hp[idx[i][1]];
			int nsc3 = (sc3 - hp[idx[i][2]] < 0) ? 0 : sc3 - hp[idx[i][2]];

			if (!visited[nsc1][nsc2][nsc3])
			{
				visited[nsc1][nsc2][nsc3] = 1;
				q.push(make_tuple(nsc1, nsc2, nsc3, r + 1));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> scv[i];
	
	bfs();
	cout << minimum;

	return (0);
}