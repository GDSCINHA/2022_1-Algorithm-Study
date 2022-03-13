#include <iostream>
#include <string>

using namespace std;

int ans, idx;
bool pm, cur, sign;
string stack, cmd;

int main() {
    // 명령어 입력
	cin >> cmd;

    // 첫 숫자 입력을 위한 반복문
	while (idx < cmd.length()) {
		if (cmd[idx] == '-') {
			pm = false;
            cur = false;
            sign = true;
			break;
		}
		if (cmd[idx] == '+') {
			pm = true;
            cur = true;
            sign = true;
			break;
		}
		stack += cmd[idx];
		idx++;
	}
	idx++;
	ans = stoi(stack);
	stack = "";

    // 연산기호가 안들어오는 경우 중단
    if (!sign) {
        cout << ans;
        return 0;
    }

    // 연산 수행
	for (; idx < cmd.length(); idx++) {
		if (cmd[idx] == '-') {
			ans += (pm && cur) ? stoi(stack) : -(stoi(stack));
			pm = false;
            cur = false;
			stack = "";
		}

		else if (cmd[idx] == '+') {
			ans += (pm && cur) ? stoi(stack) : -(stoi(stack));
			pm = true;
			stack = "";
		}

		else {
			stack += cmd[idx];
		}
	}

    // 앞선 연산기호들과 관계없이 마지막 연산기호 기준으로 연산
    ans += (pm && cur) ? stoi(stack) : -stoi(stack);

    // 정답 출력
	cout << ans << "\n";

	return 0;
}