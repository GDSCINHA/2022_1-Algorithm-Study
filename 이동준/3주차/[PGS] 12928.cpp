#include <string>
#include <vector>
#include <iostream>

using namespace std;

//[PGS] / 12928. 약수의 합 / 레벨 1 / 5분

int solution(int n) {
    int answer = 0;
    for(int i=1;i*i<=n;i++){
        if(i*i==n){
            if(n%i==0)
            answer+=i;
        }else{
            if(n%i==0)
            answer+=i+n/i;
        }
    }
    return answer;
}