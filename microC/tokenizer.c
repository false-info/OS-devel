#include <stdio.h>

int main() {
    char source[] = "pin(\"hello\") pin(345234) exit()";

    int i = 0;
    while (source[i] != '\0') {
        if (source[i] == 'p' &&
        source[i + 1] == 'i' &&
        source[i + 2] == 'n' &&
        !(source[i + 3] >= 'a' && source[i + 3] <= 'z') &&
        !(source[i + 3] >= 'A' && source[i + 3] <= 'Z') &&
        !(source[i + 3] >= '0' && source[i + 3] <= '9') &&
        source[i + 3] != '_')
        {
            printf("TOKEN_PIN\n");
            i += 3;
        } 
        else if (source[i] == '(') {
            printf("TOKEN_LPAREN\n");
            i++;
        }
        else if (source[i] == ')') {
            printf("TOKEN_RPAREN\n");
            i++;
        }
        else if (source[i] == '"') {
            i++;
            printf("TOKEN_STRING: ");
            

            while (source[i] != '"' && source[i] != '\0') {
                printf("%c", source[i]);
                i++;
            }
        
            printf("\n");

            if (source[i] == '"') {
                i++;
            }
        }
        else if (source[i] >= '0' && source[i] <= '9') {
            int number = 0;

            while (source[i] >= '0' && source[i] <= '9') {
                int digit = source[i] - '0';
                number = number * 10 + digit;
                i++;
            }
        printf("TOKEN_NUMBER: %d\n", number);
        }
        else if (source[i] == 'e' && source[i + 1] == 'x' && source[i + 2] == 'i' && source[i + 3] == 't') {
            printf("TOKEN_END\n");
            i += 4;
        }
        else if (source[i] == ' ' || source[i] == '\n' || source[i] == '\t') {
            i++;
        }


        else {
            printf("char: %c\n", source[i]);
            i++;
        }

    }
printf("TOKEN_EOF\n");
    return 0;
}
