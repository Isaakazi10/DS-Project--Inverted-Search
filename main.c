#include "is.h"

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        printf("");
        return FAILURE;
    }

    for (int i = 0; i < argc; i++)
    {
        if (read_and_validation() == FAILURE)
        {
            ;
        }
        else
        {
            ;
        }
    }
}