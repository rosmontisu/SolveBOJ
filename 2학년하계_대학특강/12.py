def solution(number):
    answer = ""
    answer = "POSITIVE" if number > 0 else "NEGATIVE" if number < 0 else "ZERO"
    return answer