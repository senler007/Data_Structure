//Prim算法求最小生成树(适合稠密图)

#include<iostream>
#include<cstring>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;
int n, m;
int dist[N];
int g[N][N];
bool st[N];


//返回的是最小生成树所需建造道路的长度
int prim() {
    memset(dist, 0x3f, sizeof dist);

    int res;
    for (int i = 0;i < n;i++) {
        int t = -1;
        for (int j = 1;j <= n;j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        if (i && dist[t] == INF) return INF;
        if (i) res += dist[t];

        for (int j = 1;j <= n;j++) dist[j] = min(dist[j], g[t][j]);

        st[t] = true;
    }

    return res;
}

int main() {
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    int t = prim();
    return t;
}