#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

struct bookh
{
char* title;
int pages;
float price;
};
typedef struct bookh Bookh;

int main()
{
    int* pa = malloc(sizeof(size_t));
    *pa = 123;
    printf("%i\n", *pa);
    free(pa);

    char* pb = malloc(9 * sizeof(char));
    strcpy(pb, "Elephant");
    printf("%s\n", pb);
    free(pb);

    char** pc = malloc(sizeof(char*));
    *pc = malloc(14*sizeof(char));
    strcpy(*pc, "Cats and Dogs");
    printf("%s\n", *pc);
    free(*pc);
    free(pc);

    Book* pd = malloc(sizeof(Book));
    strcpy(pd -> title, "Don Quixote");
    pd -> pages = 1000;
    pd -> price = 750.0;
    printf("%s %i %f\n", pd -> title, pd -> pages, pd -> price);
    free(pd);

    Book a = {"Don Quixote", 1000, 750.0};
    Book** pe = malloc(sizeof(Book*));
    *pe = &a;
    printf("%s %i %f\n", (*pe) -> title, (*pe) -> pages, (*pe) -> price);
    free(pe);

    Book** pf = malloc(sizeof(Book*));
    *pf = malloc(sizeof(Book));
    strcpy((*pf) -> title, "Don Quixote");
    (*pf) -> pages = 1000;
    (*pf) -> price = 750.0;
    printf("%s %i %f\n", (*pf) -> title, (*pf) -> pages, (*pf) -> price);
    free(*pf);
    free(pf);

    Book* pg = malloc(sizeof(Book)*3);
    strcpy(pg[0].title, "Don Quixote");
    pg[0].pages = 1000;
    pg[0].price = 750.0;
    strcpy(pg[1].title, "Oblomov");
    pg[1].pages = 400;
    pg[1].price = 250.0;
    strcpy(pg[2].title, "The Odyssey");
    pg[2].pages = 500;
    pg[2].price = 500.0;
    printf("%s %i %f\n", pg[0].title, pg[0].pages, pg[0].price);
    printf("%s %i %f\n", pg[1].title, pg[1].pages, pg[1].price);
    printf("%s %i %f\n", pg[2].title, pg[2].pages, pg[2].price);
    free(pg);

    Bookh* ph = malloc(sizeof(Bookh));
    ph -> title = malloc(sizeof(char)*12);
    strcpy(ph -> title, "Don Quixote");
    ph -> pages = 1000;
    ph -> price = 750.0;
    printf("%s %i %f\n", ph -> title, ph -> pages, ph -> price);
    free(ph -> title);
    free(ph);
}