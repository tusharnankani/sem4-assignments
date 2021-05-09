#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void KMP(char *str, char *word, int *ptr)
{
    int i = 0, j = 0;
    while ((i + j) < strlen(str))
    {
        if (word[j] == str[i + j])
        {
            if (j == (strlen(word) - 1))
            {
                printf("%s located at the index %d\n", word, i);
                return;
            }
            j = j + 1;
        }
        else
        {
            i = i + j - ptr[j];
            if (ptr[j] > -1)
            {
                j = ptr[j];
            }
            else
            {
                j = 0;
            }
        }
    }
}

void findOverlap(char *word, int *ptr)
{
    int i = 2, j = 0, len = strlen(word);
    ptr[0] = -1;
    ptr[1] = 0;
    while (i < len)
    {
        if (word[i - 1] == word[j])
        {
            j = j + 1;
            ptr[i] = j;
            i = i + 1;
        }
        else if (j > 0)
        {
            j = ptr[j];
        }
        else
        {
            ptr[i] = 0;
            i = i + 1;
        }
    }
    return;
}

int main()
{
    char word[256], str[1024];
    int *ptr, i;
    printf("Enter Text :--> ");
    fgets(str, 1024, stdin);
    str[strlen(str) - 1] = '\0';
    printf("Enter Pattern :--> ");
    fgets(word, 256, stdin);
    word[strlen(word) - 1] = '\0';
    ptr = (int *)calloc(1, sizeof(int) * (strlen(word)));
    findOverlap(word, ptr);
    KMP(str, word, ptr);
    return 0;
}
