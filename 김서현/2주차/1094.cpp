//[BOJ] / 1094.막대기 / 실버 5 / 1시간

#include <iostream>
#include <bitset>
#include <string>
using namespace std;

//class Half{
//public:
//	int stick;
//	
//	int half(int n) {
//		int h1 = 64 / 2 ^ n;
//		return h1;
//	}
//};


int main() {
	int jm = 0;
	int count = 05;
	cin >> jm;

	bitset<7>bs(jm); 
	/*bitset: 10진수->2진수 변환
	64=100000(2)이므로 6자리 수*/

	string s = bs.to_string();
	//bs를 string으로

	cout << s <<endl;

	

	for (int i = 0; i < size(s); i++) {
		if (s[i] == 1) count++;
	}

	cout << count;
	return 0;

	 
	
	
}