#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Item
{
public:
	bool isString;
	string content;
	Item(bool isString, string content) : isString(isString), content(content) {}
	Item(char c, string s) : isString(c == 'S'), content(s) {}
	Item operator +(Item &right) const
	{
		if (this->isString || right.isString)
		{
			return Item(true, this->content + right.content);
		}
		auto a = this->part();
		auto b = right.part();
		pair<int, int> c = {a.first + b.first, a.second + b.second};
		if (c.second == 0)
		{
			return Item(false, to_string(c.first));
		}
		if (c.second < 0)
		{
			return Item(false, to_string(c.first) + to_string(c.second) + "j");
		}
		return Item(false, to_string(c.first) + "+" + to_string(c.second) + "j");
	}
	pair<int, int> part() const
	{
		istringstream iss(this->content);
		auto a = 0, b = 0;
		iss >> a >> b;
		return {a, b};
	}
};

int main()
{
	int n;
	cin >> n;
	char c;
	string s;
	cin >> c;
	cin >> s;
	Item x(c, s);
	for (auto i = 1; i < n; ++i)
	{
		cin >> c;
		cin >> s;
		x = x + Item(c, s);
	}
	cout << x.content;
	return 0;
}