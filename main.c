#include "is.h"

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        printf("\n[-- ERROR --: ( Argument count should be greater than 1 )--]\n");
        return FAILURE;
    }

    File_node *head = malloc(sizeof(File_node));

    if (read_and_validation(argc, argv, head) == FAILURE)
    {
        printf("\n[---( 1 Read and validate -> SUCCESSFUL )---]");
    }
    else
    {
        printf("\n[-- ERROR --: ( Files are not in given format )--]\n");
    }

    File_node *temp = head;

    while (temp != NULL)
    {
        char ch;
        FILE *fptr = fopen(temp->file_name, "r");
        while (1)
        {
            while ((ch = getc(fptr)) != EOF)
            {
                ;
            }
        }
    }
}