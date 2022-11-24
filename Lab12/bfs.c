#include<stdio.h>
#include<stdlib.h>

#define V 7

typedef struct queue
{
    int front, rear;
    int size;
    int *arr;
}queue;

int isEmpty(queue q)
{
    return q.front == -1;
}

int isFull(queue q)
{
    return q.rear == q.size-1;
}

void enqueue(queue *q, int element)
{
    if(isFull(*q))
    {
        printf("Overflow!\n");
        return;
    }
    else if(isEmpty(*q))
    {
        q->rear = q->front = 0;
        q->arr[0] = element;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = element;
    }
}

int dequeue(queue *q)
{
    int val;
    if(isEmpty(*q))
    {
        printf("Underflow\n");
        val = -1;
    }
    else if(q->rear == q->front)
    {
        val = q->arr[q->rear];
        q->rear = q->front = -1;
    }
    else
    {
        val = q->arr[q->front];
        q->front++;
    }
    return val;
}

void bfs(int graph[V][V], int visited[V])
{
    queue q;
    q.size = V;
    q.arr = (int*)malloc(q.size * sizeof(int));
    q.front = q.rear = -1;
    
    enqueue(&q, 1);
    visited[1] = 1;
    int val;
    while(!isEmpty(q))
    {
        val = dequeue(&q);
        printf("%d ", val);
        for(int i = 0; i < V; i++)
        {
            if(graph[val][i] == 1 && visited[i] == 0)
            {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int graph[V][V] =  {{0, 1, 1, 1, 0, 0, 0},
                        {1, 0, 1, 0, 0, 0, 0},
                        {1, 1, 0, 1, 1, 0, 0},
                        {1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 1, 1, 0, 1, 1},
                        {0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0}};


    int visited[V] = {0};
    bfs(graph, visited);
    return 0;
}