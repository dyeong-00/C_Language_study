def solution(s):
    answer = 0
    for i in range(0, len(s)):
        // 문자인 경우
        if s[i] == 'z':
            answer = answer * 10 + 0
            i += 4
        elif s[i] == 'o':
            answer = answer * 10 + 1
            i += 3
        elif s[i] == 't':
            i += 1
            if s[i] == 'w':
                answer = answer * 10 + 2
                i += 2
            elif s[i] == 'h':
                answer = answer * 10 + 3
                i += 4
        elif s[i] == 'f':
            i += 1
            if s[i] == 'o':
                answer = answer * 10 + 4
                i += 3
            elif s[i] == 'i':
                answer = answer * 10 + 5
                i += 3
        elif s[i] == 's':
            i += 1
            if s[i] == 'i':
                answer = answer * 10 + 6
                i += 2
            elif s[i] == 'e':
                answer = answer * 10 + 7
                i += 4
        elif s[i] == 'e':
            answer = answer * 10 + 8
            i += 5
        elif s[i] == 'n':
            answer = answer * 10 + 9
            i += 4
        else: // 숫자인 경우
            answer = answer * 10 + (int(s[i]))
            i += 1
        
    return answer
