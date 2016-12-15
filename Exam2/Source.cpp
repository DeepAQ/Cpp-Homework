#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class ParkingItem
{
public:
	int hour, min, wait_time, waited_time;
	string vehicle_id;
	double vehicle_prop;

	ParkingItem(int hour, int min, int wait_time, int waited_time, const string& vehicle_id, double vehicle_prop)
		: hour(hour),
		min(min),
		wait_time(wait_time),
		waited_time(waited_time),
		vehicle_id(vehicle_id),
		vehicle_prop(vehicle_prop)
	{
	}

	int get_time() const
	{
		return hour * 60 + min;
	}
};

class ParkingLot
{
	vector<ParkingItem> parking;
	vector<ParkingItem> waiting;
	double profit;
	int car_num;

public:
	ParkingLot()
		: profit(0),
		car_num(0)
	{
	}

	void add(int hour, int min, int wait_time, int waited_time, string& vehicle_id, double vehicle_prop)
	{
		ParkingItem item(hour, min, wait_time, waited_time, vehicle_id, vehicle_prop);

		if (car_num >= 30)
		{
			if (wait_time > 0)
			{
				auto i = 0;
				while (i < waiting.size() && waiting[i].get_time() <= item.get_time())
				{
					i++;
				}
				waiting.insert(waiting.begin() + i, item);
			}
		}
		else
		{
			auto i = 0;
			while (i < parking.size() && parking[i].get_time() >= item.get_time())
			{
				i++;
			}
			parking.insert(parking.begin() + i, item);
			car_num++;
		}

		check_waiting(hour, min);
	}

	void remove(string vehicle_id, int hour, int min)
	{
		for (auto& item : parking)
		{
			if (item.vehicle_id.compare(vehicle_id) == 0)
			{
				item.vehicle_id = "";
				auto time = hour * 60 + min - item.get_time() - item.waited_time;
				switch (vehicle_id[0])
				{
				case 'T':
					profit += 2 * time;
					break;
				case 'K':
					profit += 1.5 * time;
					break;
				case 'C':
					profit += time;
				}
				car_num--;
				break;
			}
		}

		check_waiting(hour, min);
	}

	void print()
	{
		cout << "==========" << endl;
		cout << profit << endl;
		for (auto& item : parking)
		{
			if (!item.vehicle_id.empty())
			{
				cout << item.vehicle_id << " " << item.wait_time << " " << item.vehicle_prop << endl;
			}
		}
		cout << "**********" << endl;
		for (auto& item : waiting)
		{
			if (!item.vehicle_id.empty())
			{
				cout << item.vehicle_id << " " << item.wait_time << " " << item.vehicle_prop << endl;
			}
		}
		cout << "==========" << endl;
	}

private:
	void check_waiting(int hour, int min)
	{
		for (auto& item : waiting)
		{
			if (!item.vehicle_id.empty())
			{
				if (item.get_time() + item.wait_time >= hour * 60 + min)
				{
					if (car_num < 30)
					{
						add(item.hour, item.min, item.wait_time, hour * 60 + min - item.get_time(), item.vehicle_id, item.vehicle_prop);
						item.vehicle_id = "";
					}
				}
				else
				{
					item.vehicle_id = "";
				}
			}
		}
	}
};

int main()
{
	ParkingLot park;
	string s;
	double d;
	char c;
	int i, j, k;
	while (true)
	{
		cin >> c;
		if (cin.eof())
		{
			break;
		}
		switch (c)
		{
		case 'A':
			cin >> s;
			i = (s[0] - '0') * 10 + s[1] - '0';
			j = (s[3] - '0') * 10 + s[4] - '0';
			cin >> k;
			cin >> s;
			cin >> d;
			park.add(i, j, k, 0, s, d);
			break;
		case 'D':
			cin >> s;
			i = (s[0] - '0') * 10 + s[1] - '0';
			j = (s[3] - '0') * 10 + s[4] - '0';
			cin >> s;
			park.remove(s, i, j);
			break;
		case 'Q':
			park.print();
			break;
		}
	}
	return 0;
}
