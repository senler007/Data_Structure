//求1~n距离点1的最短路径

#include<iostream>
#include<cstring>

using namespace std;
const int N = 1001;

int n, m;
int dist[N];//distance
int g[N][N];//邻接矩阵
bool st[N];//最短距离是否确定

int dijstra() {
    //初始化距离表
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;


    for (int i = 0;i < n;i++) {
        int t = -1;
        //找出没有确定距离的点中已知距离最小的点
        for (int j = 1;j <= n;j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        st[t] = true;

        //更新最短距离
        for (int k = 1;k <= n;k++) {
            dist[k] = min(dist[k], dist[t] + g[t][k]);
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main() {
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    for (int i = 0;i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a][b] = min(g[a][b], c);
    }

    int t = dijstra();

    cout << t << endl;
}