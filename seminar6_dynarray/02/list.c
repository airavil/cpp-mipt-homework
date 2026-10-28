#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

// Error checked malloc
void* ecmalloc(size_t n)
{
    void* p = malloc(n);
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    return p;
}

static Node* create_node(int value)
{
    Node* p = ecmalloc(sizeof(Node));
    p->value = value;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

List init(size_t n)
{
    List l;
    l.head = NULL;
    l.tail = NULL;
    l.size = 0;

    for (size_t i = 0; i < n; ++i)
        push_back(&l, 0);

    return l;
}

void print(const List* pl)
{
    printf("list: ");
    Node* p = pl->head;
    while (p != NULL)
    {
        printf("%i ", p->value);
        p = p->next;
    }
    printf("\n");
}

void push_back(List* pl, int value)
{
    Node* new_node = create_node(value);
    new_node->prev = pl->tail;

    if (pl->tail != NULL)
        pl->tail->next = new_node;
    else
        pl->head = new_node;

    pl->tail = new_node;
    pl->size += 1;
}

int pop_back(List* pl)
{
    if (pl->size == 0)
    {
        fprintf(stderr, "pop_back: list is empty.\n");
        exit(1);
    }

    Node* last = pl->tail;
    int value = last->value;

    pl->tail = last->prev;
    if (pl->tail != NULL)
        pl->tail->next = NULL;
    else
        pl->head = NULL;

    free(last);
    pl->size -= 1;
    return value;
}

void push_front(List* pl, int value)
{
    Node* new_node = create_node(value);
    new_node->next = pl->head;

    if (pl->head != NULL)
        pl->head->prev = new_node;
    else
        pl->tail = new_node;

    pl->head = new_node;
    pl->size += 1;
}

int pop_front(List* pl)
{
    if (pl->size == 0)
    {
        fprintf(stderr, "pop_front: list is empty.\n");
        exit(1);
    }

    Node* first = pl->head;
    int value = first->value;

    pl->head = first->next;
    if (pl->head != NULL)
        pl->head->prev = NULL;
    else
        pl->tail = NULL;

    free(first);
    pl->size -= 1;
    return value;
}

Node* erase(List* pl, Node* p)
{
    if (p == NULL)
        return NULL;

    Node* next_node = p->next;
    Node* prev_node = p->prev;

    if (prev_node != NULL)
        prev_node->next = next_node;
    else
        pl->head = next_node;

    if (next_node != NULL)
        next_node->prev = prev_node;
    else
        pl->tail = prev_node;

    free(p);
    pl->size -= 1;
    return next_node;
}

void splice(List* plist, Node* p, List* pother)
{
    if (pother->size == 0)
        return;

    Node* first = pother->head;
    Node* last = pother->tail;

    if (p != NULL)
    {
        Node* prev_node = p->prev;

        first->prev = prev_node;
        if (prev_node != NULL)
            prev_node->next = first;
        else
            plist->head = first;

        last->next = p;
        p->prev = last;
    }
    else
    {
        first->prev = plist->tail;
        if (plist->tail != NULL)
            plist->tail->next = first;
        else
            plist->head = first;

        last->next = NULL;
        plist->tail = last;
    }

    plist->size += pother->size;

    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}

void destroy(List* pl)
{
    Node* p = pl->head;
    while (p != NULL)
    {
        Node* next_node = p->next;
        free(p);
        p = next_node;
    }

    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}

void advance(Node** pp, size_t n)
{
    Node* p = *pp;
    for (size_t i = 0; i < n; ++i)
    {
        if (p == NULL)
            break;
        p = p->next;
    }
    *pp = p;
}