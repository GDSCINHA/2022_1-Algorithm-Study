#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    // 모든 두 합 계산
    for (int i = 0; i < numbers.size() - 1; i ++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            int new_num = numbers[i] + numbers[j];
            
            // 중복성 검토
            if (find(answer.begin(), answer.end(), new_num) == answer.end())
                answer.push_back(new_num);
        }
    }
    
    // 정렬 수행
    sort(answer.begin(), answer.end());
    
    return answer;
}