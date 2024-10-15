#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

extern size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
extern ssize_t ft_read(int fildes, void *buf, size_t nbyte);
extern char *ft_strdup(const char *s);

int main() {
    const char *test = "Hello, world!";
    
    size_t len = ft_strlen(test);
    size_t len2 = strlen(test);
    
    if (len == len2)
        printf("\033[32mSTRLEN 1. OK\n");
    else
        printf("\033[31mSTRLEN 1. KO\n");
    printf("\033[34mLEN:%zu\nFT_LEN:%zu\n", len2, len);

    len = ft_strlen("");
    len2 = strlen("");
    if (len == len2)
        printf("\033[32mSTRLEN 2. OK\n");
    else
        printf("\033[31mSTRLEN 2. KO\n");
    printf("\033[34mLEN:%zu\nFT_LEN:%zu\n", len2, len);

    char src[] = "gemartin";
    char dest[15];

    ft_strcpy(dest, src);
    if (strcmp(dest, src) == 0)
        printf("\033[32mSTRCPY 2. OK\n");
    else
        printf("\033[31mSTRCPY 2. KO\n");
    printf("\033[34mSRC:|%s|\nDEST:|%s|\n", src, dest);

    char src2[] = "";
    char dest2[15];

    ft_strcpy(dest2, src2);
    if (strcmp(dest2, src2) == 0)
        printf("\033[32mSTRCPY 2. OK\n");
    else
        printf("\033[31mSTRCPY 2. KO\n");
    printf("\033[34mSRC:|%s|\nDEST:|%s|\n", src, dest);

    //TEST1
    int res1 = ft_strcmp("gemartin", "gemartin");
    int res2 = strcmp("gemartin", "gemartin");
    if (res1 == res2)
        printf("\033[32mSTRCMP 1. OK\n");
    else
        printf("\033[31mSTRCMP 1. KO\n");
    printf("\033[34mFT_STRCMP:|%d|\nORIGINAL:|%d|\n", res1, res2);
    //TEST2
    res1 = ft_strcmp("", "");
    res2 = strcmp("", "");
    if (res1 == res2)
        printf("\033[32mSTRCMP 2. OK\n");
    else
        printf("\033[31mSTRCMP 2. KO\n");
    printf("\033[34mFT_STRCMP:|%d|\nORIGINAL:|%d|\n", res1, res2);
    //TEST3
    res1 = ft_strcmp("gemartinn", "germartin");
    res2 = strcmp("gemartinn", "germartin");
    if (res1 == res2)
        printf("\033[32mSTRCMP 3. OK\n");
    else
        printf("\033[31mSTRCMP 3. KO\n");
    printf("\033[34mFT_STRCMP:|%d|\nORIGINAL:|%d|\n", res1, res2);

    //TEST4
    res1 = ft_strcmp("gemartin", "jareste");
    res2 = strcmp("gemartin", "jareste");
    if (res1 == res2)
        printf("\033[32mSTRCMP 4. OK\n");
    else
        printf("\033[31mSTRCMP 4. KO\n");
    printf("\033[34mFT_STRCMP:|%d|\nORIGINAL:|%d|\n", res1, res2);

    //TEST5
    res1 = ft_strcmp("jareste", "gemartin");
    res2 = strcmp("jareste", "gemartin");
    if (res1 == res2)
        printf("\033[32mSTRCMP 5. OK\n");
    else
        printf("\033[31mSTRCMP 5. KO\n");
    printf("\033[34mFT_STRCMP:|%d|\nORIGINAL:|%d|\n", res1, res2);

    //TEST6
    res1 = ft_strcmp("", "gemartin");
    res2 = strcmp("", "gemartin");
    if (res1 == res2)
        printf("\033[32mSTRCMP 6. OK\n");
    else
        printf("\033[31mSTRCMP 6. KO\n");
    printf("\033[34mFT_STRCMP:|%d|\nORIGINAL:|%d|\n", res1, res2);

    //TEST7
    res1 = ft_strcmp("jareste", "");
    res2 = strcmp("jareste", "");
    if (res1 == res2)
        printf("\033[32mSTRCMP 7. OK\n");
    else
        printf("\033[31mSTRCMP 7. KO\n");
    printf("\033[34mFT_STRCMP:|%d|\nORIGINAL:|%d|\n", res1, res2);
    
    //TEST1
    int fd1 = open("tests/write", O_WRONLY);
    ssize_t resu1 = ft_write(fd1, "buenas", strlen("buenas"));
    ssize_t resu2 = write(fd1, "buenas", strlen("buenas"));
    if (resu1 == resu2)
        printf("\033[32mWRITE 1. OK\n");
    else
        printf("\033[31mWRITE 1. KO\n");
    printf("\033[34mFT_WRITE:|%zd|\nORIGINAL:|%zd|\n", resu1, resu2);
    close(fd1);
    //TEST2
    int fd2 = open("tests/write_err", O_WRONLY);
    resu1 = ft_write(fd2, "nana", strlen("nana"));
    resu2 = write(fd2, "nana", strlen("nana"));
    if (resu1 == resu2)
        printf("\033[32mWRITE 2. OK\n");
    else
        printf("\033[31mWRITE 2. KO\n");
    printf("\033[34mFT_WRITE:|%zd|\nORIGINAL:|%zd|\n", resu1, resu2);
    close(fd2);
    //TEST3
    resu1 = ft_write(1, "buenas\n", strlen("buenas\n"));
    resu2 = write(1, "buenas\n", strlen("buenas\n"));
    if (resu1 == resu2)
        printf("\033[32mWRITE 3. OK\n");
    else
        printf("\033[31mWRITE 3. KO\n");
    printf("\033[34mFT_WRITE:|%zd|\nORIGINAL:|%zd|\n", resu1, resu2);
    close(fd1);

    //TEST1
    char buffer[100] = {0};
    char buffer2[100] = {0};
    int fd3 = open("tests/read", O_RDONLY);
    resu1 = ft_read(fd3, buffer, 50);
    close(fd3);
    fd3 = open("tests/read", O_RDONLY);
    resu2 = read(fd3, buffer2, 50);
    if (strcmp(buffer, buffer2) == 0)
        printf("\033[32mREAD 1. OK\n");
    else
        printf("\033[31mREAD 1. KO\n");
    //printf("\033[34mFT_READ:|%zd|\nORIGINAL:|%zd|\n", resu1, resu2);
    printf("\033[34mBUFF:%s\nORI:%s\n", buffer, buffer2);

    //TEST2
    int fd4 = open("tests/read_err", O_RDONLY);
    resu1 = ft_read(fd4, buffer, 10);
    close(fd4);
    fd4 = open("tests/read_err", O_RDONLY);
    resu2 = read(fd4, buffer, 10);
    if (resu1 == resu2)
        printf("\033[32mREAD 2. OK\n");
    else
        printf("\033[31mREAD 2. KO\n");
    printf("\033[34mFT_READ:|%zd|\nORIGINAL:|%zd|\n", resu1, resu2);

    //TEST3

    char buffer3[100] = {0};
    char buffer4[100] = {0};
    fd3 = open("tests/read", O_RDONLY);
    resu1 = ft_read(0, buffer3, 50);
    close(fd3);
    fd3 = open("tests/read", O_RDONLY);
    resu2 = read(0, buffer4, 50);
    if (strcmp(buffer, buffer2) == 0)
        printf("\033[32mREAD 3. OK\n");
    else
        printf("\033[31mREAD 3. KO\n");
    //printf("\033[34mFT_READ:|%zd|\nORIGINAL:|%zd|\n", resu1, resu2);
    printf("\033[34mBUFF:%s\nORI:%s\n", buffer3, buffer4);

    //TEST1
    printf("TEST\n");
    char *str1 = ft_strdup("gemartin");
    printf("TEST2\n");
    char *str2 = strdup("gemartin");
    if (strcmp(str1, str2) == 0)
        printf("\033[32mSTRDUP 1. OK\n");
    else
        printf("\033[31mSTRDUP 1. KO\n");
    printf("\033[34mFT_STRDUP:|%s|\nORIGINAL:|%s|\n", str1, str2);
    //TEST2
    char *str3 = ft_strdup("");
    char *str4 = strdup("");
    if (strcmp(str1, str2) == 0)
        printf("\033[32mSTRDUP 2. OK\n");
    else
        printf("\033[31mSTRDUP 2. KO\n");
    printf("\033[34mFT_STRDUP:|%s|\nORIGINAL:|%s|\n", str3, str4);
    return 0;
}

