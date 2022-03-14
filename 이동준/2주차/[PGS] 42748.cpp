#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// [PGS] / 42748. K번째 수 / 레벨 1 / 5분
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int here=0;here<commands.size();here++){
        int i=commands[here][0],j=commands[here][1],k=commands[here][2];
        vector<int>tmp;
        for(;i<=j;i++){
            tmp.push_back(array[i-1]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[k-1]);
    }
    return answer;
}