bool enqueue(QUEUE* queue, void* dataPtr)
{
    NODE* newPtr = (NODE*)malloc(sizeof(NODE));
    if(!newPtr)
    {
        return false;
    }

    newPtr->data = dataPtr;
    newPtr->next = NULL;

    if(queue->counter == 0 )
    {
        queue->front = newPtr;
    }
    else
    {
        queue->rear->next = newPtr;
    }

    (queue->counter)++;
    queue->rear = newPtr;

    return true;
}
