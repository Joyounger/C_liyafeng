#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct stationItem
{
    int sn;
    float cost;
    float p;
} stationItem;

struct queue
{
    stationItem *qe;
    int front;
    int tail;
    int maxlen;
};

int initQueue(struct queue *q, int max)
{
    if (max <= 0)
    {
        printf("max is invalid!\n");
        return -1;
    }
    q -> maxlen = max;
    q -> qe = malloc(max * sizeof(stationItem));
    if (!q -> qe)
    {
        printf("memory alloc error!\n");
        return -1;
    }
    q->front = q -> tail = 0;
    return 0;
}

int enQueue( struct queue *q, stationItem x)
{
    if ((q->tail + 1) % q->maxlen ==  q->front)
    {
        printf("queue is full\n");
    }

    q->tail = (q->tail + 1) % q->maxlen;
    q->qe[q->tail] = x;
    return 0;
}

 stationItem deQueue( struct queue *q)
{
    if (q->front == q->tail)
    {
        printf("queue is empty!\n");
    }
    q->front = (q->front + 1) % q->maxlen;
    return q->qe[q->front];
}

int emptyQueue (struct queue *q)
{
    if (q->front == q->tail)
    {
        return 1;
    } else
        return 0;
}

void clearQueue(struct queue *q)
{
    if (q->qe != NULL)
    {
        free(q->qe);
        q->qe = NULL;
        q->front = q->tail = 0;
        q->maxlen = 0;
    }
}

int main()
{
    float D1 = 0.0;
    float C = 0.0;
    float D2 = 0.0;
    float distance  = 0.0;
    float P = 0;

    int N = 0;
    float left = 0.0, use = 0.0, cost = 0.0;
    int i, j, temp;
    int PN[MAX];
    float D[MAX];
    float p[MAX];
    float gas[MAX];
    struct queue q;
    stationItem sI;

    scanf("%f, %f, %f, %f, %d", &D1, &C, &D2, &P, &N);
    for (i = 1; i <= N; i++)
    {
        scanf("%f, %f", &D[i], &p[i]);
    }

    initQueue(&q, MAX);
    D[0] = 0.0;
    p[0] = P;
    D[N+1] = D1;

    for (i = 0; i <= N; i++)
    {
        if (D[i + 1] - D[i] > C*D2)
        {
            printf("error!\n");
            return -1;
        }
    }
    for (i = 0; i <= N; i++)
    {
        PN[i] = i;
    }
    for (i = 0; i <= N-1; i++)
    {
        for (j = i+1; j <= N; j++)
        {
            if (p[PN[i]] > p[PN[j]])
            {
                temp = PN[i];
                PN[i] = PN[j];
                PN[j] = temp;
            }
        }
    }
    for (i = 0; i <= N; i++)
    {
        cost = 0;
        gas[i] = C - left;
        for (j = 0; j <= i - 1; j++ )
        {
            if (p[j] > p[i])
            {
                gas[i] += gas[j];
                gas[j] = 0;
            }
        }
        distance = D[i+1] - D[i];
        use = distance / D2;
        left = C - use;
        for (j = 0; j <= N; j++)
        {
            if (gas[PN[j]] > 0)
            {
                if (gas[PN[j]] < use)
                {
                    use  -= gas[PN[j]]; 
                    cost = gas[PN[j]] * p[PN[j]];
                    gas[PN[j]] = 0;
                    sI.sn = i + 1;
                    sI.cost = cost;
                    sI.p =p[PN[j]];
                    enQueue(&q, sI);
                } else {
                    gas[PN[j]] = gas[PN[j]] - use;
                    cost = use * p[PN[j]];
                    sI.sn = i + 1;
                    sI.cost = cost;
                    sI.p = p[PN[j]];
                    enQueue(&q, sI);
                    break;
                }
            }
        }
    }
    
    cost = 0;
    printf("\n");
    if (emptyQueue(&q))
    {
        printf("No solution\n");
    }
    while (!emptyQueue(&q))
    {
        sI = deQueue(&q);
        cost += sI.cost;
        printf("Student No. %d, Costs = %0.2f, price = %0.2f\n", sI.sn, sI.cost, sI.p);
    }
    printf("Cost = %0.2f", cost);
    clearQueue(&q);
    return 0;
}