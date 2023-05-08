#ifndef IS_H
#define IS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct File
{
    char file_name[30];
    struct File *next;
} file_node;

typedef struct Sub_node
{
    int word_count;
    char file_name[30];
    struct sub_node *next;
} sub_node;

typedef struct Main_node
{
    int file_count;
    char word[20];
    struct main_node *next;
    sub_node *down;
} main_node;

int read_and_validation(char **argv);

#endif