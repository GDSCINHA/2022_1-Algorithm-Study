// [PGS] / K번째 수 / 레벨 1
 //성공!!
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> temp;
        for (int j = (commands[i][0] - 1); j <= (commands[i][1] - 1); j++) { 
            temp.push_back(array[j]);
        }
        sort(temp.begin(),temp.end());
        
        //int answer = temp[commands[i][3]];
        answer.push_back(temp[commands[i][2] - 1]);
    }

    return answer;
}
int main() {
    vector<int>v = { 1, 5, 2, 6, 3, 7, 4 }; //int형 백터 생성 후 1, 2, 3 으로 초기화
    vector<int> array;
    vector<vector<int>> commands = { {2, 5, 3} ,{4, 4, 1},{1, 7, 3} };
    solution(v, commands);

    return 0;
}
/*commands
   0-1-2
0  2 5 3
1  4 4 1
2  1 7 3*/