#include "header.h"

void saveIssuedBooks(void)
{
    FILE *fp;

    fp = fopen(ISSUE_FILE, "wb");

    if(fp == NULL)
    {
        printf("\nUnable to save issued book details.\n");
        return;
    }

    fwrite(&issueCount,
           sizeof(int),
           1,
           fp);

    fwrite(issues,
           sizeof(Issue),
           issueCount,
           fp);

    fclose(fp);

    printf("\nIssued book details saved successfully.\n");
}

