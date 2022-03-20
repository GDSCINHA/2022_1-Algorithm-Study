 //[PGS] / 크레인 인형뽑기 게임 / 레벨 1
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void crane() {

}

int main() {
    int array[5][5] = {
        {0,0,0,0,0},
        {0,0,1,0,3},
        {0,2,5,0,1},
        {4,2,4,4,2},
        {3,5,1,3,1}
    };

    //int moves = sizeof(array[0]) / sizeof(int); //2차원 배열의 열 개수
    int(*moves)[5] = array;
   
    crane(moves == 1);//???모르겠음

}

    
    //1 = [0][i]에 접근. for(int i=0; i<5; i++) if(array[0][i] ==! 0) 숫자 뽑아서 바구니에 담기
    //5 = [4][i] 
    //3 = [2][i]
    //5 = [4][i] 
    //1 = [0][i]
    //2 = [1][i]
    //1 = [0][i]에 접근
    //4 = [3][i]에 접근


  /*  int solution(vector<vector<int>> board, vector<int> moves) {
        int answer = 0;
        return answer;
    }*/