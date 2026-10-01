#include "header.h"


void saveBooks(void)
{
    FILE *fp;

    fp = fopen(BOOK_FILE, "wb");

    if(fp == NULL)
    {
        printf("\nUnable to save books.\n");
        return;
    }

    fwrite(&bookCount,
           sizeof(int),
           1,
           fp);

    fwrite(books,
           sizeof(Book),
           bookCount,
           fp);

    fclose(fp);

    printf("\nBook details saved successfully.\n");
}




void clearInputBuffer(void)
{
    int c;

    while((c = getchar()) != '\n' &&
          c != EOF);
}


void readLine(char *str, int size)
{
    fgets(str, size, stdin);

    str[strcspn(str, "\n")] = '\0';
}


void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    getchar();
}


int findBookByID(int id)
{
    for(int i = 0; i < bookCount; i++)
    {
        if(books[i].bookID == id)
            return i;
    }

    return -1;
}


void getCurrentDate(char *date)
{
    time_t t = time(NULL);

    struct tm *tm_info =
        localtime(&t);

    strftime(date,
             11,
             "%Y-%m-%d",
             tm_info);
}


time_t convertDate(const char *date)
{
    struct tm tm_date = {0};

    sscanf(date,
           "%d-%d-%d",
           &tm_date.tm_year,
           &tm_date.tm_mon,
           &tm_date.tm_mday);

    tm_date.tm_year -= 1900;
    tm_date.tm_mon -= 1;
    tm_date.tm_hour = 12;

    return mktime(&tm_date);
}


void addDaysToDate(const char *date,
                   int days,
                   char *result)
{
    time_t t = convertDate(date);

    t += (time_t)days * 24 * 60 * 60;

    struct tm *tm_info =
        localtime(&t);

    strftime(result,
             11,
             "%Y-%m-%d",
             tm_info);
}


int daysBetween(const char *from,
                const char *to)
{
    time_t t1 = convertDate(from);
    time_t t2 = convertDate(to);

    return (int)
           (difftime(t2, t1) /
           (24 * 60 * 60));
}
