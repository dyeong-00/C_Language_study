#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int finding_index(char* ID, const char* id_list[]);

// id_list_len은 배열 id_list의 길이입니다.
// report_len은 배열 report의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {

    int report_arr[id_list_len][id_list_len];
    int i, j, q;
    char* ID1 = NULL;
    char* ID2 = NULL;
    
    for (i = 0; i < id_list_len; i++)
    {
        for (j = 0; j < id_list_len; j++)
        {
            report_arr[i][j] = 0;
        }
    }
    for (q = 0; q < report_len; q++)
    {
        ID1 = strtok(report[q], " ");
        i = finding_index(ID1, id_list);
        ID2 = strtok(NULL, " ");
        j = finding_index(ID2, id_list);
        if (report_arr[j][i] > 0)
        {
            continue;
        }
        else
        {
            report_arr[j][i] = 1;
        }
    }
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * id_list_len);
    for (q=0;q<id_list_len;q++)
    {
        answer[q] = 0;
    }
    for (i=0;i<id_list_len;i++)
    {
        int num = 0;
        for (j=0;j<id_list_len;j++)
        {
            num += report_arr[i][j];
        }
        if (num >= k)
        {
            for (j=0;j<id_list_len;j++)
            {
                if (report_arr[i][j] == 1)
                {
                    answer[j] += 1;
                }
            }
        }
    }
    return answer;
}

int finding_index(char* ID, const char* id_list[])
{
    int i = 0;
    while(1)
    {
        if (strcmp(id_list[i], ID) == 0)
        {
            break;
        }
        else
        {
            i++;
            continue;
        }
    }
    return i;
}
