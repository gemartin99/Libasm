#include <stdio.h>
#include <unistd.h>
#include <string.h>

extern size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *dest, const char *src);

int main() {
    const char *test = "Hello, world!";
    
    size_t len = ft_strlen(test);
    size_t len2 = strlen(test);
    
    if (len == len2)
        printf("STRLEN 1. OK\n");
    else
    {
        printf("STRLEN 1. KO\n");
        printf("LEN:%zu\nFT_LEN:%zu\n", len2, len);
    }
    char src[] = "gemartin";
    char dest[15];

    ft_strcpy(dest, src);
    if (strcmp(dest, src) == 0)
    {
        printf("STRCPY 2. OK\n");
        printf("SRC:|%s|\nDEST:|%s|\n", src, dest);
    }
    else
    {
        printf("STRCPY 2. KO\n");
        printf("SRC:|%s|\nDEST:|%s|\n", src, dest);
    }
    
    return 0;
}
