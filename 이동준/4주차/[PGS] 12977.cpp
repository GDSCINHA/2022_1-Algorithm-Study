#include <vector>
#include <iostream>
using namespace std;

// [PGS] / 12977. 소수 만들기 / level 1 / 5분

bool prime(int x){
    for(int i=2;i<x;i++){
        if(x%i==0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    for(int i=0;i<nums.size()-2;i++){
        for(int j=i+1;j<nums.size()-1;j++){
            for(int k=j+1;k<nums.size();k++){
                if(prime(nums[i]+nums[j]+nums[k]))
                    answer++;
            }
        }
    }

    return answer;
}