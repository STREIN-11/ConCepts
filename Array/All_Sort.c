#include <stdio.h>
#include <stdlib.h>




void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void selection(int array[], int size){
  for (int i = 0; i < size - 1; i++){
    int temp = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[temp])
        temp = j;
    }
    swap(&array[temp], &array[i]);
  }
}

void insertionsort(int *arr, int size){
    int j,temp;
    for (int i = 1; i <=size-1; i++){
        temp = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;   
    }
}

void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void bubble(int *arr, int size){
    int temp;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }   
    } 
}

void print(int arr[],int size){
    printf("Result is : ");
    for (int i = 0; i < size; i++){
        printf("%d",arr[i]);
    } 
}
int main(int argc, char const *argv[]){
    int size;
    printf("Enter The Size: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter Array element : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    // selection(arr,size);
    // quickSort(arr,0,size-1);
    mergeSort(arr,0,size-1);
    print(arr,size);
    

    return 0;
}
