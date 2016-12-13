#include <iostream>
#include <cmath>

using namespace std;

class Point
{
public:
	Point(int x, int y) : x(x), y(y) {}
	void Output() const
	{
		cout << "(" << x << "," << y << ")";
	}
	double Distance(Point& p) const
	{
		return round(sqrt(pow(p.x - x, 2) + pow(p.y - y, 2)) * 100.0) / 100.0;
	}
private:
	int x, y;
};

class Triangle
{
public:
	Triangle(Point &a, Point &b, Point &c) : a(a), b(b), c(c) {}
	double Circum()
	{
		auto ab = a.Distance(b), bc = b.Distance(c), ac = a.Distance(c);
		return (ab + bc < ac || ab + ac < bc || bc + ac < ab) ? 0 : (ab + bc + ac);
	}
private:
	Point a, b, c;
};

int main()
{
	int x, y;
	cin >> x >> y;
	Point a(x, y);
	cin >> x >> y;
	Point b(x, y);
	cin >> x >> y;
	Point c(x, y);

	a.Output();
	cout << " ";
	b.Output();
	cout << " ";
	c.Output();
	cout << " ";

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << a.Distance(b) << " " << a.Distance(c) << " " << b.Distance(c) << " ";

	Triangle t(a, b, c);
	auto z = t.Circum();
	z == 0 ? cout << 0 : cout << z;

	return 0;
}