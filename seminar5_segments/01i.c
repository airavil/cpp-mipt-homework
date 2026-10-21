#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct book
{
char* title;
int pages;
float price;
};
typedef struct book Book;

struct library
{
Book* books;
int number_of_books;
};
typedef struct library Library;

void library_create(Library* p, int n)
{
    p -> books = (Book*)malloc(n * sizeof(Book));
    p -> number_of_books = n;
    for (int i = 0; i < n; i++)
        (p -> books)[i].title = NULL;
}

void  library_set(Library a, int i, char* str, int pg, float pr)
{
    free(a.books[i].title);
    a.books[i].title = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(a.books[i].title, str);
    a.books[i].pages = pg;
    a.books[i].price = pr;
}

Book* library_get(const Library a, int i)
{
    return a.books + i;
}

void library_print(const Library a)
{
    for (Book* p = a.books; p < a.books + a.number_of_books; p++)
        printf("Title: %s\nPages: %i\nPrice %.1f\n\n", p -> title, p -> pages, p -> price);
}

void library_destroy(Library* p)
{
    for (int i = 0; i < p -> number_of_books; i++)
    {
        free((p -> books)[i].title);
        (p -> books)[i].title = NULL;
    }
    free(p -> books);
    p->books = NULL;
    p->number_of_books = 0;
}

void print_book(const Book* p)
{
    printf("Title: %s\nPages: %i\nPrice: %.1f\n\n", p -> title, p -> pages, p -> price);
}

int main()
{
    Library a;
    library_create(&a, 3);
    library_set(a, 0, "Don Quixote", 1000, 750.0);
    library_set(a, 1, "Oblomov", 400, 250.0);
    library_set(a, 2, "The Odyssey", 500, 500.0);
    library_print(a);
    print_book(library_get(a, 1));
    library_destroy(&a);
}