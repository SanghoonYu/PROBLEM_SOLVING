#include <iostream>

using namespace std;

struct POINT{
    int x;
    int y;
};

POINT ARR[100001];

void merge(POINT A[], int start, int mid, int end)
{
    int p = start, q = mid + 1;
    POINT B[end - start + 1];
    int k = 0;

    for (int i = start; i <= end; i++) {

        if (p > mid) {// Check if left part is done
            B[k++] = A[q++];
        } else if (q > end) {// Check if right part is done
            B[k++] = A[p++];
        } else {
            if (A[p].y == A[q].y) {
                if (A[p].x < A[q].x) {
                    B[k++] = A[p++];
                } else {
                    B[k++] = A[q++];
                }
            } else {
                if (A[p].y < A[q].y) {
                    B[k++] = A[p++];
                } else {
                    B[k++] = A[q++];
                }
            }
        }
    }

    for (int i = 0; i < k; i++) {
        A[start++] = B[i];
    }
}

void merge_sort(POINT A[], int start, int end)
{
    if (end > start) {
        int mid = (start + end) / 2;
        merge_sort(A, start, mid);
        merge_sort(A, mid + 1, end);

        merge(A, start, mid, end);
    }
}

int main()
{
    int N;

    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &ARR[i].x, &ARR[i].y);
    }

    merge_sort(ARR, 0, N - 1);

    for (int i = 0; i < N; ++i)
        printf("%d %d\n", ARR[i].x, ARR[i].y);

    return 0;
}
