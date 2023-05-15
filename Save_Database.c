#include "is.h"

int save_database(File_node *fhead, Main_node **hashtable)
{
    char file_name[30];
    printf("\n[---( Enter File name to save Data Base )---] ==>  ");
    scanf("%s", file_name);

    // if it is not equal to 0 print ERROR.
    if (strcmp(strstr(file_name, "."), ".txt") != 0)
    {
        printf("\n[-- ERROR --: ( %s is not .txt file )--]\n", file_name);
        return FAILURE;
    }

    // Create a file pointer in read mode and check if fptr is equal to NULL and if it is equal to NULL print ERROR.
    FILE *fptr = fopen(file_name, "r");

    // If fptr is not equal to NULL then use fseek to find the If data is present or not
    if (fptr != NULL)
    {
        fseek(fptr, 0, SEEK_END);
    }

    // If fptr is equal to NULL or fptr is equal to zero then execute if-statement.
    if ((fptr == NULL) || (ftell(fptr) == 0))
    {
        // If fptr is equal to NULL (which shows that there is no such file in this directory) then then execute if-statement.
        if (fptr == NULL)
        {
            printf("\n[-- ERROR --: ( %s Not Found )--]\n", file_name);
            printf("\n[--- ( Creating new File ) ---]\n");

            // Make a new_file.
            fptr = fopen(file_name, "w");
        }
        else
        {
            // open the file with write mode.
            fptr = fopen(file_name, "w");
        }

        // For index is less than 27 keep running the loop
        for (int index = 0; index < 27; index++)
        {
            // Store hashtable[index] of next in temp
            Main_node *temp = hashtable[index];

            // While temp is not equal to NULL keep running the loop
            while (temp != NULL)
            {

                // Algorithum for printing data present in main_node and sub_node into a file.
                fprintf(fptr, "#%d;%s;%d", index, temp->word, temp->file_count);

                Sub_node *stemp = temp->down;
                while (stemp != NULL)
                {
                    fprintf(fptr, ";%s;%d", stemp->file_name, stemp->word_count);
                    stemp = stemp->next;
                }

                // This will act as a delimiter to denote next line.
                fprintf(fptr, "#\n");

                // Update the temp pointer.
                temp = temp->next;
            }
        }
    }
    else
    {
        // If data is present in the file return DATA_PRESENT.
        return DATA_PRESENT;
    }

    // close FILE pointer fptr and return SUCCESS.
    // fclose is a keyword whose feature is to save whatever changes made to a file.
    fclose(fptr);

    return SUCCESS;
}