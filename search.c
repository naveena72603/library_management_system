#include "header.h"

void searchBook(void)
{
    int choice;
    int id;
    char name[100];
    int found = 0;

    printf("\n====================================\n");
    printf("           SEARCH BOOK\n");
    printf("====================================\n");
    printf("1. Search By Book ID\n");
    printf("2. Search By Book Name\n");
    printf("3. Search By Author\n");
    printf("Enter choice: ");

    scanf("%d", &choice);
    clearInputBuffer();

    if(choice == 1)
    {
        printf("Enter Book ID: ");
        scanf("%d", &id);
        clearInputBuffer();

        int index = findBookByID(id);

        if(index == -1)
        {
            printf("\nBook not found.\n");
        }
        else
        {
            printf("\nBook ID  : %d", books[index].bookID);
            printf("\nTitle    : %s", books[index].title);
            printf("\nAuthor   : %s", books[index].author);
            printf("\nQuantity : %d\n", books[index].quantity);
        }
    }
    else if(choice == 2)
    {
        printf("Enter Book Name: ");
        readLine(name, sizeof(name));

        for(int i = 0; i < bookCount; i++)
        {
            if(strstr(books[i].title, name) != NULL)
            {
                printf("\nBook ID  : %d", books[i].bookID);
                printf("\nTitle    : %s", books[i].title);
                printf("\nAuthor   : %s", books[i].author);
                printf("\nQuantity : %d\n", books[i].quantity);

                found = 1;
            }
        }

        if(!found)
            printf("\nBook not found.\n");
    }
    else if(choice == 3)
    {
        printf("Enter Author Name: ");
        readLine(name, sizeof(name));

        for(int i = 0; i < bookCount; i++)
        {
            if(strstr(books[i].author, name) != NULL)
            {
                printf("\nBook ID  : %d", books[i].bookID);
                printf("\nTitle    : %s", books[i].title);
                printf("\nAuthor   : %s", books[i].author);
                printf("\nQuantity : %d\n", books[i].quantity);

                found = 1;
            }
        }

        if(!found)
            printf("\nBook not found.\n");
    }
    else
    {
        printf("\nInvalid choice.\n");
    }
}

