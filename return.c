#include "header.h"

void returnBook(void)
{
    int bookID;
    int issueIndex = -1;

    printf("\nEnter Book ID: ");
    scanf("%d", &bookID);
    clearInputBuffer();

    for(int i = 0; i < issueCount; i++)
    {
        if(issues[i].bookID == bookID &&
           issues[i].returned == 0)
        {
            issueIndex = i;
            break;
        }
    }

    if(issueIndex == -1)
    {
        printf("\nActive issue record not found.\n");
        return;
    }

    char returnDate[11];

    getCurrentDate(returnDate);

    strcpy(issues[issueIndex].returnDate,
           returnDate);

    int lateDays = daysBetween(
        issues[issueIndex].dueDate,
        returnDate
    );

    if(lateDays > 0)
    {
        issues[issueIndex].fineAmount =
            lateDays * FINE_PER_DAY;
    }
    else
    {
        issues[issueIndex].fineAmount = 0;
    }

    issues[issueIndex].returned = 1;

    int bookIndex =
        findBookByID(bookID);

    if(bookIndex != -1)
        books[bookIndex].quantity++;

    printf("\n====================================\n");
    printf("          BOOK RETURNED\n");
    printf("====================================\n");

    printf("Return Date : %s\n", returnDate);

    if(lateDays > 0)
    {
        printf("Late Days   : %d\n", lateDays);
        printf("Fine        : Rs. %.2f\n",
               issues[issueIndex].fineAmount);
    }
    else
    {
        printf("Returned on time.\n");
        printf("Fine        : Rs. 0.00\n");
    }
}

