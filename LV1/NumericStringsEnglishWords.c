// 숫자 문자열과 영단어

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    //int length = sizeof(s) / sizeof(char);
    int i = 0;
    int answer = 0;
    while(1)
    {
        if (s[i] == NULL)
        {
            break;
        }
        else
        {
            if (s[i] == 'z')
            {
                answer = answer * 10;
                i += 4;
            }
            else if (s[i] == 'o')
            {
                answer = answer * 10 + 1;
                i += 3;
            }
            else if (s[i] == 't')
            {
                i++;
                if (s[i] == 'w')
                {
                    answer = answer * 10 + 2;
                    i += 2;
                }
                else if (s[i] == 'h')
                {
                    answer = answer * 10 + 3;
                    i += 4;
                }
            }
            else if (s[i] == 'f')
            {
                i++;
                if (s[i] == 'o')
                {
                    answer = answer * 10 + 4;
                    i += 3;
                }
                else if (s[i] == 'i')
                {
                    answer = answer * 10 + 5;
                    i += 3;
                }
            }
            else if (s[i] == 's')
            {
                i++;
                if (s[i] == 'i')
                {
                    answer = answer * 10 + 6;
                    i += 2;
                }
                else if (s[i] == 'e')
                {
                    answer = answer * 10 + 7;
                    i += 4;
                }
            }
            else if (s[i] == 'e')
            {
                answer = answer * 10 + 8;
                i += 5;
            }
            else if (s[i] == 'n')
            {
                answer = answer * 10 + 9;
                i += 4;
            }
            else
            {
                answer = answer * 10 + (int)(s[i] - '0');
                i++;
            }
        }
    }
    return answer;
}
