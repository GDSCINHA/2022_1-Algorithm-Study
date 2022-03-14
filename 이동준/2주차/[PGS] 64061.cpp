#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
//[PGS] / 64061. 크레인 인형뽑기 게임 / 레벨 1 / 35분
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int>s;
    vector<int>top; //각줄의 가장 위에 있는 인형 인덱스 저장용
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[j][i]!=0){
                top.push_back(j);
                break;
            }
        }
        if(top.size()!=i+1)
            top.push_back(board.size()-1);
    }
    for(int i=0;i<moves.size();i++){
        int here=moves[i]-1;
        int tmp=board[top[here]][here]; //크레인으로 뽑은 인형 번호
        board[top[here]][here]=0;
        //cout<<tmp<<" ";
        if(tmp!=0){ //0인 경우 헛손질 한거
            if(top[here]<board.size()-1)
                top[here]++;
            
            s.push(tmp);
            
            while(s.size()>1){ //에니팡 구현
                int ttop=s.top();
                s.pop();
                if(s.top()==ttop){//팡
                    answer+=2;
                    s.pop();
                }else{
                    s.push(ttop);
                    break;
                }
            }
        }
    }
    return answer;
}