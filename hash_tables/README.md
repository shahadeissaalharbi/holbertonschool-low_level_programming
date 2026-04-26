# Hash Tables

## Description

A **hash table** is a data structure that maps keys to values using a hash function. It provides average O(1) time complexity for insertions and lookups.

This project implements a hash table in C using **chaining** (linked lists) to handle collisions.

## Data Structures

typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

## Files

| File | Description |
|------|-------------|
| hash_tables.h | Header file with structs and prototypes |
| 0-hash_table_create.c | Creates a new hash table |

## Functions

hash_table_t *hash_table_create(unsigned long int size);
- Allocates memory for a new hash table
- Initializes all array slots to NULL
- Returns a pointer to the new hash table, or NULL on failure

## Compilation

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-hash_table_create.c -o a
./a

## Author

Holberton School - Low Level Programming
