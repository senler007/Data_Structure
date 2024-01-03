//树和图的深度优先搜索
//找树的重心

#include<iostream>
#include<cstring>
using namespace std;
const int N = 10010;

int ans = N;
int n;
int h[N], e[N], ne[N], idx;
bool st[N];//标记该点是否被搜到


//a->b (和拉链法的连接一样)
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

//u代表当前搜到的点的编号(返回以u为根的子树里点的数目)
int dfs(int u) {
    st[u] = true;

    int sum = 1, res = 0;

    for (int i = h[u];i != -1;i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int s = dfs(j);
            sum += s;
            res = max(res, s);
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 0;i < n - 1;i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans;
}