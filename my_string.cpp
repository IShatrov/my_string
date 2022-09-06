#include "my_string.h"

int my_puts(const char *str)
{
    assert(str != NULL);

    int chars_written = 0;

    while(*str)
    {
        if (putchar(*str) == EOF) return EOF;
        ++str;
        ++chars_written;
    }

    if (putchar('\n') == EOF) return EOF;

    return chars_written + 1;
}

char *my_strchr(const char *str, int ch)
{
    assert(str != NULL);

    while (*str != ch && *str) ++str;

    if (*str == ch) return (char*) str;

    return NULL;
}

size_t my_strlen(const char *str)
{
    assert(str != NULL);

    int chars_checked = 0;

    while (str[chars_checked]) ++chars_checked;

    return chars_checked;
}

char *my_strcpy(char *dest, const char *src)
{
    assert(src != NULL);
    assert(dest != NULL);

    char *res = dest;

    while (*src) *(dest++) = *(src++);

    return res;
}

char *my_strncpy(char *dest, const char *src, size_t count)
{
    assert(src != NULL);
    assert(dest != NULL);

    unsigned int i = 0, src_end = my_strlen(src) + 1;

    while (i < count)
    {
        while (i <= src_end && i < count)
        {
            dest[i] = src[i];
            ++i;
        }

        dest[i] = '\0';
        ++i;
    }

    return dest;
}

char *my_strcat(char *dest, const char *src)
{
    assert(src != NULL);
    assert(dest != NULL);

    char *ans = dest;

    while (*dest) ++dest;
    while (*src) *(dest++) = *(src++);

    *dest = '\0';

    return ans;
}

char *my_strncat(char *dest, const char *src, size_t count)
{
    assert(src != NULL);
    assert(dest != NULL);

    char *ans = dest;
    unsigned int chars_appended = 0;

    while (*dest) ++dest;
    while (*src && chars_appended < count)
    {
        *(dest++) = *(src++);
        ++chars_appended;
    }

    if (chars_appended < count) *dest = '\0';

    return ans;
}

int my_strcmp(const char *lhs, const char *rhs)
{
    assert(lhs != NULL);
    assert(rhs != NULL);

    while(*lhs != '\0' && *rhs != '\0' && *lhs == *rhs)
    {
        ++lhs;
        ++rhs;
    }

    return *lhs - *rhs;
}

char *my_fgets(char *str, int count, FILE *stream)
{
    assert(str != NULL);
    assert(stream != NULL);

    char *res = str;
    int chars_read = 0, ch = '0', max_chars_read = count - 1;

    while (chars_read < max_chars_read)
    {
        ch = getc(stream);

        if (ch == EOF) return NULL;

        if (ch == '\n')
        {
            *(str++) = '\n';
            break;
        }

        *(str++) = (char) ch;
        ++chars_read;
    }

    *str = '\0';

    return res;
}

char *my_strdup(const char *str1)
{
    assert(str1 != NULL);

    char *ans = (char*) malloc((my_strlen(str1) + 1) * sizeof(char));

    assert(ans != NULL);

    my_strcpy(ans, str1);

    return ans;
}

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    assert(stream != NULL);

    if (*lineptr == NULL)
    {
        *lineptr = (char*) malloc(1 * sizeof(char));
        if (*lineptr == NULL) return -1;

        *n = 10;
    }

    unsigned int ans = 0;
    int ch = '0';
    char *ptr = *lineptr;

    while (ch != '\n' && ch != EOF)
    {
        ch = getc(stream);

        if (ch == EOF) return -1;

        if (*n == ans)
        {
            *n *= 2;

            *lineptr = (char*) realloc(*lineptr, *n * sizeof(char));
            if (*lineptr == NULL) return -1;

            ptr = *(lineptr) + ans;

        }

        *ptr = (char) ch;
        ++ptr;
        ++ans;
    }

    if (*n < ans + 1) //check if *lineptr can fit \0
    {
        *lineptr = (char*) realloc(*lineptr, (*n + 1) * sizeof(char));
        if (*lineptr == NULL) return -1;

        ++*n;

        ptr = *(lineptr) + ans;
    }

    *ptr = '\0';

    if (*n > ans + 1) //check if *lineptr has excess space
    {
        *lineptr = (char*) realloc(*lineptr, (ans + 1) * sizeof(char));
        if (*lineptr == NULL) return -1;

        *n = ans + 1;
    }

    return ans;
}

