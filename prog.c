#include<stdio.h> 
#include<stdlib.h>

int divisionPoint (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;
            int l = arr[i];
            arr[i] = arr[j];
            arr[j] = l;
        } 
    } 
    int r = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = r;
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int dp = divisionPoint(arr, low, high); 
        quickSort(arr, low, dp - 1); 
        quickSort(arr, dp + 1, high); 
    } 
} 
  
int main() 
{ 
  int N; 
  scanf("%d", &N); 
  int *arr = (int*)malloc(sizeof(int) * N); 
  for (int i = 0; i < N; i++) 
    scanf("%d", &arr[i]); 
  int n = N;
  quickSort(arr, 0, n-1); 
    
  for (int i = N-1; i >= 0; i--) 
    printf("%d ", arr[i]);

  free(arr);
  return 0; 
} 
