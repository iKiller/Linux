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
#define MAX_NAME_SIZE 10
#define MAX_DESCRIPTION_SIZE 10

typedef union tagACL
{
    UINT uiAclIndex;
    CHAR szAclName[MAX_NAME_SIZE + 1];
}ACL_GROUPINDEX_U;

typedef struct tagACl
{
    CHAR szDescription[MAX_DESCRIPTION_SIZE + 1];
    ACL_GROUPINDEX_U unAcl;
    #define unAclName unAcl.szAclName
    #define unAclIndex unAcl.uiAclIndex
}ACL_S;

STATIC VOID acl_Init(ACL_S *pstACL)
{
    strlcpy(pstACL->szDescription, "Hello!", sizeof(pstACL->szDescription));                
    strlcpy(pstACL->unAclName, "VPN1", sizeof(pstACL->unAclName));

    printf("ACL_1 Init:\n");
    printf("\t%s\n", pstACL->szDescription);
    printf("\t%s\n\n", pstACL->unAclName);
}

INT main()
{
    ACL_S *pstACL1;
    ACL_S *pstACL2;

    pstACL1 = (ACL_S *) calloc(1UL, sizeof(ACL_S));
    
    acl_Init(pstACL1);
    
    pstACL2 = (ACL_S *) calloc(1UL, sizeof(ACL_S));    
    memcpy(pstACL2, pstACL1, sizeof(ACL_S));

    printf("ACL_1:\n");
    printf("\t%s\n", pstACL1->szDescription);
    printf("\t%s\n\n", pstACL1->unAclName);

    printf("ACL_2:\n");
    printf("\t%s\n", pstACL2->szDescription);
    printf("\t%s\n\n", pstACL2->unAclName);
    
    return 0;
}
