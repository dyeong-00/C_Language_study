#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    int i, j;
    int win = 0;
    int zero = 0;
  
    // 지워진 숫자와 당첨된 숫자의 개수 구하기
    for (i = 0; i < lottos_len; i++)
    {
        if (lottos[i] == 0)
        {
            zero += 1;
            continue;
        }
        for (j = 0; j < win_nums_len; j++)
        {
            if (lottos[i] == win_nums[j])
            {
                win += 1;
            }
            else
                continue;
        }
    }
  
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(1);
  
    // 순위 할당
    if (win + zero >= 2)
    {
        answer[0] = 7 - (win + zero);
    }
    else
    {
        answer[0] = 6;
    }
    if (win >= 2)
    {
        answer[1] = 7 - win;
    }
    else
    {
        answer[1] = 6;
    }
    return answer;
}
