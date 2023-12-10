#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 100010;

//高精度(大整数)计算

vector<int> add(vector<int>& A, vector<int>& B) {
    if (A.size() < B.size()) {
        return add(B, A);
    }

    vector<int> C;
    int t = 0;
    for (int i = 0;i < A.size();i++) {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t);
        t /= 10;
    }

    if (t) C.push_back(t);
    return C;
}

//A>=B
vector<int> sub(vector<int>& A, vector<int>& B) {
    vector<int> C;
    for (int i = 0, t = 0;i < A.size();i++) {
        t = A[i] - t;
        if (i < B.size())  t -= B[i];
        C.push_back((t + 10) % 10);//包含补进位1和不补的情况
        if (t < 0) t = 1;
        else t = 0;
    }
}

vector<int> mul(vector<int>& A, int b) {
    vector<int> C;

    int t = 0;
    for (int i = 0;i < A.size() || t;i++) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

vector<int> div(vector<int>& A, int b, int& r) {
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1;i >= 0;i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }

    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

