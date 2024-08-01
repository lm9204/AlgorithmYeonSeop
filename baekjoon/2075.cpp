#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int> > pq;
	int num;
	for (int i = 0; i < n * n; ++i)
	{
		cin >> num;
		pq.push(num);
		if (pq.size() > n)
			pq.pop();
	}

	cout << pq.top() << "\n";
	return (0);
}


// 원래 내 풀
// #include <iostream>
// #include <set>

// using namespace std;

// set<int> arr;

// int main()
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0), cout.tie(0);

// 	int n, v;
// 	cin >> n;

// 	set<int>::iterator fr;

// 	for (int i = 0; i < n * n; ++i)
// 	{
// 		cin >> v;
// 		fr = arr.begin();
// 		if (i < n)
// 			arr.insert(v);
// 		else if (*fr < v)
// 		{
// 			arr.erase(fr);
// 			arr.insert(v);
// 		}
// 	}

// 	set<int>::iterator it = arr.begin();
// 	cout << *it << "\n";
// }