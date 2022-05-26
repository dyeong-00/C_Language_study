// 소수 만들기

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int i, j, k, q, num;
    int answer = 0;
    
    for (i = 0; i < nums_len-2; i++)
    {
        for (j = i+1; j < nums_len-1; j++)
        {
            for (k = j+1; k < nums_len; k++)
            {
                num = nums[i] + nums[j] + nums[k];
                for (q = 2; q <= sqrt(num); q++)
                {
                    if (num % q == 0)
                    {
                        answer -= 1;
                        break;
                    }
                }
                answer += 1;
            }
        }
    }
    return answer;
}
