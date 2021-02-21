#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

int control(const char *common, char letter, int size);
void print(const char *common, int size);

int main()
{
    char text[SIZE], text2[SIZE], common[SIZE];
    int count = 0;
    printf("2 kelime giriniz:\n"), gets(text), gets(text2);

    for(int i = 0; i < text[i] != '\0'; i++)
    {
        for(int k = 0; k < text2[k] != '\0'; k++)
        {
            if(text[i] < 123 && text[i] > 64 && (text[i] == text2[k] || text[i] == (text2[k] + 32) || (text[i] + 32) == text2[k]))
            {
                if(!count)
                    common[count] = text[i], count++;
                else
                    if(control(common, text[i], count))
                        common[count] = text[i], count++;
            }
        }
    }
    print(common, count);

    return 0;
}

int control(const char *common, char letter, int size)
{
    for(int i = 0; i < size; i++)
        if(common[i] == letter || common[i] == (letter + 32) || (common[i] + 32) == letter)
            return 0;
    return 1;
}

void print(const char *common, int size)
{
    printf("Common Letters: ");
    for(int i = 0; i < size; i++)
        printf("%c ",common[i]);
    printf("\n%d Letters are common.", size);
}
