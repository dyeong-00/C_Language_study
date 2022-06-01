// 최솟값 만들기
// 미완

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.

void ascending_sort(int l[], int low, int high);
void descending_sort(int l[], int low, int high);
int ascending(int l[], int low, int high);
int descending(int l[], int low, int high);


int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    ascending_sort(A, 0, A_len-1);
    descending_sort(B, 0, B_len-1);
    for (int i = 0; i < A_len; i++)
    {
        answer += (A[i] * B[i]);
    }
    return answer;
}

void ascending_sort(int l[], int low, int high)
{
    if (low <= high)
    {
        int pivot = ascending(l, low, high);
        ascending_sort(l, low, pivot-1);
        ascending_sort(l, pivot+1, high);
    }
        
}

void descending_sort(int l[], int low, int high)
{
    if (low < high)
    {
        int pivot = descending(l, low, high);
        descending_sort(l, low, pivot-1);
        descending_sort(l, pivot+1, high);

    }
}

int ascending(int l[], int low, int high)
{
    int pivot = l[low];
    int i = pivot + 1;
    int j = high;
    int temp;
    while(i <= j)
    {
        while(l[i] <= l[pivot])
        {
            i++;
        }
        while(l[j] >= l[pivot])
        {
            j--;
        }
        if (i <= j)
        {
            temp = l[i];
            l[i] = l[j];
            l[j] = temp;
            i++;
            j--;
        }
    }
    temp = l[pivot];
    l[pivot] = l[i];
    l[i] = temp;
    
    return pivot;
}

int descending(int l[], int low, int high)
{
    int pivot = l[low];
    int i = pivot + 1;
    int j = high;
    int temp;
    while(i <= j)
    {
        while(l[i] >= l[pivot])
        {
            i++;
        }
        while(l[j] <= l[pivot])
        {
            j--;
        }
        if (i >= j)
        {
            temp = l[i];
            l[i] = l[j];
            l[j] = temp;
            i++;
            j--;
        }
        
    }
    temp = l[pivot];
    l[pivot] = l[i];
    l[i] = temp;
    
    return pivot;
}
