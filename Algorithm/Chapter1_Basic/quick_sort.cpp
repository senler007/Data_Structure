#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;

//快速排序的思想即是通过将一个数组不断分为小于x和大于x的两端数组，再将这两段数组持续递归重复分割直至全部有序
//x可为待分数组中的任意一个数
//复杂度nlog2n

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];//定左右点，两端开始往中间遍历//x定为数组的中点
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);//递归分段数组
}

int main() {
    int q[N] = { 1,20,6,4 };
    quick_sort(q, 0, 3);
    for (auto a : q) {
        cout << a << " ";
    }
}