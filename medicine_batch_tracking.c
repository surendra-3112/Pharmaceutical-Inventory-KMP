
#include <stdio.h>
#include <string.h>

#define MAX 100

void computeLPS(char pattern[], int lps[])
{
    int i = 1, len = 0;
    int m = strlen(pattern);

    lps[0] = 0;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[MAX];

    int i = 0, j = 0;

    computeLPS(pattern, lps);

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            return 1;
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return 0;
}

int main()
{
    int n, i, count = 0;
    char id[MAX][30];
    char batch[MAX][50];
    char pattern[50];

    printf("Enter number of medicine records: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of records.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter Medicine ID: ");
        scanf("%29s", id[i]);

        printf("Enter Batch Number: ");
        scanf("%49s", batch[i]);
    }

    printf("\nEnter batch number to search: ");
    scanf("%49s", pattern);

    printf("\n--- SEARCH RESULTS ---\n");

    for (i = 0; i < n; i++)
    {
        if (KMPSearch(batch[i], pattern))
        {
            printf("\nMatch found: %s", id[i]);
            printf("\nBatch: %s\n", batch[i]);
            count++;
        }
    }

    if (count == 0)
        printf("\nNo matching records found.\n");

    printf("\nTotal matching records: %d\n", count);

    return 0;
}
