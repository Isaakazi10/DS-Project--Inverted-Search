#include "is.h"

int update_database(File_node *fhead, Main_node **hashtable)
{
    char file_name[30];
    printf("\n[---( Enter File name to save Data Base )---] ==>  ");
    scanf("%s", file_name);

    FILE *fptr = fopen(file_name, "r");
    if (fptr == NULL)
    {
        printf("\n[-- ERROR --: ( %s Not Found )--]\n", file_name);
        return FAILURE;
    }
    else
    {
        ;
    }
}