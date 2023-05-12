#include "is.h"

int read_and_validation(int argc, char **argv, File_node **head)
{
    // Initializing count variable.
    int count = 0;

    // For i = 0 and i is less than argc keep increasing the i variable.
    for (int i = 1; i < argc; i++)
    {
        // Creating a Flag and making it zero.
        int Flag = 0;

        // Create a file pointer in read mode and check if fptr is equal to NULL and if it is equal to NULL print ERROR and continue.
        FILE *fptr = fopen(argv[i], "r");
        if (fptr == NULL)
        {
            printf("\n[-- ERROR --: ( %s Not Found )--]\n", argv[i]);
            continue;
        }

        // if it is not equal to 0 print ERROR and continue.
        if (strcmp(strstr(argv[i], "."), ".txt") != 0)
        {
            printf("\n[-- ERROR --: ( %s is Not .txt file )--]\n", argv[i]);
            continue;
        }

        // Checking if the file possess any data or not and if not print error and continue.
        fseek(fptr, 0, SEEK_END);
        if (ftell(fptr) == 0)
        {
            printf("\n[-- ERROR --: ( Nothing in File )--]\n");
            continue;
        }

        // Storing fhead in temp pointer
        File_node *temp = *head;

        // While temp is not equalt o NULL
        while (temp != NULL)
        {
            // If output of strcmp is eqaul to 0 te make Flag 1 then break the loop.
            if (strcmp(temp->file_name, argv[i]) == 0)
            {
                Flag = 1;
                break;
            }

            // Update the temp pointer
            temp = temp->next;
        }
        if (Flag == 1)
        {
            printf("\n[-- ERROR --: ( There is already a file named same as %s )--]\n", argv[i]);
            continue;
        }

        // Creating a new_node and make its next member NULL.
        File_node *new_node = malloc(sizeof(File_node));
        new_node->next = NULL;
        strcpy(new_node->file_name, argv[i]);

        temp = *head;

        // While temp is not equal to NULL keep running the loop and updating the node.
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                break;
            }
            temp = temp->next;
        }

        // If temp is equal to head assign new_node pointer to head
        if (temp == NULL)
        {
            *head = new_node;
        }
        // else assign new_node pointer in temp of next.
        else
        {
            temp->next = new_node;
        }
        count++;
    }

    // if count is equal to zero then return FAILURE.
    if (count == 0)
    {
        return FAILURE;
    }

    return SUCCESS;
}