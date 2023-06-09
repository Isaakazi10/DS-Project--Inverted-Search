/*
Name : Isaa kazi
Completion Date : May 15 2023 Project Name : Inverted Search
*/
#include "is.h"

int main(int argc, char **argv)
{
    // Variable used in this file.c
    int res = 0, choice = 0;
    char cont;
    int Flag = 0;

    // If argc is less than 2 then return FAIlURE.
    if (argc <= 1)
    {
        printf("\n[-- ERROR --: ( Argument count should be greater than 1 )--]\n");
        printf("\n[-- USAGE --: ( ./output file1.txt file2.txt file3.txt )--]\n");
        return FAILURE;
    }

    // Creating a File_node pointer.
    File_node *fhead = NULL;

    // Calling read_and_validation function and if it return SUCCESS then read_and_validation is SUCCESSFUL else FAILURE.
    if (read_and_validation(argc, argv, &fhead) == SUCCESS)
    {
        printf("\n[---( Read and validate -> SUCCESSFUL )---]\n");
    }
    else
    {
        printf("\n\n[-- ERROR --: ( Read and validate -> FAILURE )--]\n\n");
        return FAILURE;
    }

    // Creating a hashtable with 27 index and if hashtable is eqaul to NULL then return FAILURE.
    Main_node *hashtable[27] = {NULL};
    if (hashtable == NULL)
    {
        printf("\n\n[-- ERROR --: ( Creation on mhead pointer -> FAILURE )--]\n\n");
        return FAILURE;
    }

    while (1)
    {
        // Make a choice.
        printf("\n[--- ( Select Your Choice among following OPTIONS ) ---]");
        printf("\n1-> Create Database\n2-> Display Database\n3-> Search Database\n4-> Save Database\n5-> Update Database\n");
        printf("\n[---( Your Choice )---] ==>  ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (Flag == 1)
            {
                printf("\n[-- ERROR --: ( DataBase has already been Updated )--]\n");
                printf("[-- ERROR --: ( Database Create -> FAILURE )--]\n\n");
            }

            if ((create_database(fhead, hashtable)) == SUCCESS)
            {
                File_node *ftemp = fhead;
                printf("\n[---( Creating Database for");
                while (ftemp != NULL)
                {
                    printf(" %s", ftemp->file_name);
                    ftemp = ftemp->next;
                }

                Flag = 1;
                printf(" -> SUCCESSFUL )---]");
            }
            else
            {
                printf("\n\n[-- ERROR --: ( Creating Database -> FAILURE )--]\n\n");
            }
            break;

        case 2:
            if (display_database(hashtable, fhead) == SUCCESS)
            {
                printf("\n[---( Display Database -> SUCCESSFUL )---]");
            }
            else
            {
                printf("\n\n[-- ERROR --: ( Display Database -> FAILURE )--]\n");
                printf("[-- ERROR --: ( Data Base has not been Created )--]\n\n");
            }
            break;

        case 3:
            if ((res = search_database(hashtable, fhead)) == SUCCESS)
            {
                printf("\n[---( Search Database -> SUCCESSFUL )---]");
            }
            else if (res == DATA_NOT_FOUND)
            {
                printf("\n\n[-- ERROR --: ( Search Database -> FAILURE )--]\n");
                printf("[-- ERROR --: ( Data not Found )--]\n\n");
            }
            else
            {
                printf("\n\n[-- ERROR --: ( Search Database -> FAILURE )--]\n");
                printf("[-- ERROR --: ( Data Base has not been Created )--]\n\n");
            }
            break;

        case 4:
            if ((res = save_database(fhead, hashtable)) == SUCCESS)
            {
                printf("\n[---( Save Database -> SUCCESSFUL )---]");
            }
            else if (res == DATA_PRESENT)
            {
                printf("\n[-- ERROR --: ( Data is already present in File )--]\n");
                printf("[-- ERROR --: ( Save Database -> FAILURE )--]\n\n");
            }
            else
            {
                printf("\n\n[-- ERROR --: ( Save Database -> FAILURE )--]\n");
            }
            break;

        case 5:

            if (Flag == 1)
            {
                printf("\n[-- ERROR --: ( DataBase has already been Created )--]\n");
                printf("[-- ERROR --: ( Update Database -> FAILURE )--]\n\n");
            }
            else if ((update_database(hashtable)) == SUCCESS)
            {
                printf("\n[---( Update Database -> SUCCESSFUL )---]");
                Flag = 1;
            }
            else
            {
                printf("\n\n[-- ERROR --: ( Update Database -> FAILURE )--]\n");
            }
            break;

        default:
            printf("\n\n[-- ERROR --: ( Make choice within range )--]\n\n");
            break;
        }

        // Continue/Exit the program.
        printf("\n\n[---( Do you want to continue? (Y/y) or Discontinue (N//n))---] ==>  ");
        scanf(" %c", &cont);
        if (cont == 'n' || cont == 'N')
        {
            break;
        }
    }
}