/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/1/23 11:27:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jt
 *          Email:  jt_2010@hust.edu.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"public.h"

#pragma pack(1)
struct tagACl
{
    UINT uiAclNum;
    CHAR szAclName[10];
};
#pragma pack()

INT main()
{
	struct tagAcl Acl1;

	Acl1.szAclName = 'hub1';

	printf("%s", Acl1.szAclName);

    return 0;
}
