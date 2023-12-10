#include<iostream>
using namespace std;
const int N = 100010;

//并查集

//朴素并查集：
int p[N];//存储每个点的祖宗节点

//返回x的祖宗节点
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

//初始化，假定节点编号是1~n
void init(int n) {
    for (int i = 1;i <= n;i++) {
        p[i] = i;//祖宗是自己的那就是头节点
    }
}

//合并a和b所在的两个集合
void merge(int a, int b) {
    p[find(a)] = find(b);
}

//维护size的并查集：
int p[N], size[N];//p[]存储每个点的祖宗节点，size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量

//返回x的祖宗节点
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

//初始化，假定节点编号是1~n
void init(int n) {
    for (int i = 1;i <= n;i++) {
        p[i] = i;//祖宗是自己的那就是头节点
        size[i] = 1;
    }
}

//合并a和b所在的两个集合
void merge(int a, int b) {
    size[find(b)] += size[find(a)];
    p[find(a)] = find(b);
}

//维护到祖宗节点距离的并查集:
int p[N], d[N];
//p[]存储每个点的祖宗节点，d[x]存储x到p[x]的距离

//返回x的祖宗节点
int find(int x) {
    if (p[x] != x) {
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}

//初始化，假定节点编号是1~n
void init(int n) {
    for (int i = 1;i <= n;i++) {
        p[i] = i;
        d[i] = 0;
    }
}

//合并a和b所在的两个集合
void merge(int a, int b) {
    p[find(a)] = find(b);
    d[find(a)] = distance;//根据具体问题确定
}