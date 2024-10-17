#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Trying to do like an python list
#define Type(x) _Generic((x), int: "int", short: "short", long: "long", char: "char", float: "float", double: "double", default: "unknown")

typedef char *string;

typedef struct node
{
    int *oqAponta;
    struct node *next;
}node;

int main(int agrc, string argv[])
{

}