#include "header.h"
void removeBook(void)
{
    int id;
    int index;

    printf("\nEnter Book ID to remove: ");
    scanf("%d", &id);
    clearInputBuffer();

    index = findBookByID(id);

    if(index == -1)
    {
        printf("\nBook not found.\n");
        return;
    }

    for(int i = index; i < bookCount - 1; i++)
    {
        books[i] = books[i + 1];
    }

    bookCount--;

    printf("\nBook removed successfully.\n");
}
