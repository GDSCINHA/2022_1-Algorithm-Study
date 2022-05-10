#include <string>
#include <vector>
#include <utility>
using namespace std;

// [PGS] / 92334. 신고 결과 받기 / 레벨 1 / 45분

//오래 걸릴문제가 아닌데 너무 오래걸림... 구현할때 단순하게 생각하자
//그냥 2중백터로도 할수 있는건데 뭐 set쓰려다가 unordered_map쓰려다가 이상한짓 많이함

pair<string, string> split(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            return make_pair(s.substr(0, i), s.substr(i+1, s.size() - 1));
        }
    }
}

int find_idx(vector<string>v, string s) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == s)
            return i;
    }
    return -1;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    vector<int>tmp(id_list.size(), 0);
    vector<vector<int>>count(id_list.size(), tmp);

    vector<int>reportedCount(id_list.size(), 0);
    vector<int> answer(id_list.size(), 0);

    for (int i = 0; i < report.size(); i++) {
        pair<string, string>p = split(report[i]);
        int reporter = find_idx(id_list, p.first);
        int reported = find_idx(id_list, p.second);
        //최초 신고만 입력
        if (count[reporter][reported] == 0) {
            count[reporter][reported] = 1;
            reportedCount[reported]++;
        }
    }

    for (int i = 0; i < reportedCount.size(); i++) {
        //밴 맥이자
        if (reportedCount[i] >= k) {
            //메일 보내자
            for (int j = 0; j < reportedCount.size(); j++) {
                if (count[j][i] == 1) {
                    answer[j]++;
                }
            }
        }
    }


    return answer;
}