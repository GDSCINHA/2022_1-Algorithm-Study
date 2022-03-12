#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a = 1;
	int num = 0, sum = 0, bracket = 0;
	vector<string> signarr;
	vector<int> intarr;
	string str, sign;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {//잘라
		if (str[i] == '-') {
			signarr.push_back("-");
		}
		else if (str[i] == '+') {
			signarr.push_back("+");
		}
	}
	replace(str.begin(), str.end(), '+', ' ');
	replace(str.begin(), str.end(), '-', ' ');
	stringstream stream;
	stream.str(str);

	while (stream >> num) {
		intarr.push_back(num);
	}
	signarr.push_back("0");
	int i = 0;
	sum += intarr[i];
	intarr.erase(intarr.begin());

	while (signarr[i]!="0")
	{
		if (signarr[i] == "-") {
			bracket += intarr[i];
			i++;
			while (signarr[i] == "+") {
				bracket += intarr[i];
				i++;
			}
		}
		else
		{
			sum += intarr[i];
			i++;
		}
	}
	cout << sum - bracket;
}