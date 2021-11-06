#include "SORTHEADER.h"
unsigned long long int  BUBBLE_SORT(int *a,int n,unsigned long long int comp_count)
{
int i,j,temp;
for(i=0;i<=n-2;i++)
{
for(j=0;j<=n-2-i;j++)
{
comp_count++;
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
return comp_count;
}

unsigned long long int SELECTION_SORT(int *a,int n,unsigned long long int comp_count)
{
int i,min_pos,j,temp;
for(i=0;i<=n-2;i++)
{
min_pos=i;
for(j=i+1;j<=n-1;j++)
{
comp_count+=1;
if(a[min_pos]>a[j])
{
min_pos=j;
}
}
temp=a[i];
a[i]=a[min_pos];
a[min_pos]=temp;
}
/*for(int i=0;i<n;i++)
{
printf("%d:",a[i]);
}*/
return comp_count;
}

void merge(int *arr, int p, int q, int r) {

  
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
  cmp_count++;
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


void mergeSort(int *arr, int l, int r) {
  if (l < r) {

    
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    
    merge(arr, l, m, r);
  }
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int *array, int low, int high) {
  
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
  cmpquick_count++;
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int *array, int low, int high) {
  if (low < high) {
    
    
    int pi = partition(array, low, high);
    
    
    quickSort(array, low, pi - 1);
    
 
    quickSort(array, pi + 1, high);
    
}
}
