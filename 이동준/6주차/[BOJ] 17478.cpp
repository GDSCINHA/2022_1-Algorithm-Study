#include <iostream>
using namespace std;

//[BOJ] 17478. 재귀함수가 뭔가요? / 실버 5 / 30분

void under(int n) {
	for (int i = 0; i < n; i++)
		cout << "____";
}

//아니 왜 북붙했는데 지멋대로 띄워쓰기 변함;; 띄어 쓰기 사라진거 찾느라 20분 걸림
void recur(int n, int now) {
	under(now - 1);
	cout << "\"재귀함수가 뭔가요?\""<<endl;
	under(now - 1);
	cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어."<<endl;
	under(now - 1);
	cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << endl;
	under(now - 1);
	cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << endl;

	if(n>now)
		recur(n, now + 1);
	if (n == now) {
		under(now);
		cout << "\"재귀함수가 뭔가요?\"" << endl;
		under(now);
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
		under(now);
		cout << "라고 답변하였지." << endl;
	}

	under(now - 1);
	cout << "라고 답변하였지." << endl;
}



int main() {
	int n; cin >> n;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
	recur(n, 1);
}