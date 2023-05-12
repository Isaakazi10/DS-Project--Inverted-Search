#include "is.h"

int main(int argc, char **argv)
{
    int choice = 0;
    char cont;

    // If argc is less than 2 then return FAIlURE.
    if (argc <= 1)
    {
        printf("\n[-- ERROR --: ( Argument count should be greater than 1 )--]\n");
        printf("\n[-- USAGE --: ( ./output file1.txt file2.txt file3.txt )--]\n");
        return FAILURE;
    }

    File_node *fhead = NULL;

    if (read_and_validation(argc, argv, &fhead) == SUCCESS)
    {
        printf("\n[---( Read and validate -> SUCCESSFUL )---]\n");
    }
    else
    {
        printf("\n\n[-- ERROR --: ( Read and validate -> FAILURE )--]\n\n");
        return FAILURE;
    }

    Main_node *hashtable[27] = {NULL};
    if (hashtable == NULL)
    {
        printf("\n\n[-- ERROR --: ( Creation on mhead pointer -> FAILURE )--]\n\n");
        return FAILURE;
    }

    while (1)
    {
        // Make a choice.
        printf("1-> Create Database\n2-> Display Database\n3-> Search Database\n4-> Save Database\n5-> Update Database\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (create_database(&fhead, hashtable) == SUCCESS)
            {
                printf("\n[---( Creating Database -> SUCCESSFUL )---]\n");
            }
            else
            {
                printf("\n\n[-- ERROR --: ( Creating Database -> FAILURE )--]\n\n");
            }
            break;

        case 2:
            if (display_database(hashtable) == SUCCESS)
            {
                printf("\n[---( Display Database -> SUCCESSFUL )---]\n");
            }
            else
            {
                printf("\n\n[-- ERROR --: ( Display Database -> FAILURE )--]\n\n");
            }
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        default:
            printf("\n\n[-- ERROR --: ( Make choice within range )--]\n");
            break;
        }

        printf("\n\n[---] Do you want to continue? (Y/N) [---]\n\n");
        scanf(" %c", &cont);
        if (cont == 'n' || cont == 'N')
        {
            break;
        }
    }
}