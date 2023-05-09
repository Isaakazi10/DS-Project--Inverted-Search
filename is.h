#ifndef IS_H
#define IS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define DATA_NOT_FOUND -2

typedef struct File
{
    char file_name[30];
    struct File *next;
} File_node;

typedef struct Sub
{
    int word_count;
    char file_name[30];
    struct sub *next;
} Sub_node;

typedef struct Main
{
    int file_count;
    char word[20];
    struct main *next;
    Sub_node *down;
} Main_node;

int read_and_validation(int argc, char **argv, File_node **head);

#endif