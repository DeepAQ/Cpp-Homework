#include <iostream>

using namespace std;

class DrinkOverflowException : public exception {};

class DrinkNotFoundException : public exception {};

class DrinkHouse
{
private:
	int* drinks;
	DrinkHouse()
	{
		drinks = new int[4] {0, 0, 0, 0};
	}
public:
	static DrinkHouse& getInstance()
	{
		static DrinkHouse drink_house;
		return drink_house;
	}
	void add(int type, int count) const
	{
		auto sum = drinks[0] + drinks[1] + drinks[2] + drinks[3];
		if (sum + count > 10)
		{
			throw DrinkOverflowException();
		}
		drinks[type - 1] += count;
	}
	int getCount(int type) const
	{
		return drinks[type - 1];
	}
};

class Drink
{
public:
	virtual void buy() = 0;
protected:
	~Drink() {}
};

class Coffee : public Drink
{
public:
	void buy() override
	{
		DrinkHouse::getInstance().add(1, -1);
		cout << "coffee:5" << endl;
	}
};

class Milk : public Drink
{
public:
	void buy() override
	{
		DrinkHouse::getInstance().add(2, -1);
		cout << "milk:4" << endl;
	}
};

class Tea : public Drink
{
public:
	void buy() override
	{
		DrinkHouse::getInstance().add(3, -1);
		cout << "tea:3" << endl;
	}
};

class Beer : public Drink
{
public:
	void buy() override
	{
		DrinkHouse::getInstance().add(4, -1);
		cout << "beer:6" << endl;
	}
};

class DrinkFactory
{
public:
	static Drink* getDrink(int type)
	{
		if (DrinkHouse::getInstance().getCount(type) <= 0)
		{
			throw DrinkNotFoundException();
		}
		switch (type)
		{
		case 1:
			return new Coffee;
		case 2:
			return new Milk;
		case 3:
			return new Tea;
		case 4:
			return new Beer;
		}
		return nullptr;
	}
};

int main()
{
	int x = 0, y, z;
	while (x < 3)
	{
		cin >> x;
		switch (x)
		{
		case 1:
			cin >> y >> z;
			try
			{
				DrinkHouse::getInstance().add(y, z);
			}
			catch (DrinkOverflowException)
			{
				cout << "DrinkOverflow" << endl;
			}
			break;
		case 2:
			cin >> y;
			try
			{
				DrinkFactory::getDrink(y)->buy();
			}
			catch (DrinkNotFoundException)
			{
				switch (y)
				{
				case 1:
					cout << "coffee";
					break;
				case 2:
					cout << "milk";
					break;
				case 3:
					cout << "tea";
					break;
				case 4:
					cout << "beer";
				}
				cout << " is not found" << endl;
			}
		}
	}
	return 0;
}
