#include "header.h"

void addBook(void)
{
    Book b;

    if(bookCount >= MAX_BOOKS)
    {
        printf("\nBook storage is full.\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &b.bookID);
    clearInputBuffer();

    if(findBookByID(b.bookID) != -1)
    {
        printf("Book ID already exists.\n");
        return;
    }

    printf("Enter Book Title: ");
    readLine(b.title, sizeof(b.title));

    printf("Enter Author Name: ");
    readLine(b.author, sizeof(b.author));

    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);
    clearInputBuffer();

    if(b.quantity < 0)
    {
        printf("Quantity cannot be negative.\n");
        return;
    }

    books[bookCount++] = b;

    printf("\nBook added successfully.\n");
}



