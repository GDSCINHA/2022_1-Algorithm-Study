//[BOJ] / 1094.막대기 / 실버 5 / 1시간
//성공!!

#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main() {
	int jm = 0;
	int count = 0;
	cin >> jm;

	bitset<7>bs(jm); 
	/*bitset: 10진수->2진수 변환
	64=100000(2)이므로 6자리 수*/

	string s = bs.to_string();
	//bs를 string으로

	


	for (int i = 0; i < s.size(); i++) {

		if (s[i] == '1') { 
			count++; }
	}

	cout << count;
	return 0;

	 
	
	
}