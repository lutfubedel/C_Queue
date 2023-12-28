typedef struct node
{
    void* data;
    struct node* next;
}NODE;

typedef struct
{
    NODE* front;
    NODE* rear;
    int counter;
}QUEUE;


QUEUE* createQueue()
{
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    if(queue)
    {
        queue->front = NULL;
        queue->rear = NULL;
        queue->counter = 0;
    }

    return queue;
}


