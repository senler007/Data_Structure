#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;

//二分法
/*在实际应用中，bSearch_1 可以用于找到序列中第一个满足某条件的元素的位置（lower bound）
而 bSearch_2 可以用于找到序列中第一个不满足某条件的元素的位置（upper bound）
这两者结合起来可以有效地找到符合条件的元素的范围
*/
bool check(int x) { /*...*/ } //检查x是否满足某种性质

int bSearch_1(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int bSearch_2(int l, int r) {
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

