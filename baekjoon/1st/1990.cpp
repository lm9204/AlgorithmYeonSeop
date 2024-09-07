#include <iostream>
// #include <bitset>

using namespace std;

int a, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> a >> b;
	for (long i = a; i <= b && i <= 10000000; ++i)
	{
		bool flag = false;
		int reversed = 0, n = i;
		while (n > 0)
		{
			reversed = reversed * 10 + n % 10;
			n /= 10;
		}
		flag = i == reversed;
		if (flag)
		{
			for (long j = 2; j * j <= i; ++j)
			{
				if (i % j == 0)
				{
					flag = false;
					break;
				}
			}
			if (flag)
				cout << i << "\n";
		}
	}
	cout << -1 << "\n";
	return (0);
}

/** 
 * 내가 해결한 방법
 */
// const int N = 100000000;
// bitset<N + 1> p;


// int main()
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0), cout.tie(0);

// 	int a, b;
// 	cin >> a >> b;

// 	p.set();
// 	p[0] = p[1] = 0;

// 	for (int i = 2; i * i <= b; ++i)
// 		if (p[i])
// 			for (int j = i * i; j <= b; j += i)
// 				p[j] = 0;

// 	for (int i = a; i <= b; ++i)
// 	{
// 		if (p[i] && is_palindrome(i))
// 			cout << i << "\n";
// 	}
// 	cout << -1 << "\n";
// 	return (0);
// }