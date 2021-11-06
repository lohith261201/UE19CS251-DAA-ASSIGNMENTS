#include "PES2UG19CS203_H.h"

int main(void)
{
    Graph *gr= file(); 
    HEAP *heap= HEAPINIT(gr->n); 

    gr = Dijkstras(gr,heap);
    DISPLAY(gr);
}
