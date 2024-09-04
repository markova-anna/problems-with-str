#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int strlen(const char* str);
void strcpy(char* str1, const char* str2);
void strdup(char** str1, const char* str2);

int main ()
{
    char* str1;
    const char* str2 = "cool"; 
    strdup(&str1, str2);
    //printf("%s\n", str1);
    free(str1);
    //printf("its free\n");

    return 0;
}

int strlen(const char* str)
{
    assert(str != nullptr);

    int cnt = 0;
    int i = 0;

    while (char ch = str[i] != '\0')
    {
        cnt++;
        i++;
    }
    return cnt;
}

void strcpy(char* str1, const char* str2)
{
    assert(str1 != nullptr);
    assert(str2 != nullptr);
    int i = 0;

    while(str2[i] != '\0')
    {
        str1[i] = str2[i];
        //printf("check symbol %d - %c\n", i+1, str1[i]);
        i++;
    }
    //printf("check symbol %d - %c\n", i+1, str1[i]);
    str1[i] = str2[i];
}

void strdup(char** str1, const char* str2)
{
    assert(str1 != nullptr);
    assert(str2 != nullptr);
    *str1 = (char*)calloc(strlen(str2)+1, sizeof(char));
    strcpy(*str1, str2);
}



