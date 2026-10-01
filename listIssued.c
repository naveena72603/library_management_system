#include "header.h"

void listIssuedBooks(void)
{
    if(issueCount == 0)
    {
        printf("\nNo issue records found.\n");
        return;
    }

    printf("\n");
    printf("================================================================================\n");

    printf("%-8s %-8s %-20s %-20s %-12s %-12s %-12s %-10s\n",
           "IssueID",
           "BookID",
           "Book Title",
           "User Name",
           "Issue Date",
           "Due Date",
           "Return Date",
           "Fine");

    printf("================================================================================\n");

    for(int i = 0; i < issueCount; i++)
    {
        printf("%-8d %-8d %-20s %-20s %-12s %-12s %-12s Rs.%-7.2f\n",
               issues[i].issueID,
               issues[i].bookID,
               issues[i].bookTitle,
               issues[i].userName,
               issues[i].issueDate,
               issues[i].dueDate,
               issues[i].returnDate,
               issues[i].fineAmount);
    }
}
