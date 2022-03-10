#include <iostream>
using namespace std;

class Stick
{
public:
	int arr[64];
	int num = 2;
	Stick()
	{
		for (int i = 0; i < 64; i++) {
			arr[i] = 0;
		}
		arr[0] = 64;
	}
	int sum(int _num)
	{
		int count = 0;
		for (int i = 0; i < _num; i++) {
			count += arr[i];
		}
		return count;
	}
	int number() {
		int count = 0;
		for (int i = 0; i < 64; i++) {
			if (arr[i] != 0) {
				count++;
			}
		}
		return count;
	}

	int cut(int _X)
	{
		int key = 0;
		while (sum(num)!=_X)
		{
			for (int i = 0; i < 64; i++)
			{
				arr[i] = (arr[i] / 2);
				arr[i + 1] = arr[i];

				if ((sum(num)-arr[i]) > _X) 
				{
					arr[i] = 0;
				}
				if ((sum(num) - arr[i]) == _X)
				{
					arr[i] = 0;
					key = 1;
					break;
				}
			    num++;
			}
		}
		return number();
	}
};

int main()
{
	int X;
	cin >> X;
	if (X == 64)
	{
		cout << "1";
	}
	else
	{
		Stick stick;
		cout << stick.cut(X);
	}
}