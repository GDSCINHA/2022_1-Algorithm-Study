//[BOJ] / 1541. 잃어버린 괄호 / 실버2 /2시간+@
//모르겠어서 코드분석해봤는데 모르겠다

/*
1. 선택 절차: 마이너스 사이의 식에 괄호 ex. 5-(9+8)-(9+4+2)-8
			마이너스가 나오면 (, 다음 자리에 마이너스가 있으면 
2. 적절성 검사: 선택된 해가 문제의 조건을 만족하는지 검사
3. 해답 검사: 값 확인
*/


// #include<iostream>
//#include<string>
//using namespace std;
//int main() {
//	string str;
//	cin >> str;
//
//	int answer = 0;
//	
//	for (int i = 0; i < str.size(); i++) {
//		if (str[i]=="-")////모르겠다
//	}
//	
//}

//stoi함수: string을 int로 바꿈

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;

    int result = 0;
    string num;
    bool isMinus = false;

    for (int i = 0; i <= input.size(); i++) {

        if (input[i] == '-' || input[i] == '+' || i == input.size()) {
            //연산자일 경우
            if (isMinus) {//-가 나오면 전부 - 처리
                result -= stoi(num);
                num = "";//초기화?? 왜하지
            }
            else {//+ or 끝dl 나오면 전부 +처리
                result += stoi(num);
                num = "";//?
            }
        }
        else {// 피연산자일 경우
            num += input[i];
        }

        if (input[i] == '-') {
            isMinus = true;
        }
    }

    cout << result;
}