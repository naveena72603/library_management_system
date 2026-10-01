#include "header.h"

Book books[MAX_BOOKS];
Issue issues[MAX_ISSUES];

int bookCount = 0;
int issueCount = 0;

int main(void)
{
    int choice;

    do
    {
        printf("\n");
        printf("+----------------------------------------+\n");
        printf("|         BOOK MANAGEMENT MENU            |\n");
        printf("+----------------------------------------+\n");
        printf("| 1. Add New Book                        |\n");
        printf("| 2. Remove Book                         |\n");
        printf("| 3. Search Book                         |\n");
        printf("| 4. List Books                          |\n");
        printf("| 5. Save Books                          |\n");
        printf("| 6. Issue Book                          |\n");
        printf("| 7. Return Book                         |\n");
        printf("| 8. List Issued Books                   |\n");
        printf("| 9. Save Issued Book Details            |\n");
        printf("| 10. Exit                               |\n");
        printf("+----------------------------------------+\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice)
        {
            case 1:
                addBook();
                pauseScreen();
                break;

            case 2:
                removeBook();
                pauseScreen();
                break;

            case 3:
                searchBook();
                pauseScreen();
                break;

            case 4:
                listBooks();
                pauseScreen();
                break;

            case 5:
                saveBooks();
                pauseScreen();
                break;

            case 6:
                issueBook();
                pauseScreen();
                break;

            case 7:
                returnBook();
                pauseScreen();
                break;

            case 8:
                listIssuedBooks();
                pauseScreen();
                break;

            case 9:
                saveIssuedBooks();
                pauseScreen();
                break;

            case 10:
                saveBooks();
                saveIssuedBooks();

                printf("\nThank you for using Library Management System.\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while(choice != 10);

    return 0;
}
