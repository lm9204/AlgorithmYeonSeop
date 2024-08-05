#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int limit, speed;
	cin >> limit >> speed;

	if (limit >= speed)
		cout << "Congratulations, you are within the speed limit!" << "\n";
	else if (limit + 20 >= speed)
		cout << "You are speeding and your fine is $100.\n";
	else if (limit + 30 >= speed)
		cout << "You are speeding and your fine is $270.\n";
	else
		cout << "You are speeding and your fine is $500.\n";
	return (0);
}