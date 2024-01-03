//经典走迷宫求从左上角走到右下角

#include<iostream>
#include<cstring>
using namespace std;

const int N = 101;
int m, n;
typedef pair<int, int> PII;
int g[N][N];
int d[N][N];
PII q[N * N];//点栈

int bfs() {
    int hh = 0, tt = 0;
    q[0] = { 0,0 };

    memset(d, -1, sizeof d);//sizeof d 是d数组整个的大小
    d[0][0] = 0;

    //向量：右，下，左，上
    int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

    while (hh <= tt) {
        auto t = q[hh++];
        for (int i = 0;i < 4;i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;
                q[++tt] = { x,y };
            }
        }
    }
    return d[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            cin >> g[i][j];
        }
    }
    cout << bfs();

}