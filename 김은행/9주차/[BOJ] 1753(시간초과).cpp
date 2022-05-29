/*
다익스트라 알고리즘을 사용하지 않아 샘플 테스트케이스의 경우에는
정답을 얻을 수 있지만 채점서버의 큰 테스트케이스는 시간초과가
발생하는 것으로 추정됨
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;

int ** graph;
bool ** visited;
vector<pair<int, int>> edges;
vector<int> dis;
int V, E, K, maxD;

/* printGraph for debug */
void printGraph() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

void bankDFS(int s, int e, int d) {     // s = start, e = end
    cnt++;
    if (d > maxD) return ;

    if (s == e) {
        dis.push_back(d);
        return ;
    }

    for (int i = 0; i < V; i++) {
        if (graph[s][i] != 0 && !visited[s][i]) {
            visited[s][i] = true;
            bankDFS(i, e, d + graph[s][i]);
            visited[s][i] = false;
        }
    }
}


int main() {
    cin >> V >> E >> K;

    /* initialization graph */
    graph = new int* [V];
    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];

        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    /* initialization visited */
    visited = new bool* [V];
    for (int i = 0; i < V; i++) {
        visited[i] = new bool[V];

        for (int j = 0; j < V; j++) {
            visited[i][j] = false;
        }
    }

    /*       setting graph       */
    /* start = row, end = column */
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        maxD += w;
        graph[u - 1][v - 1] = w;
    }

//    printGraph();

    for (int i = 0; i < V; i++) {
        if (K - 1 ==  i) {
            cout << "0\n";
            continue;
        }

        dis.clear();
        bankDFS(K - 1, i, 0);

        if (dis.empty()) {
            cout << "INF\n";
        } else {
            sort(dis.begin(), dis.end());
            cout << dis[0] << "\n";
        }
    }

//    cout << "cnt = " << cnt << endl;

    return 0;
}