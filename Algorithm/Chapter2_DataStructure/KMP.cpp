/*一、题目描述
给定一个模式串 S，以及一个模板串 P，所有字符串中只包含大小写英文字母以及阿拉伯数字。

模板串P在模式串S中多次作为子串出现。

求出模板串 P在模式串S中所有出现的位置的起始下标。

输入格式
第一行输入整数 N，表示字符串 P的长度。

第二行输入字符串P。

第三行输入整数 M ，表示字符串 S的长度。

第四行输入字符串 S 。

输出格式
共一行，输出所有出现位置的起始下标（下标从 0 00 开始计数），整数之间用空格隔开。

数据范围
1 ≤ N ≤ 1 0 5 1≤N≤10^5
5

1 ≤ M ≤ 1 0 6 1≤M≤10^6
6


输入样例：

3
aba
5
ababa
1
2
3
4
输出样例：

0 2
*/

#include <iostream>

using namespace std;

const int N = 100010, M = 10010; //N为模式串长度，M匹配串长度

int n, m;
int ne[M]; //next[]数组，避免和头文件next冲突
char s[N], p[M];  //s为模式串， p为匹配串

int main()
{
    cin >> n >> s + 1 >> m >> p + 1;  //下标从1开始

    //求next[]数组
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && p[i] != p[j + 1]) j = ne[j];//已经开始追但没看对，退到上次合适的地方
        if (p[i] == p[j + 1]) j++; //看对眼加一步
        ne[i] = j;//写ne数组
    }
    //匹配操作
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m)  //满足匹配条件，打印开头下标, 从0开始
        {
            //匹配完成后的具体操作
            //如：输出以0开始的匹配子串的首字母下标
            //printf("%d ", i - m); (若从1开始，加1)
            j = ne[j];            //再次继续匹配
        }
    }

    return 0;
}
