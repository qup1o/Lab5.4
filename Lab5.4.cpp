// Лабораторна робота № 5.4

#include <iostream>
#include <cmath>

using namespace std;

// k-й доданок суми
double t(const int N, const int k)
{
    return sqrt(sin(1. * k) * sin(1. * k)
        + cos(1. * N / k) * cos(1. * N / k));
}

// 5) ітераційний спосіб
double S0(const int N, const int M)
{
    double s = 0;
    for (int k = N; k <= M; k++)
        s += t(N, k);
    return s;
}

// 1) на рекурсивному спуску, параметр k спадає
double S1(const int N, const int k, double s)
{
    s = s + t(N, k);
    if (k <= N)
        return s;
    else
        return S1(N, k - 1, s);
}

// 2) на рекурсивному спуску, параметр k зростає
double S2(const int N, const int M, const int k, double s)
{
    s = s + t(N, k);
    if (k >= M)
        return s;
    else
        return S2(N, M, k + 1, s);
}

// 3) на рекурсивному підйомі, параметр k спадає
double S3(const int N, const int k)
{
    if (k < N)
        return 0;
    else
        return t(N, k) + S3(N, k - 1);
}

// 4) на рекурсивному підйомі, параметр k зростає
double S4(const int N, const int M, const int k)
{
    if (k > M)
        return 0;
    else
        return t(N, k) + S4(N, M, k + 1);
}

int main()
{
    const int M = 19;       // верхня межа суми
    int N;

    cout << "N = "; cin >> N;

    if (N < 1 || N > M)
    {
        cout << "Error: 1 <= N <= 19 is required" << endl;
        return 1;
    }

    cout << "(iter)         S0 = " << S0(N, M) << endl;
    cout << "(down, k--)    S1 = " << S1(N, M, 0) << endl;
    cout << "(down, k++)    S2 = " << S2(N, M, N, 0) << endl;
    cout << "(up,   k--)    S3 = " << S3(N, M) << endl;
    cout << "(up,   k++)    S4 = " << S4(N, M, N) << endl;

    return 0;
}
