/*
 * =====================================================================================
 *
 *       Filename:  string_ops.c
 *
 *    Description:  To implement the functions
 *
 *        Version:  1.0
 *        Created:  08/15/2013 03:35:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include "string_ops.h"

/* *
 * copy string from src to dst
 * */
char *cst_strcpy(char * dst, char *src)
{
	if (dst == NULL || src == NULL)	
		return 	NULL;
	
	char *result = dst, *tmp = src;

	while (*tmp){
		*dst++ = *tmp++;
	}
	
	return result;
}

/* *
 * compare str1 with str2
 * return:
 *  >0: str1 > str2
 *  =0: str1 = str2
 *  <0: str1 < str2
 * */
int cst_strcmp(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return -1;
	
	char *ptr1 = str1, *ptr2 = str2;
	unsigned char c1 = *ptr1;
	unsigned char c2 = *ptr2;

	do {
		c1 = (unsigned char)*ptr1++;
		c2 = (unsigned char)*ptr2++;
		if (c1 == '\0' || c2 == '\0')
			return c1 - c2;
	}while(c1 == c2);

	return c1 - c2;
}

/* *
 * compare str1 with str2
 * return:
 *  >0: str1 > str2
 *  =0: str1 = str2
 *  <0: str1 < str2
 * */
int cst_strncmp(char *str1, char *str2, int n)
{
	if (str1 == NULL || str2 == NULL)
		return -1;
	
	char *ptr1 = str1, *ptr2 = str2;
	unsigned char c1 = *ptr1;
	unsigned char c2 = *ptr2;
	
	while (c1 == c2 && --n > 0){
		c1 = (unsigned char)*ptr1++;
		c2 = (unsigned char)*ptr2++;
		if (c1 == '\0' || c2 == '\0')
			return c1 - c2;
	}

	return c1 - c2;
}

/* *
 * To check if str2 is the subsequence of str1
 * <0: str2 isn't in str1
 * >=0: str2 is in str1
 * */
int cst_strstr(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return -1;

	int index = -1;
	int len = strlen(str2);
	char *pos;

	for (pos = str1; *pos != '\0'; pos++) {
		if ( cst_strncmp(pos, str2, len) == 0) {
			index = pos - str1;	
			break;
		}
	}

	return index; 
}

/* *
 * Calculate the length of str
 * <=0: str is NULL or invalid 
 * >0 : the length of str 
 * */
int cst_strlen(char *str)
{
	if (str == NULL)
		return -1;

	int len = 0;
	char *pos = str;

	while (*pos != '\0') {
		len++;
		pos++;
	}

	return len;
}

/* *
 * Convert string to int
 * Concerned Questions:
 * 	1. empty pointer
 * 	2. illegal character
 * 	3. out of range
 * 	4. negtive or positive
 * 	5. neglect empty character from the beginning
 * */
int cst_atoi(char *str, int radix)
{
	int flag = 1, result = 0, tmp;
	char * pos = str;

	if (str == NULL) {
		printf("Invalid intput\n");
		return MAX_INT;
	} else if (strlen(str) > 10)

	//neglect empty character from the beginning
	while(*pos == ' ')
		pos++;

	if (*pos == '-') {
		pos++;
		flag = -1;
	}else if(*pos == '+') {
		pos++;
	}

	if (strlen(pos) > 10) {
		printf("number is out of range\n");
		return MAX_INT;
	}

	while (*pos != '\0') {
		tmp = *pos - '0';
		if (tmp < 0 || tmp > 9) {
			printf("Invalid character\n");
			result = MAX_INT;
			break;
		}
		result *= radix;
		result += tmp;
		pos++;
	}

	if ((result >> 31) & 0x01 && flag == 1) {
		printf("Positive number is out of range\n");
		result = MAX_INT;
	} else if ((result >> 31) & 0x01) {
		printf("Negtive number is out of range\n");
		result = MIN_INT;
	}
	if (flag == -1){
		result *= flag;
	}
	
	return result;	
}

/* *
 * 
 * */
char * cst_int2str(int num, char *str, int length)
{
	return NULL;	
}
void permutation(char *str)
{
	
}
void _permutation(char *str, char *begin)
{
}
void combination(char *str)
{
}
void _combination(char *str, char *begin, int expected, int current, int length)
{
}
void revert_string(char *str)
{
}
void revert_word(char *str)
{
}
