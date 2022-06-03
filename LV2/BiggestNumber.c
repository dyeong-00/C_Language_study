// 가장 큰 수

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void sort(float l[], int ds[], int low, int high);
int descending(float l[], int ds[], int low, int high);

// numbers_len은 배열 numbers의 길이입니다.
char* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(numbers_len * sizeof(char));
    float num = 0.0;
    int d;
    float l[numbers_len];
    int ds[numbers_len];
    for (int i = 0; i < numbers_len; i++)
    {
        l[numbers_len] = 0.0;
    }
    for (int i = 0; i < numbers_len; i++)
    {
        d = 1;
        while (numbers[i] / d >= 10)
        {
            d *= 10;
        }
        
        l[i] = (float)numbers[i] / (float)d;
        ds[i] = d;
    }
    printf("\n");
    sort(l, ds, 0, numbers_len-1);
    for (int i = 0; i < numbers_len; i++)
    {
        printf("%f  ", l[i]);
        printf("%d  ", ds[i]);
    }
    
    return answer;
}

void sort(float l[], int ds[], int low, int high)
{
    if (low < high)
    {
        int pivot = descending(l, ds, low, high);
        sort(l, ds, low, pivot-1);
        sort(l, ds, pivot+1, high);
    }
    else
        return;
        
}

int descending(float l[], int ds[], int low, int high)
{
    int pivot = low;
    int i = pivot + 1;
    int j = high;
    float temp;
    int temp_d;
    while(i <= j)
    {
        while(i <= high && l[i] >= l[pivot])
        {
            i++;
        }
        while(j > low && l[j] <= l[pivot])
        {
            j--;
        }
        if (i <= j)
        {
            temp = l[i];
            l[i] = l[j];
            l[j] = temp;
            temp_d = ds[i];
            ds[i] = ds[j];
            ds[j] = temp_d;
            i++;
            j--;
        }
        else
        {
            temp = l[pivot];
            l[pivot] = l[j];
            l[j] = temp;
            temp_d = ds[pivot];
            ds[pivot] = ds[j];
            ds[j] = temp_d;
        }
    }
    
    return pivot;
}
