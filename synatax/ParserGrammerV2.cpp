#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
int i = 0;
char s[10];
/* Function declaration*/
void S();
void A();
void B();
void disp();
void error();
int main()
{
    /* Display grammar on console*/
    cout << "Given grammar is " << endl;
    cout << "S -> aBb/ccA" << endl;
    cout << "A -> b/c" << endl;
    cout << "B -> a/b" << endl;
    cout << "Enter the string" << endl;
    cin >> s;
    S();
    if (s[i] == NULL)
        cout << "string is valid" << endl;
    else
        cout << "string is invalid" << endl;
    getch();
    return 0 ;
}
void S()
{
    if (s[i] == 'a')
    {
        i++;
        B();
        if (s[i] == 'b')
            i++;
        else
            error();
    }
    else if (s[i] == 'c')
    {
        i++;
        if (s[i] == 'c')
        {
            i++;
            A();
        }
        else
            error();
    }
}
void A() // function definition
{
    if (s[i] == 'b' || s[i] == 'c')
        i++;
    else
        error();
}
void B() // function definition
{
    if (s[i] == 'a' || s[i] == 'b')
        i++;
    else
        error();
}
void error()
{
    cout << "string is invalid" << endl;
    getch();
}