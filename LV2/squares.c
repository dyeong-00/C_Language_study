// 멀쩡한 사각형

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int w, int h) {
    long long answer = 0;
    answer = (long long)w * (long long)h;
    int gcd = 0;
    if (w > h)
        gcd = findGCD(w, h);
    else
        gcd = findGCD(h, w);
    
    answer -= (w + h - gcd);
    
    return answer;
}

// 최대공약수 구하는 함수
int findGCD(int a, int b)
{
    int temp = 0;
    while(b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
