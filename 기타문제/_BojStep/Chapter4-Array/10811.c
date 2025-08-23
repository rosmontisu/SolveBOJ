#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, m;
  int a, b;
  
  scanf("%d %d", &n, &m);
  
  int* arr = (int*)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) // arr 1 2 3... 정렬
  {
    arr[i] = i+1;
  }
  
  for (int i = 0; i < m; i++)
  {
    scanf("%d %d", &a, &b);
    for (int j = 0; j < (b-a+1)/2; j++) // b-a에서 오차 1을 보정 후 2로 나눈다.
    {
      int temp = arr[a-1+j];
      arr[a-1+j] = arr[b-1-j];
      arr[b-1-j] = temp;
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  
  free(arr);
  return 0;
}
