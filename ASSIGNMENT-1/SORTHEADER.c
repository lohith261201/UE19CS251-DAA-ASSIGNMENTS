#include<stdio.h>
#include<stdlib.h>
#include<time.h>
unsigned long long int cmp_count=0;
unsigned long long int cmpquick_count=0;
unsigned long long int  BUBBLE_SORT(int *a,int n,unsigned long long int comp_count);
unsigned long long int SELECTION_SORT(int *a,int n,unsigned long long int comp_count);
void merge(int *arr, int p, int q, int r); 
void mergeSort(int *arr, int l, int r); 
void swap(int *a, int *b); 
int partition(int *array, int low, int high);
void quickSort(int *array, int low, int high);
void repeat(int n);  