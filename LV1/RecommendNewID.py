# 신규 아이디 추천

def solution(new_id):
    answer = ''
    dot = 0
    
    for i in new_id:
        # 4단계
        if answer == '' and i == '.':
            continue
            
        # 1단계
        if i.isalpha():
            dot = 0
            if i.isupper():
                answer += i.lower()
            else:
                answer += i
        # 2단계
        else:
            if i == '.':
                # 3단계
                if dot > 0:
                    continue
                else:
                    answer += i
                    dot += 1
            elif i == '-' or i == '_' or i.isdigit():
                dot = 0
                answer += i
            else:
                continue
    
    # 5단계
    if answer == '':
        answer = 'a'
    
    # 4단계
    while(True):
        if answer[-1] == '.':
            answer = answer[:-1]
        else:
            break
    
    # 6단계
    if len(answer) > 15:
        answer = answer[:15]
    
    # 4단계
    while(True):
        if answer[-1] == '.':
            answer = answer[:-1]
        else:
            break
            
    # 7단계
    while(True):
        if len(answer) <= 2:
            answer += answer[-1]
        else:
            break
            
    return answer
