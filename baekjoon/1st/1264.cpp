#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string buf;
	while (getline(cin, buf))
	{
		int count = 0;
		if (buf == "#")
			break;
		for (int i = 0; i < buf.size(); ++i)
		{
			if (buf[i] == 'a' || buf[i] == 'e' || buf[i] == 'i' || buf[i] == 'o' || buf[i] == 'u'
			|| buf[i] == 'A' || buf[i] == 'E' || buf[i] == 'I' || buf[i] == 'O' || buf[i] == 'U')
				count++;
		}
		cout << count << "\n";
	}

	return (0);
}