#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;

//栈

//tt表示栈顶
int stk[N], tt = 0;

//向栈顶插入一个数
stk[++tt] = x;

//从栈顶弹出一个数
tt--;

//栈顶的值
stk[tt];



//队列
// hh 表示队头，tt表示队尾
int q[N], hh = 0, tt = -1;

// 向队尾插入一个数
q[++tt] = x;

// 从队头弹出一个数
hh++;

// 队头的值
q[hh];

// 判断队列是否为空，如果 hh <= tt，则表示不为空
if (hh <= tt)
{

}