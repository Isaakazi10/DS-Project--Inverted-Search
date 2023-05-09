#include "is.h"

int read_and_validation(int argc, char **argv, File_node **head)
{
    // For i = 0 and i is less than argc keep increasing the i variable.
    for (int i = 0; i < argc; i++)
    {
        // Create a file pointer in read mode and check if fptr is equal to NULL and if it is equal to NULL print ERROR and continue.
        FILE *fptr = fopen(argv, "r");
        if (fptr == NULL)
        {
            printf("\n[-- ERROR --: ( File %d Not Found )--]\n", (i + 1));
            continue;
        }

        // if it is not equal to 0 print ERROR and continue.
        if (strcmp(strstr(argv, '.'), ".txt") != 0)
        {
            printf("\n[-- ERROR --: ( File is Not \".txt\" file )--]\n", (i + 1));
            continue;
        }

        // Checking if the file possess any data or not and if not print error and continue.
        fseek(fptr, 0, SEEK_END);
        if (ftell(fptr == 0))
        {
            printf("\n[-- ERROR --: ( Nothing in File )--]\n");
            continue;
        }

        // Creating a new_node and make its next member NULL.
        File_node *new_node = malloc(sizeof(File_node));
        new_node->next = NULL;

        // Create a temp pointer and assign a head pointer to it.
        File_node *temp = *head;

        // While temp is not equal to NULL keep running the loop and updating the node.
        while (temp != NULL)
        {
            temp = temp->next;
        }

        // If temp is equal to head assign new_node pointer to head
        if (temp == *head)
        {
            *head = new_node;
        }
        // else assign new_node pointer in temp of next.
        else
        {
            temp->next = new_node;
        }
    }

    return SUCCESS;
}