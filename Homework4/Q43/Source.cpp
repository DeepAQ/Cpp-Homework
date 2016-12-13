#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	while (true)
	{
		getline(cin, s);
		if (cin.eof())
		{
			break;
		}
		cout << s << endl;
		if (s.compare("T: meow") == 0)
		{
			cout << "J: escape" << endl << "O: what's up?" << endl;
		}
		else if (s.compare("T: chase") == 0)
		{
			cout << "J: run" << endl;
		}
		else if (s.compare("J: hide") == 0)
		{
			cout << "O: you piece of shit.";
			break;
		}
		else if (s.compare("T: catch") == 0)
		{
			cout << "J: zhi" << endl << "O: well done.";
			break;
		}
	}
	return 0;
}