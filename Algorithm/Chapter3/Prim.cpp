//Prim算法求最小生成树(适合稠密图)

#include<iostream>
#include<cstring>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;
int n, m;
int dist[N];
int g[N][N];
bool st[N];

/*
    算法步骤：
    1.初始化距离数组为正无穷
    2.遍历n次，每次都寻找距离集合最近的点，并加入集合，更新距离数组
*/


//返回的是最小生成树所需建造道路的长度
int prim() {
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    //更新n次，第一次时因为只把一个点加入，并无边，所以距离为无穷，所以在判断是否存在最小生成树时，应该除去第一次遍历时的0号点
    for (int i = 0;i < n;i++) {
        int t = -1;
        for (int j = 1;j <= n;j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        if (i && dist[t] == INF) return INF;

        if (i) res += dist[t];//要先累加res再更新dist数组 //如果有自环，dist[t] 会变小，但因为它只用一次就被累加到res里，所以不影响其他地方的数据

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