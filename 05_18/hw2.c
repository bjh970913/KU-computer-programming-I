#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    char str[10000], token[10], *str_p, f_name[100];
    int token_length, count_token, count_word;

    printf("Enter the file name and word: ");
    scanf("%s", f_name);
    scanf("%s", token);
    token_length = strlen(token);
    // printf("%s\n", token);

    fp = fopen(f_name, "r");
    fgets(str, 10000, fp);
    

    count_token = 0;
    str_p = strstr(str, token);
    while(str_p)
    {
        count_token++;
        str_p += token_length;
        str_p = strstr(str_p, token);
    }

    count_word = 0;
    str_p = strtok(str, " .-");
    while(str_p)
    {
        count_word++;
        str_p = strtok(NULL, " .-");
    }

    printf("The finding ratio: %d/%d\n", count_token, count_word);

    return 0;
}