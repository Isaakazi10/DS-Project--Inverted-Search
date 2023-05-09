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
        ;
    }
    else
    {
        ;
    }
}