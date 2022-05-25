// 행렬 테두리 회전하기

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// queries_row_len은 2차원 배열 queries의 행(세로) 길이입니다.
// queries_col_len은 2차원 배열 queries의 열(가로) 길이입니다.
// queries[i][j]는 queries의 i번째 행의 j번째 열에 저장된 값을 의미합니다.
int* solution(int rows, int columns, int **queries, size_t queries_row_len, size_t queries_col_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(queries_row_len * sizeof(int));
    int i, j;
    int x1, y1, x2, y2;
    int x, y, temp, min;
    int count = 1;
    
    // list 초기화
    int list[rows][columns];
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            list[i][j] = count;
            count++;
        }
    }
  
    // 회전하고 min값 구하기
    for (i = 0; i < queries_row_len; i++)
    {
        x1 = queries[i][0]-1;
        y1 = queries[i][1]-1;
        x2 = queries[i][2]-1;
        y2 = queries[i][3]-1;
        temp = list[x1][y1];
        min = temp;
        for (x = x1; x < x2; x++)
        {
            list[x][y1] = list[x+1][y1];
            if (list[x][y1] < min)
                min = list[x][y1];
        }
        for (y = y1; y < y2; y++)
        {
            list[x2][y] = list[x2][y+1];
            if (list[x2][y] < min)
                min = list[x2][y];
        }
        for (x = x2; x > x1; x--)
        {
            list[x][y2] = list[x-1][y2];
            if (list[x][y2] < min)
                min = list[x][y2];
        }
        for (y = y2; y > y1+1; y--)
        {
            list[x1][y] = list[x1][y-1];
            if (list[x1][y] < min)
                min = list[x1][y];
        }
        list[x1][y1+1] = temp;
        answer[i] = min;
        
    }
    return answer;
}
