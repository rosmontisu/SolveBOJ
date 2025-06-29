def solution(year):
    answer = ""
    if year % 400 == 0:
        answer = "YES"
    elif year % 100 == 0:
        answer = "NO"
    elif year % 4 == 0:
        answer = "YES"
    else:
        answer = "NO"
    return answer
