#include <iostream>

using namespace std;

struct SCORE{
    int lang;
    int eng;
    int math;
    char name[12];
};

SCORE ARR[100001];

// A's Priority is high: return positive
int compare(SCORE A, SCORE B) {
    //LANG SCORE Descending
    if (A.lang != B.lang) 
        return (A.lang - B.lang);

    //ENG SCORE Ascending
    if (A.eng != B.eng) 
        return (B.eng - A.eng);
    
    //MATH SCORE Descending
    if (A.math != B.math)
        return (A.math - B.math);
    
    //NAME ORDER Ascending
    int i = 0;
    while (A.name[i] != '\0' && B.name[i] != '\0') {
        if (A.name[i] != B.name[i]) {
            break;
        }
        i++;
    }
    return (B.name[i] - A.name[i]);
}

void merge(SCORE A[], int start, int mid, int end)
{
    int p = start, q = mid + 1;
    SCORE B[end - start + 1];
    int k = 0;

    for (int i = start; i <= end; i++) {

        if (p > mid) {// Check if left part is done
            B[k++] = A[q++];
        } else if (q > end) {// Check if right part is done
            B[k++] = A[p++];
        } else {
            int ret = compare(A[p], A[q]);
            if (ret > 0) {
                B[k++] = A[p++];
            } else {
                B[k++] = A[q++];
            }
        }
    }

    for (int i = 0; i < k; i++) {
        A[start++] = B[i];
    }
}

void merge_sort(SCORE A[], int start, int end)
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
        scanf("%s %d %d %d", ARR[i].name, &ARR[i].lang, &ARR[i].eng, &ARR[i].math);
    }
    merge_sort(ARR, 0, N - 1);

    for (int i = 0; i < N; ++i)
        printf("%s\n", ARR[i].name);

    return 0;
}
