#include "PES2UG19CS203_H.h"
#define inf INT_MAX




Graph* file(void)
{
    
    FILE*f;
    f=fopen("adjacencylist.txt","r");

    if (f == NULL)
    {
        return NULL;
    }

    size_t size = 1000;

    char* num = malloc(1000 * sizeof(char));
    int p= getline(&num,&size,f);
    Graph* g = INIT(atoi(num)+1); 

    while(p = getline(&num,&size,f) != -1)
    {
        
        char* token = strtok(num, " ");
        int NODE = atoi(token);

        int wt,v; //WGHT and vertex

        while (token != NULL)
        {
            // Get vertex token
            token = strtok(NULL," ");
            if (token == NULL)
                          break;

            v=atoi(token);
            token=strtok(NULL," ");

            if (token == NULL)
                           break;
            wt=atoi(token);
            g->Graph[v] = INSERT(g->Graph[v],NODE,wt);
        }
    }
    return g;
}

Graph* INIT(int size)
{
    Graph*g=(Graph*)malloc(sizeof(Graph));  
    g->Graph=malloc(size * sizeof(NODE));
    g->n=size;
  

    for (int i=0;i<=size-1;i++)
    {
        g->Graph[i].HEAD=NULL;
        g->Graph[i].d=inf;
        g->Graph[i].pre=0;
    }
    return g;
}

HEAD INSERT(HEAD HEAD, int id, int WGHT)
{
    // HEAPINIT NODE with id and WGHT
    NODE* nde = malloc(sizeof(NODE));
    nde->id = id;
    nde->WGHT = WGHT;
    nde->pre = 0;
    nde->next = NULL;
    nde->d = inf;
    

    if (HEAD.HEAD == NULL)
                HEAD.HEAD = nde;  //list is empty
    else
    {
        NODE*tmp = HEAD.HEAD;

        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = nde;
    }
    return HEAD;
}



HEAP* HEAPINIT(int size)
{
    HEAP*tmph=(HEAP*)malloc(sizeof(HEAP));
    tmph->n = size - 1;

    tmph->HEAP=malloc((tmph->n + 1) * sizeof(NODE));

    for (int i = 0; i < tmph->n; i++)
    {
        tmph->HEAP[i].id = i + 1;
        tmph->HEAP[i].d = inf;
        tmph->HEAP[i].pre = 0;
    }
    return tmph;
}

HEAP* UPDATE(HEAP* h)
{
    NODE tmp;

    for (int i = 0; i < h->n - 1; i++)
    {
        int swapcount = 0;
        
        for (int j = 0; j < (h->n - i - 1); j++)
        {
            if (h->HEAP[j + 1].d < h->HEAP[j].d)
            {
                tmp = h->HEAP[j];
                h->HEAP[j] = h->HEAP[j + 1];
                h->HEAP[j + 1] = tmp;
                swapcount ++;
            }
        }
        if (swapcount == 0)
                    break;
    }
    return h;
}

HEAP* delete(HEAP* h, int* dele)
{
    *dele = h->HEAP[0].id;

    for (int i = 0; i <= (h->n - 2); i++)
    {
        h->HEAP[i] = h->HEAP[i + 1];
    }
    h->n--;
    return h;
}

HEAP* dist_UPDATE(HEAP* h, int id, int d)
{
    for (int i = 0; i <= h->n -1;i++)
    {
        if (h->HEAP[i].id == id)
        {
            h->HEAP[i].d = d;
            break;
        }
    }

    h = UPDATE(h);
    return h;
}


NODE* Out_going(Graph* g, int* visited, int id)
{
    NODE* temp = g->Graph[id].HEAD;

    while (temp != NULL)
    {
        if (visited[temp->id] == 0)
                        return temp;
        temp = temp->next;
    }
    return NULL;
}

Graph* Dijkstras(Graph* g, HEAP* h)
{
    int source= g->n - 1;

    h->HEAP[h->n - 1].d = 0;
    g->Graph[h->HEAP[h->n - 1].id].d = 0;
    h = UPDATE(h);

    int value[g->n];
    for (int i = 1; i < g->n;i++)
    {
        value[i] = 0;
    }
    value[g->n - 1] = 1;
    int del;

    NODE* n;

    for (int i = 1; i < (g->n - 1);i++)
    {
        h = delete(h,&del);
        value[del] = 1;

        NODE*t=g->Graph[del].HEAD;

        while (t != NULL)
        {
            if ((g->Graph[t->id].d) > (g->Graph[del].d + t->WGHT))
            {
                g->Graph[t->id].d = g->Graph[del].d + t->WGHT;
                h = dist_UPDATE(h, t->id, g->Graph[t->id].d);
                g->Graph[t->id].pre = del;
            }
            t=t->next;
        }
    }
    return g;
}

NODE* PATH_INSERT(NODE* HEAD, int id)
{
    NODE* nde = malloc(sizeof(NODE));
    nde->id = id;
    nde->next = NULL;

    if (HEAD == NULL)
               HEAD=nde;
    else
    {
        NODE* temp = HEAD;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nde;
    }
    return HEAD;
}

int* reset(int* arr,int size)
{
    for (int i = 1; i <= size-1; i ++)
    {
        arr[i] = 0;
    }
    return arr;
}


void DISPLAY(Graph* g)
{
    PATHS* p = malloc(sizeof(PATHS));
    p->PATHS = malloc((g->n - 1) * sizeof(NODE));

    int source=g->n-1;
    int* arr = malloc(source * sizeof(int));

    for (int i = 1; i <= source-1; i ++)
    {
        if (g->Graph[i].pre == 0)
        {   
            p->PATHS[i].HEAD = NULL;
        }
        else
            {
            NODE* nde = malloc(sizeof(NODE));
            nde->id = i;
            nde->next = NULL;
            p->PATHS[i].HEAD = nde; 
            }
    }

    for (int i=1; i < source; i ++)
    {
        arr = reset(arr,source);
        int pre = g->Graph[i].pre;
        int j=0;
        int k=0;
  
        if (pre != 0)
        {
            while (pre != source)
            {
                arr[j] = pre;
                j++;
                pre =g->Graph[pre].pre;
            }
            arr[j] = pre;
        }
        while (k <= j && (arr[j]==source))
        {
            p->PATHS[i].HEAD = PATH_INSERT(p->PATHS[i].HEAD,arr[k]);
            k++;
        }
    }
    NODE*tmp;

    for (int i = 1; i <= source-1; i++)
    {
        tmp = p->PATHS[i].HEAD;
        if (tmp == NULL)
               printf("%d NO PATH\n",i);
        else
        {
            printf("%d ",i);

            while (tmp != NULL)
            {
                printf("%d ",tmp->id);
                tmp = tmp->next;
            }
            printf("%d\n",g->Graph[i].d);
        }
    }
}