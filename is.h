#ifndef IS_H
#define IS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1
#define DATA_NOT_FOUND -2
#define DATA_PRESENT -3

typedef struct File
{
    char file_name[30];
    struct File *next;
} File_node;

typedef struct Sub
{
    int word_count;
    char file_name[30];
    struct Sub *next;
} Sub_node;

typedef struct Main
{
    int file_count;
    char word[30];
    Sub_node *down;
    struct Main *next;
} Main_node;

int read_and_validation(int argc, char **argv, File_node **head);
int create_database(File_node *fhead, Main_node **hashtable);
int display_database(Main_node **hashtable, File_node *fhead);
int search_database(Main_node **hashtable, File_node *fhead);
int save_database(File_node *fhead, Main_node **hashtable);
int update_database(Main_node **hashtable);

#endif