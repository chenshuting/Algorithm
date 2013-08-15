/*
 * =====================================================================================
 *
 *       Filename:  string.c
 *
 *    Description:  String operations
 *
 *        Version:  1.0
 *        Created:  08/15/2013 12:46:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "test.h"
#include "string_ops.h"

int main()
{
	unsigned char choice = 0;
	int type = 1;

	print_choice();
	while(type != 0){
		printf(">");
		scanf("%c", &choice);
		type = choice - '0';
		switch(type) {
			case STRCPY:
				call_strcpy();
				break;
			case STRCMP:
				call_strcmp();
				break;
			case STRNCMP:
				call_strncmp();
				break;
			case STRSTR:
				call_strstr();
				break;
			case STRLEN:
				call_strlen();
				break;
			case ATOI:
				call_atoi();
				break;
			case INT2STR:
				call_int2str();
				break;
			case PERMUTATION:
				call_permutation();
				break;
			case COMBINATION:
				call_combination();
				break;
			case REVERTSTR:
				call_revert_string;
				break;
			case REVERTWORD:
				call_revert_word();
				break;
			default:
				break;
		}
	}
	return 0;
}
