#include <iostream>

#define MAX(A, B) ((A > B) ? A : B)

using namespace std;

long long ARR[1000001] = {0};

bool compare(long long X, long long Y)
{
    if (X < Y)
        return true;
    return false;
}

void merge(long long A[], int start, int mid, int end)
{
    int p = start, q = mid + 1;
    long long B[end - start + 1];
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

void mergesort(long long A[], int start, int end)
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

    long long max_val = ARR[0];
    int count = 1;
    int max_count = 0;
    int i = 1;

    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%lld", &ARR[i]);
    }

    mergesort(ARR, 0, N - 1);


    do {
        if (ARR[i] != ARR[i - 1]) {
            if (count > max_count) {
                max_val = ARR[i-1];
                max_count = count;
            }
            count = 0;
        }
        count++;
    } while (i++ < N);
    
    printf("%lld\n", max_val);

    return 0;
}
