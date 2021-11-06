#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>




typedef struct NODE
{
    struct NODE* next;
    int id,WGHT,pre,d;
    
}NODE;

typedef struct HEAP
{
    int n;
    NODE*HEAP;
}HEAP;

typedef struct HEAD
{
    NODE* HEAD;
    int pre,d; 
}HEAD;


typedef struct Graph
{
    int n;
    HEAD* Graph;
}Graph;


typedef struct PATH
{
    int d;     
    NODE* HEAD;
    
} PATH;

typedef struct PATHS
{
    int n;
    PATH* PATHS;
}PATHS;

void DISPLAY(Graph* g);
int* reset(int* arr, int size);

Graph* INIT(int size);
Graph* file(void);
Graph* Dijkstras(Graph* g, HEAP* h);


HEAP* HEAPINIT(int size);
HEAP* UPDATE(HEAP* h);
HEAP* dist_UPDATE(HEAP* h, int id, int d);
HEAP* delete(HEAP* h, int* dele);

NODE* PATH_INSERT(NODE* HEAD, int id);
NODE* Out_going(Graph* g, int* visited, int id);


HEAD INSERT(HEAD HEAD, int id, int WGHT);