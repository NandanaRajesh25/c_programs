#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct
{
    char dname[10];
    char fname[10][10];
    int fcnt;
} dir[10];

void createDirectory(int *dcnt);
void createFile(int dcnt);
void deleteFile(int dcnt);
void searchFile(int dcnt);
void displayDirectories(int dcnt);

int main()
{
    int i, ch, dcnt = 0;

    while (1)
    {
        printf("\n1.Create Directory\n2.Create File\n3.Delete File\n4.Search File\n5.Display\n6.Exit\nEnter Your Choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            createDirectory(&dcnt);
            break;
        case 2:
            createFile(dcnt);
            break;
        case 3:
            deleteFile(dcnt);
            break;
        case 4:
            searchFile(dcnt);
            break;
        case 5:
            displayDirectories(dcnt);
            break;
        case 6:
            exit(0);
        default:
            printf("\nInvalid Choice! Please try again.");
        }
    }

    return 0;
}

void createDirectory(int *dcnt)
{
    if (*dcnt >= 10) {
        printf("\nMaximum directory limit reached.");
        return;
    }

    printf("\nEnter Name of Directory:");
    scanf("%s", dir[*dcnt].dname);
    dir[*dcnt].fcnt = 0;
    (*dcnt)++;
    printf("\nDirectory created");
}

void createFile(int dcnt)
{
    int i;
    char d[30];

    printf("\nEnter Name of the Directory:");
    scanf("%s", d);
    for (i = 0; i < dcnt; i++)
    {
        if (strcmp(d, dir[i].dname) == 0)
        {
            if (dir[i].fcnt >= 10) {
                printf("\nMaximum file limit reached in directory %s", d);
                return;
            }

            printf("\nEnter Name of the File to Create:");
            scanf("%s", dir[i].fname[dir[i].fcnt]);
            dir[i].fcnt++;
            printf("\nFile created");
            return;
        }
    }
    printf("\nDirectory %s Not Found!", d);
}

void deleteFile(int dcnt)
{
    int i, k;
    char d[30], f[30];

    printf("\nEnter Name of the Directory:");
    scanf("%s", d);
    for (i = 0; i < dcnt; i++)
    {
        if (strcmp(d, dir[i].dname) == 0)
        {
            printf("\nEnter Name of the File to Delete:");
            scanf("%s", f);
            for (k = 0; k < dir[i].fcnt; k++)
            {
                if (strcmp(f, dir[i].fname[k]) == 0)
                {
                    printf("\nFile %s Deleted", f);
                    dir[i].fcnt--;
                    strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt]);
                    return;
                }
            }
            printf("\nFile %s Not Found!", f);
            return;
        }
    }
    printf("\nDirectory %s Not Found!", d);
}

void searchFile(int dcnt)
{
    int i, k;
    char d[30], f[30];

    printf("\nEnter Name of the Directory:");
    scanf("%s", d);
    for (i = 0; i < dcnt; i++)
    {
        if (strcmp(d, dir[i].dname) == 0)
        {
            printf("\nEnter the Name of the File to Search:");
            scanf("%s", f);
            for (k = 0; k < dir[i].fcnt; k++)
            {
                if (strcmp(f, dir[i].fname[k]) == 0)
                {
                    printf("\nFile %s Found", f);
                    return;
                }
            }
            printf("\nFile %s Not Found!", f);
            return;
        }
    }
    printf("\nDirectory %s Not Found!", d);
}

void displayDirectories(int dcnt)
{
    int i, k;

    if (dcnt == 0)
    {
        printf("\nNo Directories!");
        return;
    }

    printf("\nDirectory\tFiles");
    for (i = 0; i < dcnt; i++)
    {
        printf("\n%s\t\t", dir[i].dname);
        for (k = 0; k < dir[i].fcnt; k++)
        {
            printf("\t%s", dir[i].fname[k]);
        }
    }
}
