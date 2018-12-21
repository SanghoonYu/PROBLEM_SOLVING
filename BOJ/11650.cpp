#include <iostream>

using namespace std;

int ARR[100001][2];

void merge(int A[][2], int start, int mid, int end)
{
    int p = start, q = mid + 1;
    int B[end - start + 1][2];
    int k = 0;

    for (int i = start; i <= end; i++) {

        if (p > mid) {// Check if left part is done
            B[k][0] = A[q][0];
            B[k][1] = A[q][1];
            k++; q++;
        } else if (q > end) {// Check if right part is done
            B[k][0] = A[p][0];
            B[k][1] = A[p][1];
            k++; p++;
        } else {
            if (A[p][0] == A[q][0]) {
                if (A[p][1] < A[q][1]) {
                    B[k][0] = A[p][0];
                    B[k][1] = A[p][1];
                    k++; p++;
                } else {
                    B[k][0] = A[q][0];
                    B[k][1] = A[q][1];
                    k++; q++;
                }
            } else {
                if (A[p][0] < A[q][0]) {
                    B[k][0] = A[p][0];
                    B[k][1] = A[p][1];
                    k++; p++;
                } else {
                    B[k][0] = A[q][0];
                    B[k][1] = A[q][1];
                    k++; q++;
                }
            }
        }
    }

    for (int i = 0; i < k; i++) {
        A[start][0] = B[i][0];
        A[start][1] = B[i][1];
        start++;
    }
}

void merge_sort(int A[][2], int start, int end)
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
        scanf("%d %d", &ARR[i][0], &ARR[i][1]);
    }

    merge_sort(ARR, 0, N - 1);

    for (int i = 0; i < N; ++i)
        printf("%d %d\n", ARR[i][0], ARR[i][1]);

    return 0;
}
