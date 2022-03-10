#include <iostream>
#include <vector>
#include <string>
using namespace std;

// [BOJ] / 1541. 잃어버린 괄호 / 실버2 / 35분

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);

    //+ 먼저 다 계산하고 - 나중에 다 계산??

    string s, tmp = ""; cin >> s;
    vector<int>num;
    vector<char>oper;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') {
            num.push_back(stoi(tmp));
            tmp = "";
            oper.push_back(s[i]);
        }else if (s[i] == '+') {
            num.push_back(stoi(tmp));
            tmp = "";
            oper.push_back(s[i]);
        }
        else {
            tmp += s[i];
        }
    }
    num.push_back(stoi(tmp));
    
    //int p = 0;
    //for (int i = 0; i < oper.size(); i++) {
    //    if (oper[i] == '+') {
    //        num[i + 1] += num[i];
    //        num[i] = -1;
    //    }
    //}
    //int ret = 0; bool first = true;
    //for (int i = 0; i < num.size(); i++) {
    //    if (num[i] != -1) {
    //        if (first) {
    //            first = false;
    //            ret = num[i];
    //        }
    //        else {
    //            ret -= num[i];
    //        }
    //    }
    //}

    int p = 0;
    for (int i = 0; i < oper.size(); i++) {
        if (oper[i] == '+') {
            //왜 안됨??? cannot seek vector iterator after end 뜸
            // erase 할때 문제 생기는거 같은데 

            //응 그냥 인덱스 잘못쓴거였어~~
            //근데 벡터에서 erase는 그닥 비추긴함.. 하나 지우고 뒤에거 한칸씩 다 땡겨야 되서 사이즈 크면 엄청 오래걸림
            //사이즈가 커지면 다른 자료구조를 쓰면 좋음 큐라던가..
            num[i - p] += num[i - p + 1];
            num.erase(num.begin() + (i - p + 1));
            p++;
        }
    }
    int ret = num[0];
    for (int i = 1; i < num.size(); i++) {
        if (num[i] != -1) {
            ret -= num[i];
        }
    }

    cout << ret;
}