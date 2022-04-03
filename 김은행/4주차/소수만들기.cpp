#include <vector>
#include <iostream>
using namespace std;

bool isPrimeN(int num) {
    if (num < 2) 
        return false;
    
    for (int i = 2; i * i <= num; i++) { 
        if (num % i == 0) 
            return false; 
    }
    
    return true;
}

int solution(vector<int> nums) {
    int answer = -1;
    int cnt = 0;

    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                // cout << nums[i] << " " << nums[j] << " " << nums[k] << "\n";
                if (isPrimeN(nums[i] + nums[j] + nums[k]))
                    cnt++;
            }
        }
    }
    
    // cout << cnt;

    return cnt;
}