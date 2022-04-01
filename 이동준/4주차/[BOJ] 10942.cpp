#include <iostream>
#include <vector>

using namespace std;
// [BOJ] / 10942. 팰린드롬? / 골드 3 / 1시간 고민하다가 답지보고 2시간 더걸림..
//답지 링크
//https://cocoon1787.tistory.com/326
//https://4z7l.github.io/2021/04/07/algorithms-boj-10942.html
//문제 풀면서 그린 그림
//https://ibb.co/TYQNHrT

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n;
	vector<int> total;
	vector<int> idx; //해당 숫자가 끝나는 지점의 스트링 기준 인덱스
	for (int i = 0; i < n; i++) {
		int s; cin >> s;
		total.push_back(s);
	}
	
	vector<vector<int>>dp;
	for (int x = 0; x < total.size(); x++) {
		vector<int>tmp(total.size() - x, 0);
		dp.push_back(tmp);
		int y = 0;
		dp[x][y] = 1; //길이 1이니까 무적권 회문임
		//대각선 올라가기 (홀)
		int herex = x - 1, herey = y + 2;
		while (herex >= 0 && herey < dp[herex].size()) {
			if (dp[herex + 1][herey - 2] && total[herex] == total[herex + herey]) {//회문인 경우는 전단계에서 회문이고 추가 맨끝 검사 했을때 같은 경우만 있늠
				dp[herex][herey] = 1;
			}
			herex--; herey += 2;
		}

		if (x < total.size() - 1) {//마지막줄이면 오른쪽으로 안가기
			y++;
			herex = x, herey = y;
			if(total[herex] == total[herex + herey])
				dp[herex][herey] = 1;
			//대각선 올라가기 (짝)
			herex = x - 1, herey = y + 2;
			while (herex >= 0 && herey < dp[herex].size()) {
				if (dp[herex + 1][herey - 2] && total[herex] == total[herex + herey]) {//회문인 경우는 전단계에서 회문이고 추가 맨끝 검사 했을때 같은 경우만 있늠
					dp[herex][herey] = 1;
				}
				herex--; herey += 2;
			}
		}
	}



	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e; cin >> s >> e;
		cout << dp[s - 1][e - s] << "\n";
	}
}

/* 삽질한 흔적...

삽질 3줄 요약
1. 처음엔 dp로 안하고 그냥 모든 질문에 회문 검사돌림. 당연히 시간초과
2. 답지 보고 감 잡아서 dp로 풀어봄. 답지랑 일부러 조금 다르게 구현함
3. 근데도 오답 나와서 보니까 내가 문제를 좀 다르게 이해한거 같은데 아니 아무리 생각해도 내가 맞는거 같은데 왜맞틀;;;

내가 이해한거
123 3 321 들어오고 1,3 질문 하면 회문인거 아님??? 
이렇게 생각하고 구현 계속 해서 ㅈㄴ 복잡하게 했는데... (다 스트링으로 받아서 한글자 한글자 비교해서 인덱스도 따로줌..) 왜맞틀...
문제 의도
123 3 123 들어오면 1,3 질문했을때 회문 맞음

인덱스를 좀 희한하게 줘서 헷갈리고 시간 더 쓴듯..
걍 int [2000][2000] 짜리 만들어서 했으면 벡터도 안쓰고 인덱스 꼬아서 쓸 필요 없는데 
처음 문제 이해할때 한글자 한글자 보는걸로 해서 일부러 벡터씀

#include <iostream>
#include <vector>

using namespace std;
// [BOJ] / 10942. 팰린드롬? / 골드 3 / 분

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n;
	//vector<string>v;
	string total = "";
	vector<int> idx; //해당 숫자가 끝나는 지점의 스트링 기준 인덱스
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		//v.push_back(s);
		total += s;
		if (i == 0)
			idx.push_back(s.size() - 1);
		else
			idx.push_back(idx[idx.size() - 1] + s.size());

	}

	//결국 답지를 보았읍니다.. 고민하던 방법인데 시간초과 해결 못할줄 알고 시도 안했음 (대충 봤을때 시간복잡도가 늘어난줄암)
	//근데 간단하게 생각하면 이게 해결방법이긴함
	//최악의 경우를 고려해보자 -> n짜리 회문을 m번 계속 검사 o(mn)
	//근데 그냥 다 해보는거 -> o(n^2)이긴 한데
	//n이 m보다 월등히 작기 때문에 시간 확 줄어듬
	//
	//아오 햇갈리네 일어나서 다시 함....
	//그니까 121을 검사해서 이미 회문 확인한거면 91219 를 확인할때 시작,끝만 확인하면 된다를 사용하자라는 느낌?

	//그냥 모든 경우 다 회문 검사 하기고 저장??
	//멍청하게 다 하는 방법..
	//vector<vector<int>>dp;
	//for (int i = 0; i < total.size(); i++) {
	//	vector<int>tmp;
	//	for (int j = i; j < total.size(); j++) {
	//		bool isP = true;
	//		for (int x = 0; x < (j - i + 1) / 2; x++) {
	//			if (total[x] != total[j - i + 1 - x - 1]) {
	//				isP = false;
	//				break;
	//			}
	//		}
	//		tmp.push_back(isP);
	//	}
	//	dp.push_back(tmp);
	//}

	//dp 다시 제대로
	// 대충 점화식
	// dp[x][y]=dp[x-1][y-1]에서 양끝 확인
	// 문자열 길이 홀수 짝수 일때
	vector<vector<int>>dp;
	for (int x = 0; x < total.size(); x++) {
		vector<int>tmp(total.size() - x, 0);
		dp.push_back(tmp);
		int y = 0;
		dp[x][y] = 1; //길이 1이니까 무적권 회문임
		//대각선 올라가기 (홀)
		int herex = x - 1, herey = y + 2;
		while (herex >= 0 && herey < dp[herex].size()) {
			if (dp[herex + 1][herey - 2] && total[herex] == total[herex + herey]) {//회문인 경우는 전단계에서 회문이고 추가 맨끝 검사 했을때 같은 경우만 있늠
				dp[herex][herey] = 1;
			}
			herex--; herey += 2;
		}

		if (x < total.size() - 1) {//마지막줄이면 오른쪽으로 안가기
			y++;
			herex = x, herey = y;
			if(total[herex] == total[herex + herey])
				dp[herex][herey] = 1;
			//대각선 올라가기 (짝)
			herex = x - 1, herey = y + 2;
			while (herex >= 0 && herey < dp[herex].size()) {
				if (dp[herex + 1][herey - 2] && total[herex] == total[herex + herey]) {//회문인 경우는 전단계에서 회문이고 추가 맨끝 검사 했을때 같은 경우만 있늠
					dp[herex][herey] = 1;
				}
				herex--; herey += 2;
			}
		}
	}



	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e; cin >> s >> e;
		//string tmp = "";

		//이부분은 줄일수 있음 o(1)로
		//for (; s <= e; s++) {
		//	tmp += v[s - 1];
		//}
		int sidx, eidx;
		if (s == 1)
		sidx = 0;
		else
		sidx = idx[s - 2] + 1;
		eidx = idx[e - 1];
		//tmp = total.substr(sidx, eidx - sidx + 1);

		//팰린드롬 확인
		//bool isP = true;
		//for (int x = 0; x < (eidx - sidx + 1) / 2; x++) {
		//	if (total[x] != total[eidx - sidx + 1 - x - 1]) {
		//		isP = false;
		//		break;
		//	}
		//}
		//if (isP)
		//	cout << "1\n";
		//else
		//	cout << "0\n";

		cout << dp[sidx][eidx - sidx] << "\n";
	}
}
*/
