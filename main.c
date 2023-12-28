#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "create_queue.h"
#include "enqueue.h"
#include "dequeue.h"

int main()
{
    char prefix[50] = "- + * 9 + 2 8 * + 4 8 6 3";
    char* token = strtok(prefix, " ");

    QUEUE* myQueue = createQueue();

    while (token != NULL)
    {
        enqueue(myQueue, token);
        token = strtok(NULL, " ");
    }

    printQueue(myQueue);
    printf("-----------------------------------\n");

    while(myQueue->counter != 1)
    {
        QUEUE* tempQueue = createQueue();

        for(int i=0;i<myQueue->counter;i++)
        {
            char* islem = myQueue->front->data;
            char* num1  = myQueue->front->next->data;
            char* num2  = myQueue->front->next->next->data;

            if(isdigit(*num1) && isdigit(*num2) && !isdigit(*islem) )
            {
                int number1 = atoi(num1);
                int number2 = atoi(num2);
                int result;

                switch (*islem)
                {
                    case '+':
                        result = number1+number2;
                        break;
                    case '-':
                        result = number1-number2;
                        break;
                    case '*':
                        result = number1*number2;
                        break;
                    case '/':
                        result = number1/number2;
                        break;
                    default:
                        break;
                }

                char* resultString = (char*) malloc(50 * sizeof(char));
                sprintf(resultString, "%d", result);

                enqueue(tempQueue,resultString);

                dequeue(myQueue);
                dequeue(myQueue);
                dequeue(myQueue);

                break;
            }
            else
            {
                enqueue(tempQueue,myQueue->front->data);
                dequeue(myQueue);
            }
        }

        for(int i=myQueue->counter ;i>=1;i--)
        {
            enqueue(tempQueue,myQueue->front->data);
            dequeue(myQueue);
        }

        myQueue = tempQueue;
        printQueue(myQueue);
        printf("-----------------------------------\n");
    }


    return 0;
}


void printQueue(QUEUE* queue)
{
    NODE* current = queue->front;
    while (current != NULL)
    {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}
