//Kruskar算法求最小生成树(适合稀疏图)

//算法步骤：1.先将边按边权从小到大排序 2.枚举每条边ab，如果a,b不连通，将这条边加入集合 3.最后判断加集合操作的次数和n-1的大小来判断是否连通

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100010;
int n, m;
int p[N];//祖宗节点

struct Edge {
    int a, b, w;

    bool operator<  (const Edge& W)const {
        return w < W.w;
    }
}edges[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i].a = a, edges[i].b = b, edges[i].w = w;
    }

    sort(edges, edges + m);

    for (int i = 1;i <= n;i++) {
        p[i] = i;
    }

    int res = 0, cnt = 0;//res:存储权重，cnt：存储当前有多少条边加入集合

    //以边枚举，有边即可把两点加入一个集合中
    for (int i = 0;i < m;i++) {
        int a, b, w;
        a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1) cout << "impossible!";
    else cout << res;
}