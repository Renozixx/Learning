#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Trying to do like an python list
#define Type(x) _Generic((x), int: "int", short: "short", long: "long", char: "char", float: "float", double: "double", default: "unknown")

typedef char *string;

typedef struct node
{
    int index;
    int caso;
    int intvalue;
    float floatvalue;
    string strvalue;
    struct node *next;
}node;

void print_list(node *ptr);

int what_is(const char *str);

int main(int argc, char *argv[])
{
    node *list = NULL;
    char *input;
    int n = 1, k = 0;
    printf("Coloque quantos inputs quiser, digite /fim/ (com as barras) para encerrar a atividade : ");
    while(n == n)
    {
        node *ptr;
        scanf("%s", &input);
        // if (strcmp("fim", input) == 0)
        // {
        //     break;
        // }
        n = what_is(input);
        switch (n)
        {
        case 0:
            ptr->index = k;
            ptr->caso = 0;
            ptr->strvalue = input;
            ptr->next = list;
            list = ptr;
            break;
        case 1:
            ptr->index = k;
            ptr->caso = 1;
            ptr->intvalue = atoi(input);
            ptr->next = list;
            list = ptr;
            break;
        case 2:
            ptr->index = k;
            ptr->caso = 1;
            ptr->floatvalue = atof(input);
            ptr->next = list;
            list = ptr;
            break;
        default:
            printf("Não foi possivel tratar o dado");
            break;
        }
    }

    node *ptr = list;
    

    return 0;
}

void print_list(node *ptr)
{
    printf("[ ");
    while (ptr != NULL)
    {   
        switch (ptr->caso)
        {
        case 0:
            string value = ptr->strvalue;
            printf("%s, ", value);
            break;
        case 1:
            int value2 = ptr->intvalue;
            printf("%d, ", value2);
            break;
        case 2:
            float value3 = ptr->floatvalue;
            printf("%f, ", value3);
            break;        
        default:
            break;
        }
        ptr = ptr->next;
    }
    printf(" ]");
}

int what_is(const char *str)
{
    int n1, n2, n3, n4; 
    int len = strlen(&str);
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(str[i]))
        {
            n1++;
        }   
        else if (str[i] == "-")
        {
            n2++;
        }
        else if (str[i] == ".")
        {
            n3++;
        }
    }
    n4 = n3 + n2 + n1;
    if (n3 == 1 && n4 == len) 
    {
        return 2;
    }
    else if (n4 == len)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
