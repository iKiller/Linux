/**************************************************************
*    File Name: MoneyCombination.cpp
*       Author: JiangTao
*       E-mail: jt_2010@hust.edu.cn
*  Description: MoneyCombination.cpp
* Created Time: 2012/11/9 19:59:26
***************************************************************/

#include<iostream>
using namespace std;

#ifndef UINT
#define UINT unsigned int
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#define Money_Face_Value_Size 7
typedef struct StatMoney
{
    UINT   auiMoneyNum[Money_Face_Value_Size];
    struct StatMoney *pstStatMoneynext;
}STATMONEY_S;

class MoneyCombination
{
    private:
        UINT auiMoney[Money_Face_Value_Size] = {1,2,5,10,20,50,100};
        STATMONEY_S *pstHead;
        UINT uiSumComb;
        UINT uiCount;

    public:
        MoneyCombination(IN STATMONEY_S *pstH, IN UINT uiSum, IN UINT uiCon)
        {
            pstHead = pstH;
            uiSumComb = uiSum;
            uiCount = uiCon;
        }
        
        STATMONEY_S *CalculateMoneyCombinations(IN UINT uiSum, IN UINT uiMoneyFaceValueSize);        
        void ShowMoneyCombination(void);
};  

STATMONEY_S *MoneyCombination::CalculateMoneyCombinations(IN UINT uiSum, IN UINT uiMoneyFaceValueSize)
{
    UINT *puiArray;
    UINT  uiPos;
    UINT  uiIndex;
    UINT  uiRest;
    STATMONEY_S *pstNode;

    uiPos = Money_Face_Value_Size - 1;
    uiIndex = uiMoneyFaceValueSize - 1;
    uiRest = uiSum;
    pstHead = NULL;
    puiArray = NULL;

    pstNode = (STATMONEY_S *) malloc(sizeof(STATMONEY_S));
    if ((NULL == pstHead) && (NULL != pstNode))
    {
        puiArray = pstNode->auiMoneyNum;
        uiRest = uiSum;
        while (0 <= uiPos)
        {
            puiArray[uiPos] = uiRest/auiMoney[uiPos]
            uiRest = uiRest%auiMoney[uiPos];
            uiPos--;
        }

    }
    else if (NULL != pstNode)
    {
        puiArray = pstNode->auiMoneyNum;
        while (uiIndex < uiPos)
        {
            puiArray[uiPos] = pstHead->auiMoneyNum[uiPos];
            uiPos--;
        }
        while (0 <= uiMoneyFaceValueSize)
        {
            puiArray[uiPos] =  uiRest/auiMoney[uiPos];
            uiRest = uiRest%auiMoney[uiPos];
            
        }
    }
    pstNode->pstStatMoneynext = pstHead;
    pstHead = pstNode;
    
}

int main()
{


