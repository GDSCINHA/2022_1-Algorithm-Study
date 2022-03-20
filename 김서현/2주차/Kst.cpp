// [PGS] / K번째 수 / 레벨 1
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> temp;
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        
        for (int j = (commands[i][0] - 1); j <= (commands[i][1] - 1); j++) { temp.push_back[j]; }
        sort(temp.begin(),temp.end());
        int answer = temp[commands[i][3]];
    }

    return answer;
}

/*commands
   0-1-2
0  2 5 3
1  4 4 1
2  1 7 3*/