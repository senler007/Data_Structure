#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int n, m;
int a[N];//原数组
int b[N];//差分数组
//差分巧妙实现方法 //差分即是前缀和的逆运算

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++) scanf("%d", &a[i]);

    for (int i = 1;i <= n;i++) {
        insert(i, i, a[i]);//该步即构造出差分数组
    }

    while (m--) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    for (int i = 1;i <= n;i++) {
        b[i] += b[i - 1];//还原原数组
    }
}