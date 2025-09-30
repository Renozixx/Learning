#include <stdio.h>
#include <stdlib.h>

#define Type(x) _Generic((x), int: "int", short: "short", long: "long", char: "char", float: "float", double: "double", default: "unknown")

typedef char* string;

int main(void)
{
  string a = "cagueiporra";
  char b = "C";
  int *ptr = &a;
  int *ptr1 = &b;
  printf("%d\n", sizeof(ptr));
  printf("%s\n", Type(ptr));
  printf("%p\n", ptr);
  printf("%c\n", ptr1);
}
