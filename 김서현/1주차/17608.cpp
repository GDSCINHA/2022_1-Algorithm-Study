#include<iostream>
#include<list>
using namespace std;
//[BOJ] / 17680. 막대기 / 브론즈3 / 45분
//출력 값이 제대로 안나옴

int main() {
	
	int n = 0;
	cin >> n;
	int* arr = new int[n];

	int count = 1;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int top = arr[n - 1]; //맨 오른쪽 값을 top

	for (int i = 0; i < n-2; i++) { //0번째 부터 n-2 와 n-1을 비교
		
		if (arr[i] > top) {
			count++;
			top = arr[i]; 
		}

		
	}

	cout << count; 
	return 0;
	

}
