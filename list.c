#include "header.h"

void listBooks(void)
{
    if(bookCount == 0)
    {
        printf("\nNo books found.\n");
        return;
    }

    printf("\n");
    printf("===============================================================\n");
    printf("%-10s %-25s %-20s %-10s\n",
           "Book ID", "Title", "Author", "Quantity");
    printf("===============================================================\n");

    for(int i = 0; i < bookCount; i++)
    {
        printf("%-10d %-25s %-20s %-10d\n",
               books[i].bookID,
               books[i].title,
               books[i].author,
               books[i].quantity);
    }
}
