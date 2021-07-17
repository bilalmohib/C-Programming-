#include <stdio.h>

int main()
{
    //Will compile successfully
    /*int age = 10;
   int height = 72;

   printf("I am %d years old.\n",age);
   printf("I am %d inches tall\n.",height);*/

    //Will compile correctly but the age is set to zero
    /*int age;
    int height = 72;
    printf("I am %d years old.\n", age);
    printf("I am %d inches tall\n.", height);*/

    //Will compile with warnings and it will print that I am -1306723144 years old.
    int age;
    int height = 72;
    printf("I am %d years old.\n");
    printf("I am %d inches tall\n.", height);

    return 0;
}