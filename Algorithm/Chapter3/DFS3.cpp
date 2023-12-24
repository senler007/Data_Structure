//经典八皇后（按每个点枚举）
#include<iostream>
using namespace std;

int n;
const int N = 20;
bool row[N], col[N], diagonal[N], back_diagonal[N];
char g[N][N];

void dfs(int x, int y, int s/*第s个皇后已经防止*/) {
    if (y == n) y = 0, x++;
    if (x == n) {
        if (s == n) {
            for (int i = 0;i < n;i++) puts(g[i]);
            puts("");
        }
        return;
    }

    //不放皇后
    dfs(x, y + 1, s);

    //放皇后
    if (!row[x] && !col[y] && !diagonal[x + y] && !back_diagonal[n + x - y]) {
        row[x] = col[y] = diagonal[x + y] = back_diagonal[n + x - y] = true;
        g[x][y] = 'Q';
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = diagonal[x + y] = back_diagonal[n + x - y] = false;
        g[x][y] = '.';
    }
}

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            g[i][j] = '.';
        }
    }
    dfs(0, 0, 0);
    return 0;
}