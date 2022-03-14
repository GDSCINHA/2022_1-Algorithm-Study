#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int answer,k;
stack<int> stack_;
int solution(vector<vector<int>> board, vector<int> moves) {
    
    for (int i = 0; i < moves.size(); i++){
        k = moves[i] - 1;
        for (int j = 0; j < board.size(); j++) {
            if (board[j][k] != 0){
                if ( !stack_.empty()&&(stack_.top() == board[j][k]) ) {
                    stack_.pop();
                    answer += 2;
                }
                else {
                    stack_.push(board[j][k]);
                }
                board[j][k] = 0;
                break;
            }
        }
    }
    return answer;
}