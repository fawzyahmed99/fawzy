#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define KEY 32
#define BUFFER_SIZE 15

int isKeyword(char buffer[])
{
    char keywords[KEY][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto",
                              "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

    int i, flag = 0;

    for (i = 0; i < KEY; ++i)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    char ch, buffer[BUFFER_SIZE], operators[] = "+-*/%=", separators[] = "(){}[]<>,";
    FILE *fp;
    int i, j = 0;
    fp = fopen("lexicalinput.txt", "r");

    while ((ch = fgetc(fp)) != EOF)
    {

        for (i = 0; i < 6; ++i)
        {
            if (ch == operators[i])
            {
                printf(" OPERATOR:     %c \n", ch);
            }
            else if (ch == separators[i])
                printf(" SEPARATOR:    %c \n", ch);
        }

        if (isalnum(ch))
        {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (j != 0))
        {
            buffer[j] = '\0';
            j = 0;
            {
                if (isKeyword(buffer) == 1)
                    printf(" KEYWORD:      %s \n", buffer);
                else
                    printf(" IDENTIFIER:   %s \n", buffer);
            }
        }
    }

    fclose(fp);

    return 0;
}
