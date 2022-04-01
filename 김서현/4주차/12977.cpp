//[PGS] / 12977. 소수 만들기 / 레벨 1 / 1시간

#include <vector>
#include <iostream>
using namespace std;

bool prime(int s) {
    //주석쳤더니 바로 정답 나오네요;;이거에 30분 쏟은듯
    // 3개 합이니 당연히 2보다 클텐데 왜 생각 못했지
    //if (s < 2) return false; //소수는 0,1이 아니다
    
    for (int i = 2; i <= s / 2; i++) {
        if (s % i == 0)return false;
    }
   
    return true;
}


int solution(vector<int> nums) {
    int answer = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if (prime(sum)==true) answer++;

                }
            }
        }

    return answer;
    }