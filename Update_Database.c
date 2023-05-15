#include "is.h"

int update_database(Main_node **hashtable)
{
    // Initialization of variables.
    int index = -1;
    char ch, buffer[100], file_name[30];

    // Getting an input from user.
    printf("\n[---( Enter File name to save Data Base )---] ==>  ");
    scanf("%s", file_name);

    // Creating a FILE pointer in read mode and if that pointer is equal to NULL then return FAILURE.
    FILE *fptr = fopen(file_name, "r");
    if (fptr == NULL)
    {
        printf("\n[-- ERROR --: ( %s Not Found )--]\n", file_name);
        return FAILURE;
    }
    else
    {
        // Storing the first letter of file in ch variable.
        fread(&ch, 1, 1, fptr);

        // If ch is equal to char '# then execute if-statement else return FAILURE
        if (ch == '#')
        {
            // While file pointer is not equal to EOF keep runing the loop and keep storing each word in buffer.
            while (fscanf(fptr, "%s", buffer) != EOF)
            {
                if (index == -1)
                {
                    index = atoi(strtok(buffer, ";"));
                }
                else
                {
                    index = atoi(strtok((buffer + 1), ";"));
                }

                // If hashtable[index] is equal to NULL then execute if-statement
                if (hashtable[index] == NULL)
                {
                    // Creating Main_node pointer and update it with data from file.
                    Main_node *m_new_node = malloc(sizeof(Main_node));
                    strcpy(m_new_node->word, strtok(NULL, ";"));
                    m_new_node->file_count = atoi(strtok(NULL, ";"));

                    // Creating Sub_node pointer and update it with data from file.
                    Sub_node *s_new_node = malloc(sizeof(Sub_node));
                    strcpy(s_new_node->file_name, strtok(NULL, ";"));
                    s_new_node->word_count = atoi(strtok(NULL, "#"));

                    // Update s_new_node ppointer to m_new_node of down and m_new_node to hashtable of index.
                    m_new_node->down = s_new_node;
                    hashtable[index] = m_new_node;

                    // Update next pointer of both Main_node and Sub_node NULL
                    s_new_node->next = NULL;
                    m_new_node->next = NULL;
                }
                else
                {
                    // Creating a temp pointer and storing hashtable of index in it.
                    Main_node *temp = hashtable[index];
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }

                    // Creating Main_node pointer and update it with data from file.
                    Main_node *m_new_node = malloc(sizeof(Main_node));
                    strcpy(m_new_node->word, strtok(NULL, ";"));
                    m_new_node->file_count = atoi(strtok(NULL, ";"));

                    // Creating Sub_node pointer and update it with data from file.
                    Sub_node *s_new_node = malloc(sizeof(Sub_node));
                    strcpy(s_new_node->file_name, strtok(NULL, ";"));
                    s_new_node->word_count = atoi(strtok(NULL, "#"));

                    // Update s_new_node ppointer to m_new_node of down and m_new_node to hashtable of index.
                    m_new_node->down = s_new_node;
                    temp->next = m_new_node;

                    // Update next pointer of both Main_node and Sub_node NULL
                    s_new_node->next = NULL;
                    m_new_node->next = NULL;
                }
            }
        }
        else
        {
            return FAILURE;
        }
    }

    return SUCCESS;
}
