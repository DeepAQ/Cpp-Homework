#include <iostream>

using namespace std;

int main()
{
	auto speed = 0;
	int x;
	char c, d;
	cin >> x;
	speed += 5 - x;
	cin >> c;
	switch (c)
	{
	case 's':
		speed += 1;
		break;
	case 'm':
		speed += 3;
		break;
	case 'l':
		speed += 8;
	}
	cin >> c >> d;
	switch (c)
	{
	case 'J':
		speed += d == 'P' ? 10 : 7;
		break;
	case 'Y':
		speed += d == 'P' ? 9 : 8;
	}
	cout << speed;
	return 0;
}
