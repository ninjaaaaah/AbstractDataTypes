#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER 420

struct queue
{
    struct person *head;
    struct person *tail;
};

struct person
{
    int index;
    char first[BUFFER];
    char last[BUFFER];
    struct person *next;
};

void push_queue(struct queue *q, struct person *p)
{
    struct person *np;
    np = malloc(sizeof(struct person));
    np->index = p->index;
    strcpy(np->first, p->first);
    strcpy(np->last, p->last);
    np->next = NULL;

    if (!q->tail)
    {
        q->head = np;
        q->tail = np;
    }
    else
    {
        q->tail->next = np;
        q->tail = np;
    }
}

struct person *create_person(int index, char *fname, char *lname)
{
    struct person *p;
    p = malloc(sizeof(struct person));

    p->index = index;
    strcpy(p->first, fname);
    strcpy(p->last, lname);
    return p;
}

void traverse(struct queue *q)
{
    while (q->head)
    {
        printf("%d %s, %s\n", q->head->index, q->head->last, q->head->first);
        struct person *tp = q->head;
        q->head = tp->next;
    }
}

int main()
{
    char *FNames[3] = {"Jarred", "Angela", "Wilson"};
    char *LNames[3] = {"Luzada", "Zabala", "Tan"};

    struct queue *q;
    q = malloc(sizeof(struct queue));

    for (int i = 0; i < 3; i++)
    {
        struct person *p = create_person(i, FNames[i], LNames[i]);
        push_queue(q, p);
        free(p);
    }

    traverse(q);
}