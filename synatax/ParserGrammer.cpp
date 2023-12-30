#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
/* Function Declaration */
int A();
void disp();
void error();
char s[20];
int i;
int main()
{
    printf("S -> cAd\n"); // input grammar
    printf("A -> ab/a\n");
    printf("Enter the String:\n");
    scanf("%s", &s);
    i = 0;
    if (s[i++] == 'c' && A())
    {
        if (s[++i] == 'd' && s[i + 1] == NULL)
            disp();
        else
            error();
    }
    else
        error();
    return 0;
}
int A() // Function definition
{
    if (s[i++] == 'a' && s[i] == 'b')
        return (1);
    else if (s[--i] == 'a')
        return (1);
    else
        return (0);
}
void disp()
{
    printf("\nstring is valid\n");
    getch();
    // exit(0);
}
void error() // function definition
{
    printf("\nstring is invalid\n");
    getch(); // to hold the output screen for some time until the user passes a key from the keyboard to exit the console screen
}