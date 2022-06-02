// 최솟값 만들기

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const int* a, const int* b)
{
    if(*a > *b)
        return 1;
    else if(*a < *b)
        return -1;
    else
        return 0;
}

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    int temp = 0;
    qsort(A, A_len, sizeof(int), compare);
    qsort(B, B_len, sizeof(int), compare);
    for (int i = 0; i < A_len; i++)
    {
//        printf("%d, %d\n", A[i], B[i]);
        answer += (A[i] * B[B_len-i-1]);
    }
    return answer;
}
