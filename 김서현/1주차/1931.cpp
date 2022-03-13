//[BOJ] / 1931. 회의실 배정 / 실버2 / 2시간+@
//모르겠어서 코드 분석해봤는데 vetor의 first, second 개념이 이해가 안가요

/*그리디 알고리즘: 선택의 순간마다 당장 눈앞에 보이는
최적의 상황만을 쫓아 최종적인 해답에 도달하는 방법

1. 선택 절차: 현재 상태에서의 최적의 해답을 선택
2. 적절성 검사: 선택된 해가 문제의 조건을 만족하는지 검사
3. 해답 검사: 원래의 문제가 해결되었는지 검사하고,
	해결되지 않았다면 선택 절차로 돌아가 위 가정을 반복한다

조건
-선택 조건: 앞의 선택이 이후의 선택에 영향을 주지 않음
-최적 부분 구조 조건: 문제에 대한 최적해가 부분문제에 대해서도 역시 최적해임
*/

/*
1. 회의 종료시간이 제일 이른 회의 고르기
2. 두번째 종료시간과 비교
3. 반복
*/




//#include<iostream>
//using namespace std;
//int main() {
//
//	int n = 0; //회의의 최대 개수
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		int j = 0;
//		int k = 0;
//		cin >> j >> k;
//	}
//?????진짜 모르겠다



//vector: 동적할당, begin(), end()
// 
//알고리즘 헤더 > sort 할 때 사용



#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N, end, begin;

	vector<pair<int, int>> schedule;

	cin >> N;

	for (int i = 0; i < N; i++) //회의별로 시작시간, 종료시간 입력
	{
		cin >> begin >> end;
		schedule.push_back(make_pair(end, begin));
		//push_back: 벡터 끝에 요소를 추가할 때 사용
	}

	sort(schedule.begin(), schedule.end()); //순서대로 정렬

	int time = schedule[0].first; //첫 회의 시작시간을 time으로 초기화
	int count = 1;//회의 최대 개수 1로 초기화

	for (int i = 1; i < N; i++)
	{
		if (time <= schedule[i].second)
			//본 회의 시작 시간 <= 다음 회의 종료시간-????
			// first와 second가 각각 시작 시간과 종료시간을 말하는것 아닌가?
			// int time = schedule[0].second으로 바꾸고
			// time <= schedule[i].first가 맞는 것 아님??
		{
			count++;
			time = schedule[i].first;
		}
	}

	cout << count;
}
