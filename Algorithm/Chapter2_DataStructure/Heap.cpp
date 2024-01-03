//checked
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int h[N];//存储堆中的值,h[1]是堆顶,x的左儿子是2x,右儿子是2x + 1
int hp[N], ph[N];// ph[k]存储第k个插入的点在堆中的位置,hp[k]存储堆中下标是k的点是第几个插入的(可选)
int n, m;//n:size

//直接把两个点的值交换，坐标不动
void simpleswap(int a, int b) {
    swap(h[a], h[b]);
}

// 交换两个点，及其映射关系（基本不用）当需要对第n个插入的点进行操作时才使用
void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;//2*u代表左儿子，2*u+1代表右儿子
    if (u * 2 <= n && h[t] > h[u * 2]) t = u * 2;
    if (u * 2 + 1 <= n && h[t] > h[u * 2 + 1]) t = u * 2 + 1;
    if (t != u)
    {
        simpleswap(t, u);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 > 0 && h[u] < h[u / 2])
    {
        simpleswap(u, u / 2);
        u >>= 1;
    }
}

//不记录插入次序，编写普通堆排序
int main1() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> h[i];
    }
    for (int i = n / 2;i;i--) {
        down(i);
    }
    for (int i = 1;i <= n;i++) {
        cout << h[i];
    }
}

int main2()
{
    int s;
    cin >> s;

    string op;
    while (s--)
    {
        cin >> op;
        if (op == "I")//
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


