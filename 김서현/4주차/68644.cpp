//[PGS] / 68644. 두 개 뽑아서 더하기 / 레벨 1 / 30분
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;

	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i+1; j < numbers.size(); j++) {
			answer.push_back(numbers[i] + numbers[j]);
			
		}
	}
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()),answer.end());//중복 값 삭제 코드

	return answer;
}