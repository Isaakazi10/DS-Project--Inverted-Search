#include "is.h"

int search_database(Main_node **hashtable, File_node *fhead)
{
    // To check if hashtable is empty or not.
    int count = 0;
    for (int i = 0; i < 27; i++)
    {
        if (hashtable[i] != NULL)
        {
            count++;
        }
    }
    // If hashtable is empty then count wiil be zero return FAILURE
    if (count == 0)
    {
        return FAILURE;
    }

    // Initializtion of variables used in this file
    char data[30];
    int index = 0;

    printf("\n[---(Enter the data to be searched in the Data base)---] ==>  ");
    scanf("%s", data);

    // If data is special character then index is 26.
    if (((data[0] < 65) || (data[0] > 90)) && ((data[0] < 97) || (data[0] > 122)))
    {
        index = 26;
    }
    else
    {
        // else index is capital first data character mod of 65.
        index = toupper(data[0]) % 65;
    }

    // Creating a main node mtemp and storing hashtable[index] in it.
    Main_node *mtemp = hashtable[index];

    printf("\nIndex\t Word \t\t[ File_count ]\t");
    while (fhead != NULL)
    {
        printf("[ file_name ]\t[ word_count ]\t");
        fhead = fhead->next;
    }

    printf("\n");

    // While temp is not equal to NULL keep running the loop
    while (mtemp != NULL)
    {
        // If temp of word is equal to data then print every data present and return SUCCESS
        if (strcmp(mtemp->word, data) == 0)
        {
            printf("[ %d ]\t %s \t\t[ %d ]", index, mtemp->word, mtemp->file_count);

            Sub_node *stemp = mtemp->down;
            while (stemp != NULL)
            {
                printf("\t\t[ %s ]\t[ %d ]", stemp->file_name, stemp->word_count);
                stemp = stemp->next;
            }

            printf("\n");
            return SUCCESS;
        }

        // Update mtemp pointer
        mtemp = mtemp->next;
    }

    // If data is not found return DATA_NOT_FOUND.
    return DATA_NOT_FOUND;
}