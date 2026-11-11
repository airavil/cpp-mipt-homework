#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Error checked malloc
static void* ecmalloc(size_t n)
{
    void* p = malloc(n);
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    return p;
}


#define DECLARE_LIST(type) \
struct node_##type \
{ \
    type value; \
    struct node_##type* next; \
    struct node_##type* prev; \
}; \
typedef struct node_##type Node_##type; \
\
struct list_##type \
{ \
    Node_##type* head; \
    Node_##type* tail; \
    size_t size; \
}; \
typedef struct list_##type List_##type; \
\
Node_##type* node_##type##_create(type value) \
{ \
    Node_##type* p = (Node_##type*)ecmalloc(sizeof(Node_##type)); \
    p->value = value; \
    p->next = NULL; \
    p->prev = NULL; \
    return p; \
} \
\
void list_##type##_push_back(List_##type* pl, type value) \
{ \
    Node_##type* new_node = node_##type##_create(value); \
    new_node->prev = pl->tail; \
    if (pl->tail != NULL) \
        pl->tail->next = new_node; \
    else \
        pl->head = new_node; \
    pl->tail = new_node; \
    pl->size += 1; \
} \
\
List_##type list_##type##_init(size_t n) \
{ \
    List_##type l; \
    l.head = NULL; \
    l.tail = NULL; \
    l.size = 0; \
    for (size_t i = 0; i < n; ++i) \
        list_##type##_push_back(&l, (type){0}); \
    return l; \
} \
\
void list_##type##_print(const List_##type* pl, void (*print_elem)(type)) \
{ \
    printf("list_" #type ": "); \
    Node_##type* p = pl->head; \
    while (p != NULL) \
    { \
        print_elem(p->value); \
        printf(" "); \
        p = p->next; \
    } \
    printf("\n"); \
} \
\
type list_##type##_pop_back(List_##type* pl) \
{ \
    if (pl->size == 0) \
    { \
        fprintf(stderr, "list_" #type "_pop_back: list is empty.\n"); \
        exit(1); \
    } \
    Node_##type* last = pl->tail; \
    type value = last->value; \
    pl->tail = last->prev; \
    if (pl->tail != NULL) \
        pl->tail->next = NULL; \
    else \
        pl->head = NULL; \
    free(last); \
    pl->size -= 1; \
    return value; \
} \
\
void list_##type##_push_front(List_##type* pl, type value) \
{ \
    Node_##type* new_node = node_##type##_create(value); \
    new_node->next = pl->head; \
    if (pl->head != NULL) \
        pl->head->prev = new_node; \
    else \
        pl->tail = new_node; \
    pl->head = new_node; \
    pl->size += 1; \
} \
\
type list_##type##_pop_front(List_##type* pl) \
{ \
    if (pl->size == 0) \
    { \
        fprintf(stderr, "list_" #type "_pop_front: list is empty.\n"); \
        exit(1); \
    } \
    Node_##type* first = pl->head; \
    type value = first->value; \
    pl->head = first->next; \
    if (pl->head != NULL) \
        pl->head->prev = NULL; \
    else \
        pl->tail = NULL; \
    free(first); \
    pl->size -= 1; \
    return value; \
} \
\
Node_##type* list_##type##_erase(List_##type* pl, Node_##type* p) \
{ \
    if (p == NULL) \
        return NULL; \
    Node_##type* next_node = p->next; \
    Node_##type* prev_node = p->prev; \
    if (prev_node != NULL) \
        prev_node->next = next_node; \
    else \
        pl->head = next_node; \
    if (next_node != NULL) \
        next_node->prev = prev_node; \
    else \
        pl->tail = prev_node; \
    free(p); \
    pl->size -= 1; \
    return next_node; \
} \
\
void list_##type##_splice(List_##type* plist, Node_##type* p, List_##type* pother) \
{ \
    if (pother->size == 0) \
        return; \
    Node_##type* first = pother->head; \
    Node_##type* last = pother->tail; \
    if (p != NULL) \
    { \
        Node_##type* prev_node = p->prev; \
        first->prev = prev_node; \
        if (prev_node != NULL) \
            prev_node->next = first; \
        else \
            plist->head = first; \
        last->next = p; \
        p->prev = last; \
    } \
    else \
    { \
        first->prev = plist->tail; \
        if (plist->tail != NULL) \
            plist->tail->next = first; \
        else \
            plist->head = first; \
        last->next = NULL; \
        plist->tail = last; \
    } \
    plist->size += pother->size; \
    pother->head = NULL; \
    pother->tail = NULL; \
    pother->size = 0; \
} \
\
void list_##type##_destroy(List_##type* pl) \
{ \
    Node_##type* p = pl->head; \
    while (p != NULL) \
    { \
        Node_##type* next_node = p->next; \
        free(p); \
        p = next_node; \
    } \
    pl->head = NULL; \
    pl->tail = NULL; \
    pl->size = 0; \
} \
\
void list_##type##_advance(Node_##type** pp, size_t n) \
{ \
    Node_##type* p = *pp; \
    for (size_t i = 0; i < n; ++i) \
    { \
        if (p == NULL) \
            break; \
        p = p->next; \
    } \
    *pp = p; \
}
