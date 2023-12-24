// h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
// ph[k]存储第k个插入的点在堆中的位置
// hp[k]存储堆中下标是k的点是第几个插入的

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int h[N], hp[N], ph[N];
int n, m;

// 交换两个点，及其映射关系
void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]); // 这个才是核心
    swap(hp[a], hp[b]); // 这个是辅助
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;//2*u代表左儿子，2*u+1代表右儿子
    if (u * 2 <= n && h[t] > h[u * 2]) t = u * 2;
    if (u * 2 + 1 <= n && h[t] > h[u * 2 + 1]) t = u * 2 + 1;
    if (t != u)
    {
        heap_swap(t, u);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main()
{
    int s;
    cin >> s;

    string op;
    while (s--)
    {
        cin >> op;
        if (op == "I")
        {
            int x;
            cin >> x;

            n++, m++;
            hp[n] = m, ph[m] = n;
            h[n] = x;
            up(n);
        } else if (op == "PM") cout << h[1] << endl;
        else if (op == "DM")
        {
            heap_swap(1, n);
            n--;
            down(1);
        } else if (op == "D")
        {
            int k;
            cin >> k;

            k = ph[k];
            heap_swap(k, n);
            n--;
            down(k), up(k);
        } else
        {
            int k, x;
            cin >> k >> x;

            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }

    return 0;
}
