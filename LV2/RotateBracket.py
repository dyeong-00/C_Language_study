# 괄호 회전하기

def solution(s):
    answer = 0
    s = list(s)
    for i in range(0, len(s)):
        answer += iscorrect(s)
        #print(s, "\n")
        s.append(s.pop(0))
    return answer

def iscorrect(s):
    l = []
    for i in range(0, len(s)):
        if s[i] == '[' or s[i] == '{' or s[i] == '(':
            l.append(s[i])
        elif s[i] == ']':
            if (len(l) != 0) and (l[-1] == '['):
                l.pop()
                continue
            else: return 0
        elif s[i] == '}':
            if (len(l) != 0) and (l[-1] == '{'):
                l.pop()
                continue
            else: return 0
        elif s[i] == ')':
            if (len(l) != 0) and (l[-1] == '('):
                l.pop()
                continue
            else: return 0
    # 중요! l이 비어있는 경우에만 1이 되도록
    if (len(l) == 0):
        return 1
    else:
        return 0
