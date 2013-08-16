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


void inline print_string(char *str, int length)
{
	if (str == NULL || length <= 0)
		return;
	
	int i = 0;
	for (; i < length; i++) {
		printf("%c", str[i]);
	}
	printf("\n");
}

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
	int flag = 1, tmp;
	unsigned int result = 0;
	char * pos = str;

	if (str == NULL) {
		printf("Invalid intput\n");
		return MAX_INT;
	}

	//neglect empty character from the beginning
	while(*pos == ' ')
		pos++;

	if (*pos == '-') {
		pos++;
		flag = -1;
	}else if(*pos == '+') {
		pos++;
	}

	while (*pos != '\0') {
		tmp = *pos - '0';
		if (tmp < 0 || tmp > 9) {
			printf("Invalid character\n");
			result = MAX_INT;
			break;
		}

		if ((result >> 31) & 0x01 && flag == 1) {
			printf("Positive number is out of range\n");
			result = MAX_INT;
			break;
		} else if ((result >> 31) & 0x01) {
			printf("Negtive number is out of range\n");
			result = MIN_INT;
			break;
		}
		result *= radix;
		result += tmp;
		pos++;
	}
	

	result *= flag;
	return result;	
}

/* *
 * Convert integer to string 
 * Note:
 * 	1. negtive or positive number;
 * 	2. string is enough for convertion
 * */
char * cst_int2str(int num, int radix, char *str, int length)
{
	if (str == NULL || length <= 2)
	{
		//Length should reserve size for \0 and sign bit
		str[0] = '\0';
		return NULL;
	}
	
	int index = 0, tmp, flag = 0;

	//handle negtive sign
	if (num < 0) {
		flag = 1;
		num = num * -1;
		str[0] = '-';
		index = 1;
	}

	while(num && index < length - 1){
		tmp = num % radix;

		str[index] = '0' + tmp;

		num /= radix;
		index++;
	}
	
	if (num != 0) {
		printf("Sting size is not enough!\n");
		str[0] = '\0';
		return NULL;
	} 

	str[index] = '\0';	
	revert_string(str, flag, index-1);

	return str;	
}

int inline check_input_params(char *str, int length){
	if (str == NULL || length <= 0)
		return 0;
	return 1;
}

/* *
 * Full permutation of string [str]
 * */
void permutation(char *str)
{
	if (str == NULL)
		return;
	
	char *begin = str;
	_permutation(str, begin);
}

void _permutation(char *str, char *begin)
{
	if (*begin == '\0') {
		printf("Permutation:>%s\n", str);
		return;
	}

	char *cptr = begin;
	char tmp;
	for (; *cptr != '\0'; cptr++) {
		tmp = *begin;
		*begin = *cptr;
		*cptr = tmp;

		_permutation(str, begin+1);

		tmp = *begin;
		*begin = *cptr;
		*cptr = tmp;
	}
}

/* *
 * Full combination of str: [1, length-1]
 * Principle:
 * 			
 * */
void combination(char *str)
{
	if (str == NULL) {
		return;
	}
	int length = cst_strlen(str);
	int expected = 1, current = 0;
	char result[length+1];
	memset(result, '\0', length+1);

	for (; expected < length; expected++) {
		printf("Expected %d characters\n", expected);
		_combination(str, result, expected, current);	
	}
}

void _combination(char *str, char *result, int expected, int current)
{
	if (expected == current) {
		result[expected] = '\0';	
		printf(">>>>>> %s\n", result);
		return;
	} 
	
	if (*str == '\0') {
		return;
	}
	
	//choose this character
	result[current] = *str;
	_combination(str+1, result, expected, current+1);
	
	result[current] = '\0';
	//don't choose this character
	_combination(str+1, result, expected, current);

}

/* *
 * Revert string from start to end
 * */
void revert_string(char *str, int start, int end)
{
	int i = start, j = end;
	char tmp;

	if (str == NULL || start < 0 || end < 0 
		|| start > end) {
		printf("Invalid input!\n");
		return;
	}

	while(i < j) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

/* *
 * revert sentence
 * */
void revert_word(char *str, int length)
{
	if (str == NULL || length <= 0) {
		printf("Invalid input!\n");
		return;
	}
	
	revert_string(str, 0, length - 1);
	
	int start = 0, end = 0;

	do {
		if (str[end] == ' ' || str[end] == '\0' || (length - 1) <= 0) {
			printf("revert:%s, start:%d, end:%d\n", str, start, end);
			revert_string(str, start, end - 1);
			start = end + 1;
		}
		if (str[end] == '\0')
			break;
		end++;
	} while(1);
}
