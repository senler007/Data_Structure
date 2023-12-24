#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int e[N], l[N], r[N], idx;
int n;

// 初始化
void init()
{
    r[0] = 1, l[1] = 0, idx = 2;
}

// 在下标为k的结点的右侧插入结点
void add(int k, int x)
{
    e[idx] = x, r[idx] = r[k], l[idx] = k, l[r[k]] = idx, r[k] = idx, idx++;
}

// 删除下标为k的结点
void remove(int k)
{
    r[l[k]] = r[k], l[r[k]] = l[k];
}

int main()
{
    init();
    scanf("%d", &n);

    char op[5];
    while (n--)
    {
        scanf("%s", op);
        if (*op == 'L')
        {
            int x;
            scanf("%d", &x);
            add(0, x);
        } else if (*op == 'R')
        {
            int x;
            scanf("%d", &x);
            add(l[1], x);
        } else if (*op == 'D')
        {
            int k;
            scanf("%d", &k);
            remove(k + 1);  // 因为idx初始为2
        } else if (!strcmp(op, "IL"))
        {
            int k, x;
            scanf("%d%d", &k, &x);
            add(l[k + 1], x);
        } else
        {
            int k, x;
            scanf("%d%d", &k, &x);
            add(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) printf("%d ", e[i]);
    puts("");

    return 0;
}
