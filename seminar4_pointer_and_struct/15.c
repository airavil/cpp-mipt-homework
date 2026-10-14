#include <stdio.h>
struct node
{
    int value;
    struct node* ptr;
};
typedef struct node Node;
int main()
{
    Node n1;
    Node n2;
    Node n3;
    n1.value = 1;
    n2.value = 2;
    n3.value = 3;
    n1.ptr = &n2;
    n2.ptr = &n3;
    n3.ptr = &n1;
    Node* current = &n1;
    while (1)
    {
        printf("%d\n", (*current).value);
        current = (*current).ptr;
    }
}