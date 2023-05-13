#include "is.h"

int display_database(Main_node **hashtable, File_node *fhead)
{
    // Using count to check if hashtable is empty or not.
    int count = 0;

    printf("\nIndex\t[ Word ]\t\t[ File_count ]\t");
    while (fhead != NULL)
    {
        printf("[ file_name ]\t[ word_count ]\t");
        fhead = fhead->next;
    }

    printf("\n");

    // For index is less than 27 keep running the loop
    for (int index = 0; index < 27; index++)
    {
        // Store hashtable[index] of next in temp
        Main_node *temp = hashtable[index];

        // While temp is not equal to NULL keep running the loop
        while (temp != NULL)
        {
            // Algorithum for printing data present in main_node and sub_node.
            printf("[ %d ]\t %s \t\t[ %d ]", index, temp->word, temp->file_count);

            Sub_node *stemp = temp->down;
            while (stemp != NULL)
            {
                printf("\t\t[ %s ]\t[ %d ]", stemp->file_name, stemp->word_count);
                stemp = stemp->next;
            }

            printf("\n");

            temp = temp->next;
            count++;
        }
    }

    // If hashtable is empty then count wiil be zero return FAILURE
    if (count == 0)
    {
        return FAILURE;
    }

    return SUCCESS;
}