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