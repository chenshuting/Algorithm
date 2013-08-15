/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  Implement test code
 *
 *        Version:  1.0
 *        Created:  08/15/2013 07:24:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include "test.h"
#include "string_ops.h"
#include <stdio.h>

void print_choice()
{
	printf("\n+++++++++++++++++++++++++++++\n");
	printf("Choose to run function:\n");	
	printf("%d. strcpy(dst,src)\n", STRCPY);
	printf("%d. strcmp(str1,str2)\n",STRCMP);
	printf("%d. strncmp(str1,str2,n)\n",STRNCMP);
	printf("%d. strstr(str1,str2)\n",STRSTR);
	printf("%d. strlen(str)\n",STRLEN);
	printf("%d. atoi(str)\n",ATOI);
	printf("%d. int2str(num, str, len)\n",INT2STR);
	printf("%d. permutation(str)\n",PERMUTATION);
	printf("%d. combination(str)\n",COMBINATION);
	printf("%d. revert_string(str)\n",REVERTSTR);
	printf("%d. revert_word(str)\n",REVERTWORD);
	printf("0. Quit!\n");
	printf("\n+++++++++++++++++++++++++++++\n");
}

void call_strcpy()
{
	char * str1 = "hello world";
	char str2[20] = "empty";
	printf("Before copy:\n");
	printf("str1:%s\nstr2:%s\n",str1,str2);
	cst_strcpy(str2, str1);
	printf("After copy:\n");
	printf("str1:%s\nstr2:%s\n",str1,str2);
}

void call_strcmp()
{
	char * str1 = "hello world";
	char * str2 = "hello sky";
	int result = 0;

	printf("Compare two string:\n");
	printf("str1:%s\nstr2:%s\n",str1,str2);
	result = cst_strcmp(str1, str2);
	if (result > 0)
		printf("[%s] > [%s]\n", str1, str2);
	else if (result < 0)
		printf("[%s] < [%s]\n", str1, str2);
	else
		printf("[%s] = [%s]\n", str1, str2);
}

void call_strncmp()
{
	char * str1 = "hello world";
	char * str2 = "hello sky";
	int result = 0;

	printf("Compare top 5 characters of two string:\n");
	printf("str1:%s\nstr2:%s\n",str1,str2);
	result = cst_strncmp(str1, str2, 5);
	if (result > 0)
		printf("[%s] > [%s]\n", str1, str2);
	else if (result < 0)
		printf("[%s] < [%s]\n", str1, str2);
	else
		printf("[%s] = [%s]\n", str1, str2);

}

void call_strstr()
{
	char * str1 = "hello world";
	char * str2 = "llo";
	int result = 0;

	printf("Check if %s is in %s:\n", str2, str1);
	result = cst_strstr(str1, str2);

	if (result >= 0)
		printf("[%s] is in [%s] start from %d\n", str2, str1, result);
	else
		printf("[%s] isn't in [%s]\n", str2, str1);

	
}

void call_strlen()
{
	char * str1 = "hello world";
	int len = 0;
	
	printf("test length of %s\n", str1);
	len = cst_strlen(str1);
	printf("Result: %d\n", len);
}

void call_atoi()
{
	printf("Convert [12345]> result:%d\n", cst_atoi("12345", 10));
	printf("Convert [   12345]> result:%d\n", cst_atoi("   12345", 10));
	printf("Convert [+12345]> result:%d\n", cst_atoi("+12345", 10));
	printf("Convert [-12345]> result:%d\n", cst_atoi("-12345", 10));
	printf("Convert [12A45]> result:%d\n", cst_atoi("12A45", 10));
	printf("Convert [1234567891098]> result:%d\n", cst_atoi("1234567891098", 10));
}

void call_int2str()
{
	int num1 = 12345;
	int num2 = -12345;
	char string[10];
	cst_int2str(num1, string, 9);
	printf("Convert number:[%d] to string[%s]\n", num1, string);
	cst_int2str(num2, string, 9);
	printf("Convert number:[%d] to string[%s]\n", num2, string);
}
void call_permutation()
{
	char * string = "abcdefg";	
	printf("Full permutation string: %s\n", string);
	permutation(string);
}
void call_combination()
{
	char * string = "abcdefg";	
	printf("Full combination string: %s\n", string);
	combination(string);
}

void call_revert_string()
{
	char * string = "abcdefg";	
	printf("Revert string: %s\n", string);
	revert_string(string);
	printf("Revert result: %s\n", string);
}

void call_revert_word(char *str)
{
	char * string = "Hello wolrd";	
	printf("Revert string: %s\n", string);
	revert_word(string);
	printf("Revert result: %s\n", string);
}
