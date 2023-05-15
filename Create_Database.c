#include "is.h"

int create_database(File_node *fhead, Main_node **hashtable)
{
    int index = 0;

    // while fhead is not equal to NULL keep running the loop
    while (fhead != NULL)
    {
        // Creating file pointer and char array.
        FILE *fptr = fopen((fhead)->file_name, "r");
        char buffer[50];

        // while fptr is not equal to end of file keep running the loop
        while (fscanf(fptr, "%s", buffer) != EOF)
        {
            index = (toupper(buffer[0])) % 65;

            // If buffer is less than 65 or greater than 90 and buffer is less 97 or greater than 122 then execute if-statement.
            if (((buffer[0] < 65) || (buffer[0] > 90)) && ((buffer[0] < 97) || (buffer[0] > 122)))
            {
                // Initialize Flag variable
                int Flag = 0;
                Main_node *temp = hashtable[26];

                // If temp is equalt o NULL then execute if-statement else else-statement.
                if (temp == NULL)
                {
                    // Creating a Main_node and Sub_node and updating and the data in main and sub node
                    Main_node *m_new_node = malloc(sizeof(Main_node));
                    strcpy(m_new_node->word, buffer);

                    m_new_node->next = NULL;
                    m_new_node->file_count = 1;

                    Sub_node *s_new_node = malloc(sizeof(Sub_node));
                    strcpy(s_new_node->file_name, (fhead)->file_name);

                    s_new_node->next = NULL;
                    (s_new_node->word_count)++;

                    m_new_node->down = s_new_node;
                    hashtable[26] = m_new_node;
                    continue;
                }
                else
                {
                    // while temp is not equal to NULL keep running the loop
                    while (temp != NULL)
                    {
                        // If temp of word id equal to buffer then execute if-statement
                        if (strcmp(temp->word, buffer) == 0)
                        {
                            // Updating file count
                            temp->file_count++;
                            Sub_node *stemp = temp->down;

                            while (stemp != NULL)
                            {
                                if (strcmp(stemp->file_name, (fhead)->file_name) == 0)
                                {
                                    stemp->word_count++;
                                    Flag = 1;
                                    break;
                                }

                                if (stemp->next == NULL)
                                {
                                    Sub_node *s_new_node = malloc(sizeof(Sub_node));
                                    strcpy(s_new_node->file_name, (fhead)->file_name);

                                    s_new_node->next = NULL;
                                    (s_new_node->word_count)++;

                                    stemp->next = s_new_node;
                                    Flag = 1;
                                    break;
                                }

                                stemp = stemp->next;
                            }

                            if (Flag == 1)
                            {
                                break;
                            }
                        }

                        // If temp->next is equal to NULL the create Main_node and Sub_node and Update the data and then break current ongoing loop.
                        if (temp->next == NULL)
                        {
                            Main_node *m_new_node = malloc(sizeof(Main_node));
                            strcpy(m_new_node->word, buffer);

                            m_new_node->next = NULL;
                            m_new_node->file_count = 1;

                            Sub_node *s_new_node = malloc(sizeof(Sub_node));
                            strcpy(s_new_node->file_name, (fhead)->file_name);

                            s_new_node->next = NULL;
                            s_new_node->word_count++;

                            m_new_node->down = s_new_node;
                            temp->next = m_new_node;
                            break;
                        }
                        temp = temp->next;
                    }
                }
            }

            // If hashtable[index] is equal to NULL the create Main_node and Sub_node and Update the data and then continue.
            if (hashtable[index] == NULL)
            {
                Main_node *m_new_node = malloc(sizeof(Main_node));
                strcpy(m_new_node->word, buffer);

                m_new_node->next = NULL;
                m_new_node->file_count = 1;

                Sub_node *s_new_node = malloc(sizeof(Sub_node));
                strcpy(s_new_node->file_name, (fhead)->file_name);

                s_new_node->next = NULL;
                (s_new_node->word_count)++;

                m_new_node->down = s_new_node;
                hashtable[index] = m_new_node;
                continue;
            }
            else
            {
                int Flag = 0;
                Main_node *mtemp = hashtable[index];
                while (mtemp != NULL)
                {
                    if (strcmp(mtemp->word, buffer) == 0)
                    {
                        mtemp->file_count++;
                        Sub_node *stemp = mtemp->down;

                        while (stemp != NULL)
                        {
                            if (strcmp(stemp->file_name, (fhead)->file_name) == 0)
                            {
                                stemp->word_count++;
                                Flag = 1;
                                break;
                            }

                            if (stemp->next == NULL)
                            {
                                Sub_node *s_new_node = malloc(sizeof(Sub_node));
                                strcpy(s_new_node->file_name, (fhead)->file_name);

                                s_new_node->next = NULL;
                                (s_new_node->word_count)++;

                                stemp->next = s_new_node;
                                Flag = 1;
                                break;
                            }

                            stemp = stemp->next;
                        }

                        if (Flag == 1)
                        {
                            break;
                        }
                    }

                    if (mtemp->next == NULL)
                    {
                        // Creating Main_node and Sub_node and Update the data in both of them and breking the current ongooing Loop
                        Main_node *m_new_node = malloc(sizeof(Main_node));
                        strcpy(m_new_node->word, buffer);

                        m_new_node->next = NULL;
                        m_new_node->file_count = 1;

                        Sub_node *s_new_node = malloc(sizeof(Sub_node));
                        strcpy(s_new_node->file_name, (fhead)->file_name);

                        s_new_node->next = NULL;
                        s_new_node->word_count++;

                        m_new_node->down = s_new_node;
                        mtemp->next = m_new_node;
                        break;
                    }
                    mtemp = mtemp->next;
                }
            }
        }

        // Update the fhead pointer
        fhead = (fhead)->next;
    }
    return SUCCESS;
}