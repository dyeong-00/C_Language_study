# 괄호 회전하기

def solution(s):
    answer = 0
    for i in range(0, len(s)):
        answer += iscorrect(s)
        #print(s, "\n")
        s = s[1:] + s[0]
    return answer

def iscorrect(s):
    l = []
    for i in range(0, len(s)):
        if s[i] == '[' or s[i] == '{' or s[i] == '(':
            l.append(s[i])
        elif s[i] == ']':
            if len(l) != 0:
                if l[-1] == '[':
                    l.pop()
                    continue
                else:
                    return 0
            else: return 0
        elif s[i] == '}':
            if len(l) != 0:
                if l[-1] == '{':
                    l.pop()
                    continue
                else:
                    return 0
            else: return 0
        elif s[i] == ')':
            if len(l) != 0:
                if l[-1] == '(':
                    l.pop()
                    continue
                else:
                    return 0
            else: return 0

    return 1
