#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

//for testing
#include <string.h>

//! @param[in] str Pointer to string.
//! @return Returns EOF if an error occurred, and the amount of printed characters otherwise (including additional newline character).
//! @brief Prints a string and an additional newline character.
int my_puts(const char *str);

//! @param[in] str Pointer to string.
//! @param[in] ch Character to find.
//! @return Returns pointer to the first occurrence of ch in str and NULL if ch was not found.
//! @brief Finds the first occurrence of ch in str.
char *my_strchr(const char *str, int ch);

//! @param[in] str Pointer to string.
//! @return Returns the length of str.
//! @brief Counts the number of characters in a string.
size_t my_strlen(const char *str);

//! @param[in] src Pointer to array to copy from.
//! @param[out] dest Pointer to destination array.
//! @return Returns a copy of dest.
//! @brief Copies all characters from src to dest, including the null terminator.
char *my_strcpy(char *dest, const char *src);

//! @param[in] src Pointer to array to copy from.
//! @param[in] count Maximum amount of copied characters.
//! @param[out] dest Pointer to destination array.
//! @return Returns a copy of dest.
//! @brief Copies no more than count characters from src to dest. If count is not reached after copying the null terminator, null terminators are added until count characters have been copied.
char *my_strncpy(char *dest, const char *src, size_t count);

//! @param[in] src Pointer to array to copy from.
//! @param[out] dest Pointer to array to append to.
//! @return Returns dest.
//! @brief Appends src to dest.
char *my_strcat(char *dest, const char *src);

//! @param[in] src Pointer to array to copy from.
//! @param[in] count Maximum amount of copied characters.
//! @param[out] dest Pointer to array to append to.
//! @return Returns dest.
//! @brief Appends no more than count characters from src to dest.
char *my_strncat(char *dest, const char *src, size_t count);

//! @param[in] lhs Pointer to string.
//! @param[in] rhs Pointer to string.
//! @return Returns zero if lhs == rhs, a positive integer if rhs < lhs and a negative integer if rhs > lhs.
//! @brief Compares strings lexicographically.
int my_strcmp(const char *lhs, const char *rhs);

//! @param[in] count Maximum length of str after reading.
//! @param[in] stream File to read from.
//! @param[out] str Pointer to string.
//! @return Returns str if reading was successful, and NULL if an error occurred.
//! @brief Reads no more than count - 1 characters from FILE and copies them to str. Writes a null terminator at the end of str if reading was successful. Stops if new line character was read.
char *my_fgets(char *str, int count, FILE *stream);

//! @param[in] str1 Pointer to string.
//! @return Returns pointer to duplicate of str1.
//! @brief Duplicates str1.
//! @note Use free() to avoid memory leaks.
char *my_strdup(const char *str1);

//! @param[in] lineptr Pointer to pointer to char array.
//! @param[in] n Pointer to the array length.
//! @param[in] stream File to read from.
//! brief Reads from stream until a newline symbol is met, storing the characters in array pointed to by *lineptr. Expands the array with realloc if required. The resulting string includes the newline symbol and is null-terminated.
//! @note Use free() to avoid memory leaks.
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

#endif


