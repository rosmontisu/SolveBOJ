#include<stdio.h>
#include<algorithm>

#include<stdlib.h>
using namespace std;

const int MX = 105;

int D[MX][MX], E[MX][MX];

int main()
{
	int N;
	scanf("%d", &N);
	
    
    // 플로이드 1 -> 이게 첫번째 코드 인듯?
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				D[i][j] = min(D[i][k] + D[k][j], D[i][j]);
			}
		}
	}

    // 만든거 출력
    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++) 
        {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }

}
