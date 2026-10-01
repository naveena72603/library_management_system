#include "header.h"

void issueBook(void)
{
    int bookID;
    int index;
    Issue newIssue;

    if(issueCount >= MAX_ISSUES)
    {
        printf("\nIssue storage is full.\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &bookID);
    clearInputBuffer();

    index = findBookByID(bookID);

    if(index == -1)
    {
        printf("\nBook not found.\n");
        return;
    }

    if(books[index].quantity <= 0)
    {
        printf("\nBook is currently unavailable.\n");
        return;
    }

    printf("Enter User Name: ");
    readLine(newIssue.userName, sizeof(newIssue.userName));

    newIssue.issueID = issueCount + 1;
    newIssue.bookID = bookID;

    strcpy(newIssue.bookTitle, books[index].title);

    getCurrentDate(newIssue.issueDate);

    addDaysToDate(newIssue.issueDate,
                  7,
                  newIssue.dueDate);

    strcpy(newIssue.returnDate, "-");

    newIssue.fineAmount = 0;
    newIssue.returned = 0;

    issues[issueCount++] = newIssue;

    books[index].quantity--;

    printf("\n====================================\n");
    printf("          BOOK ISSUED\n");
    printf("====================================\n");

    printf("Issue ID   : %d\n", newIssue.issueID);
    printf("Book ID    : %d\n", newIssue.bookID);
    printf("Book Title : %s\n", newIssue.bookTitle);
    printf("User Name  : %s\n", newIssue.userName);
    printf("Issue Date : %s\n", newIssue.issueDate);
    printf("Due Date   : %s\n", newIssue.dueDate);
}





