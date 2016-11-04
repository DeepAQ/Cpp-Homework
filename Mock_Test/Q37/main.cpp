/*
 * main.cpp
 *
 *  Created on: 2016年11月3日
 *      Author: adn55
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;

int main()
{
	char *line = new char[1024];
	vector<string> stack;
	vector<tuple<string, int, bool>> logs;
	int maxtime = 0;

	cin.getline(line, 1024);
	while (line[0]) {
		char *a = strtok(line, " ");
		string func(a);

        char *stime = strtok(NULL, " ");

        a = strtok(NULL, " ");
        string op(a);

        char *b = strtok(stime, ":");
        int time = atoi(b) * 3600;
        b = strtok(NULL, ":");
        time += atoi(b) * 60;
        b = strtok(NULL, ":");
        time += atoi(b);
        if (time < maxtime) {
        	cout << "Incorrect";
			return 0;
        } else {
        	maxtime = time;
        }

		if (op == string("START")) {
			stack.push_back(func);
			logs.push_back({func, time, false});
		} else if (op == string("END")) {
			if (stack.size() == 0 || *(stack.end()-1) != func) {
				cout << "Incorrect";
				return 0;
			}
			stack.pop_back();
			auto it = logs.end()-1;
			while (it >= logs.begin()) {
				if (get<0>(*it) == func && !get<2>(*it)) {
					int time0 = get<1>(*it);
					get<1>(*it) = time - time0;
					get<2>(*it) = true;
					break;
				}
				it--;
			}
		}
		cin.getline(line, 1024);
	}

	for (auto& log : logs) {
		int time = get<1>(log);
		int hour = time / 3600;
		int min = (time - hour*3600) / 60;
		int sec = time - hour*3600 - min*60;
		cout << get<0>(log) << " ";
		if (hour < 10) cout << '0';
		cout << hour << ":";
		if (min < 10) cout << '0';
		cout << min << ":";
		if (sec < 10) cout << '0';
		cout << sec << endl;
	}
	return 0;
}
