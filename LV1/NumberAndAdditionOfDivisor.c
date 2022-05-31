// 약수의 개수와 덧셈

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int iseven(int a);

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++)
    {
        answer += (iseven(i) * i);
    }
    return answer;
}

int iseven(int a)
{
    if ((int)sqrt(a) * (int)sqrt(a) == a)
    {
        printf("%d", a);
        return -1;
    }
    else
        return 1;
}
