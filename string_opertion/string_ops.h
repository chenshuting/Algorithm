/*
 * =====================================================================================
 *
 *       Filename:  string_ops.h
 *
 *    Description:  To define the functions
 *
 *        Version:  1.0
 *        Created:  08/15/2013 03:34:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#define MAX_INT (2147483647)//((0x01 << 31) - 1)
#define MIN_INT (-2147483647)//(-MAX_INT) 
/*simulate system function*/
char *cst_strcpy(char * dst, char *src);
int cst_strcmp(char *str1, char *str2);
int cst_strncmp(char *str1, char *str2, int n);
int cst_strstr(char *str1, char *str2);
int cst_strlen(char *str);
int cst_atoi(char *str, int radix);

/*Complex application*/
char * cst_int2str(int num, int radix, char *str, int length);
void permutation(char *str);
void _permutation(char *str, char *begin);
void combination(char *str);
void _combination(char *str, char *result, int expected, int current);
void revert_string(char *str, int start, int end);
void revert_word(char *str, int length);
