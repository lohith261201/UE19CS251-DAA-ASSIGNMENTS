#include "SORTHEADER.h"
void repeat(int n)
{
/*printf("%llu:\n",cmp_count);
printf("%llu:\n",cmpquick_count);
*/
int* a;
int* b;
int* c;
int* d;
unsigned long long int tempcount=0;
a=(int*)malloc(n*sizeof(int));
b=(int*)malloc(n*sizeof(int));
c=(int*)malloc(n*sizeof(int));
d=(int*)malloc(n*sizeof(int));
unsigned long long int comp_count=0;
printf("\t\tSIZE:%d\t\t\n",n);
clock_t t2;
for(int i=0;i<n;i++)
{
c[i]=rand();
}
for(int i=0;i<n;i++)
{
d[i]=c[i];
}
for(int i=0;i<n;i++)
/*{
printf("%d:",c[i]);
}*/
printf("\n");
t2=clock();
mergeSort(c,0,n-1);
/*for(int i=0;i<n;i++)
{
printf("%d:",c[i]);
}*/
t2=clock()-t2;
double time_taken_merge=((double)t2)/CLOCKS_PER_SEC;
printf("\t\t MERGE SORT\t\t\n");
printf("\nfunction took %f seconds to execute \n",time_taken_merge);
printf("\nCOUNT OF COMPARISONS:%llu\n\n",cmp_count);

clock_t t3;
for(int i=0;i<n;i++)
{
a[i]=d[i];
}
/*for(int i=0;i<n;i++)
{
printf("%d:",d[i]);
}*/
printf("\n");
t3=clock();
quickSort(d,0,n-1);
/*for(int i=0;i<n;i++)
{
printf("%d:",d[i]);
}*/
t3=clock()-t3;
double time_taken_quick=((double)t3)/CLOCKS_PER_SEC;
printf("\t\tQUICK SORT \t\t\n");
printf("\nfunction took %f seconds to execute \n",time_taken_quick);
printf("\nCOUNT OF COMPARISONS:%llu\n\n",cmpquick_count);

clock_t t;
for(int i=0;i<n;i++)
{
b[i]=a[i];
}
/*for(int i=0;i<n;i++)
{
printf("%d:",a[i]);
}*/
printf("\n");
t=clock();
tempcount=BUBBLE_SORT(a,n,comp_count);
/*for(int i=0;i<n;i++)
{
printf("%d:",a[i]);
}*/
t=clock()-t;
double time_taken_bubble=((double)t)/CLOCKS_PER_SEC;
printf("\t\tBUBBLE SORT\t\t\n");
printf("\nfunction took %f seconds to execute \n",time_taken_bubble);
printf("\nCOUNT OF COMPARISONS:%llu\n\n",tempcount);

clock_t t1;
/*for(int i=0;i<n;i++)
{
printf("%d:",b[i]);
}*/
printf("\n");
t1=clock();
tempcount=SELECTION_SORT(b,n,comp_count);
/*for(int i=0;i<n;i++)
{
printf("%d:",b[i]);
}*/
t1=clock()-t1;
double time_taken_selection=((double)t1)/CLOCKS_PER_SEC;
printf("\t\tSELECTION SORT\t\t\n");
printf("\nfunction took %f seconds to execute \n",time_taken_selection);
printf("\nCOUNT OF COMPARISONS:%llu\n\n",tempcount);



cmp_count=0;
cmpquick_count=0;
printf("\n\n\n\n");
}



void main()
{
int n;
for(n=100000;n<=1000000;n=n+50000)
{
repeat(n);
}
}

