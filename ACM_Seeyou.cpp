/*
 * =====================================================================================
 *
 *       Filename:  ACM_Seeyou.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/3/24 1:02:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jt
 *          Email:  jt_2010@hust.edu.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include "public.h"

using namespace std;

typedef struct tagSeeYou_Grid
{
    INT aiGrid[3];
    struct tagGrid *pstNext;
    struct tagGrid *pstPre;
}Grid_Node_S;

class S
{
    private:
        INT iX1;
        INT iX2;
        INT iY1;
        INT iY2;
        Grid_Node_S *pstGridLit;

    SeeYou_CalculateBooks();
    S(IN INT iM = 0, IN INT iN = 0, IN INT iX = 0, IN INT iY = 0)
    {

    }
    A(IN INT iX, IN INT iY, IN INT iN1);
    D(IN INT iX, IN INT iY, IN INT iN1);
    M(IN INT iX1, IN INT iY1, IN INT iX2, IN INT iY2, IN INT iN1);
    SeeYou_Init();
    SeeYou_GetNode(IN INT iX, IN INT iY);
    SeeYou_CreatNode();
}

S::Grid_Node_S *SeeYou_CreateNode(VOID);
{
    Grid_Node_S *pstGridNode;

    pstGridNode = (Grid_Node_S *)calloc(1UL, sizeof(Grid_Node_S));
    return pstGridNode;
}

/***************************************** 
*       Func:SeeYou_GetNode
*Description:获取格子
*     IN PUT:INT iX, 格子的横坐标；
*            INT iY, 格子的纵坐标；
*    OUT PUT:无
*     Return:Grid_Node_S *pstGridNode; 获取的格子指针
******************************************/
S::Grid_Node_S *SeeYou_GetNode(IN INT iX, IN INT iY)
{   
    INT *piGrid;
    Grid_Node_S *pstGridNode;

    pstGridNode = pstGridList;
    while(NULL != pstGridNode)
    {
        piGrid = psyGridNode.aiGrid;
        if ((iX == *piGrid) && (iY == *(pstGrid+1)))
        {
            break;
        }

        pstGridNode = pstGridNode->pstNext;
    }

    return pstGridNode;
}

S::SeeYou_CalculateBooks()
{
    INT iSum;

    iSum = (iX1-iX2)*(iY1-iY2);

}

S::A(IN INT iX, IN INT iY, IN INT iN1)
{
    INT *piGrid;
    Grid_Node_S *pstGridNode;
    Grid_Node_S *pstGridNodeTmp;

    pstGridNode = SeeYou_GetNode(iX, iY);
    if (NULL == pstGridNode)
    {
        pstGridNode = (Grid_Node_S *)calloc(1UL, sizeof(Grid_Node_S));
        if (NULL == pstGridNode)
        {
            return;
        }
        
        pstGridNode->pstNext = NULL;
        pstGridNode->pstPre = NULL;

        piGrid = pstGridNode->aiGrid;
        piGrid[0] = iX;
        piGrid[1] = iY;
        piGrid[2] = iN1;
    
        if (NULL == pstGridList)
        {
            pstGridList = pstGridNode;
        }
        else
        {
            pstGridNodeTmp = pstGridList;
            while(NULL != pstGridNodeTmp)
            {
                
            }
        }

        
    }
}
