# 로또의 최고순위와 최저순위

def solution(lottos, win_nums):
    win = 0;
    zero = 0;
    for i in range(0, len(lottos)):
        if lottos[i] == 0:
            zero += 1
            continue
        else:
            for j in range(0, len(win_nums)):
                if lottos[i] == win_nums[j]:
                    win += 1
    answer = []
    if (win + zero) >= 2:
        answer.append(7 - (win + zero))
    else:
        answer.append(6)
    if (win) >= 2:
        answer.append(7 - (win))
    else:
        answer.append(6)
    return answer
