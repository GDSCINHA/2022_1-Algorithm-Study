//[PGS] / 12928. 약수의 합 / 레벨 1 / 10분

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i < n + 1; i++) {
        if (n % i == 0) {

            answer += i;
        }

    }

    return answer;
}