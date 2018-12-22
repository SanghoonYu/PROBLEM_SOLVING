#include <iostream>

#define MAX(A, B) ((A > B) ? A : B)

using namespace std;

int ARR[5000001] = {0};

bool compare(int X, int Y)
{
    if (X < Y)
        return true;
    return false;
}

void merge(int A[], int start, int mid, int end)
{
    int p = start, q = mid + 1;
    int B[end - start + 1];
    int k = 0;

    while (p <= mid && q <= end) {
        B[k++] = compare(A[p], A[q]) ? A[p++] : A[q++];
    }
    while (p <= mid)
        B[k++] = A[p++];
    while (q <= end)
        B[k++] = A[q++];

    for (int i = 0; i < k; i++) {
        A[start++] = B[i];
    }
}

void mergesort(int A[], int start, int end)
{
    if (start < end) {
        int mid = (start + end) / 2;
        mergesort(A, start, mid);
        mergesort(A, mid + 1, end);
        merge(A, start, mid, end);
    }
}

int main()
{
    int N;
    int K;

    freopen("input.txt", "r", stdin);

    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &ARR[i]);
    }

    mergesort(ARR, 0, N - 1);

    printf("%d\n", ARR[K - 1]);

    return 0;
}
