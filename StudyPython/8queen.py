pos = [0] * 8               # 각 열의 퀸 위치
flag_a = [False] * 8        # 각 행에 퀸 배치 체크
flag_b = [False] * 15       # 우상/좌하 대각선 퀸 배치 체크
flag_c = [False] * 15       # 좌상/우하 대각선 퀸 배치 체크

def put() -> None:
    for j in range(8):
        for i in range(8):
            print('●' if pos[i] == j else '□', end='')
        print()
    print()

def set(i: int) -> None:
    for j in range(8):
        if(     not flag_a[j]               # j행에 퀸이 없다면
            and not flag_b[i + j]           # +기울기에 퀸이 없다면  
            and not flag_c[i - j + 7]):      # -기울기에 퀸이 없다면
            pos[i] = j                      # 퀸을 j행에 배치
            if i == 7:                      # 모든 열에 퀸을 배치 확인
                put()
            else:
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = True        
                set(i + 1)
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = False
        
set(0)
