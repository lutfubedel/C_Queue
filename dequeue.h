bool dequeue(QUEUE* queue)
{
    NODE* tempNode;

    if(queue->counter == 0)
    {
        return false;
    }

    tempNode = queue->front;

    if(queue->counter == 1)
    {
        queue->rear = queue->front = NULL;
    }
    else
    {
        queue->front = queue->front->next;
    }

    (queue->counter)--;
    free(tempNode);

    return true;
}
