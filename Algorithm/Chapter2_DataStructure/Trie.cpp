//Trie树

#include <iostream>
using namespace std;

// 因为输入字符串的总长度是1e5，所以总结点数就是1e5
const int N = 1e5 + 10;

// 因为这里存储的是小写英文字母，故每个结点最多往外连26条边
// cnt是以当前结点结尾的单词有多少个
// idx表示下一个可用的空白结点
int son[N][26], cnt[N], idx; // 下标为0的结点既是根节点又是空节点
char str[N];
int n;

void insert(char str[])
{
    // p 指的是当前结点，初始为根结点
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        // 找到当前字符对应的子结点编号
        int u = str[i] - 'a';
        // 因为idx = 0是根节点，不存储数据，故++idx而不是idx++
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        // 说明不存在当前的查询路径，直接返回
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    scanf("%d", &n);

    while (n--)
    {
        char op[2];
        scanf("%s%s", op, str);

        if (*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }


    return 0;
}

