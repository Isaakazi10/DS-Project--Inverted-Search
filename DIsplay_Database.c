#include "is.h"

int display_database(Main_node **hashtable)
{
    int count = 0;
    for (int index = 0; index < 27; index++)
    {
        // Store hashtable[index] of next in temp
        Main_node *temp = hashtable[index];

        // While temp is not equal to NULL keep running the loop
        while (temp != NULL)
        {
            printf("#%d\t%s\t%d\t", index, temp->word, temp->file_count);

            Sub_node *stemp = temp->down;
            while (stemp != NULL)
            {
                printf("%s ", stemp->file_name);
                stemp = stemp->next;
            }

            printf("\t");

            stemp = temp->down;
            while (stemp != NULL)
            {
                printf("%d ", stemp->word_count);
                stemp = stemp->next;
            }

            printf("\n");

            temp = temp->next;
            count++;
        }
    }

    if (count == 0)
    {
        return FAILURE;
    }

    return SUCCESS;
}