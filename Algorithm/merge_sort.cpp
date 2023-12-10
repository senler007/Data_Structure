#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int temp[N];//归并需要额外开辟一个临时数组

//归并排序即是通过合并排序两段有序数组进行排序

void merge_sort(int q[], int l, int r) {
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);//让需要合并的两数组有序

    //合并两数组
    int k = 0, i = l, j = mid + 1;//从两段数组的头开始比较，谁小谁入临时数组
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) temp[k++] = q[i++];
        else temp[k++] = q[j++];
    }
    //剩下谁没入完，就全部入进临时数组
    while (i <= mid)temp[k++] = q[i++];
    while (j <= r)temp[k++] = q[j++];

    for (i = l, j = 0;i <= r;i++, j++) {
        q[i] = temp[j];
    }
}

int main() {
    int q[N] = { 1,20,6,4 };
    merge_sort(q, 0, 3);
    for (int i = 0;i < 4;i++) {
        cout << q[i] << " ";
    }
}