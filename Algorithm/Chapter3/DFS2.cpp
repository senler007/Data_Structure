//经典八皇后（按行枚举）

#include<iostream>
using namespace std;

int n;
const int N = 20;//该n需要2倍行数，因为映射问题
char g[N][N];
bool col[N], diagonal[N], back_diagonal[N];

void dfs(int u) {
    if (n == u) {
        for (int i = 0;i < n;i++) puts(g[i]);
        puts("");
        return;
    }

    for (int i = 0;i < n;i++) {

        if (!col[i] && !diagonal[i + u]/*映射到截距*/ && !back_diagonal[n + i - u]/*映射到截距+n*/) {
            g[u][i] = 'Q';
            col[i] = diagonal[i + u] = back_diagonal[n + i - u] = true;

            dfs(u + 1);

            col[i] = diagonal[i + u] = back_diagonal[n + i - u] = false;
            g[u][i] = '.';
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            g[i][j] = '.';
    dfs(0);
    return 0;
}
