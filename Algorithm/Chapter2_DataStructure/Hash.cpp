#include<iostream>
using namespace std;
const int N = 1010, null = 0x3f3f3f3f;

//一般哈希，两种方法，一种为拉链法，一种为开放寻址法

//拉链法
int h[N], e[N], ne[N], idx;

//向哈希表中插入一个数
void insert(int x) {
    int k = (x % N + N) % N;//寻找映射值(方法不唯一，这里+N是为了让k恒大于0)
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

//查询某个数字是否存在
bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k];i != -1;i = ne[i]) {
        if (e[i] == x) return true;
    }
    return false;
}

//开放寻址法
int h[N];

//如果x在哈希表中，则返回x的下标，如果x不在哈希表中，返回x应该插入的位置
int find(int x) {
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x) {
        t++;
        if (t == N) t = 0;
    }
}