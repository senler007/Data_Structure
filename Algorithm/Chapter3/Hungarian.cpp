//匈牙利算法，解决二分图匹配问题（男女匹配）

#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N = 1000, M = 1000;//N表示点的数据范围，M表示边的数据范围
int n1, n2, m;//n1表示第一个点集的个数，n2表示第二个点集的个数
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];//表示第二个集合中的每个点是否已经被遍历过

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool find(int x) {
    for (int i = h[x];i != -1;i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            if (match[j] == 0 || find(match[j]))
                return true;
        }
    }

    return false;
}

int main() {
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    int res = 0;
    for (int i = 1;i <= n1;i++) {
        memset(st, false, sizeof st);
        if (find(i)) res++;
    }

    cout << res;
}
