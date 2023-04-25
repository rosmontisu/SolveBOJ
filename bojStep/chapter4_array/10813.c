#include <stdio.h>
#include <stdlib.h>

void swap(int* num1, int* num2)
{
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

int main()
{
  int n, m;
  int a, b;
  scanf("%d %d", &n, &m);
  
  int* arr = (int*)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++)
    arr[i] = i+1;
  
  for (int i = 0; i < m; i++)
  {
    scanf("%d %d", &a, &b);
    swap(&arr[a-1], &arr[b-1]);
  }
  
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  
  free(arr);
  return 0;
}
