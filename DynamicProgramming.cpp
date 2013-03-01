/**************************************************************
*    File Name: DynamicProgramming.cpp
*       Author: JiangTao
*       E-mail: jt_2010@hust.edu.cn
*  Description: DynamicProgramming.cpp
* Created Time: 2012/11/7 14:41:05
***************************************************************/

#include<iostream>
using namespace std;
#define ARRAY_SIZE 10

class ArraySum
{
    private:
        int *piArray;
        int iMAX_SUM;
        int iSTART;
        int iLen;
        int iSubLen;

    public:
        ArraySum(int *piA = NULL, int iMax = 0, int iStart = 0, int iLength = 0, int iSubLength = 1);
        void SetArraySum(int *piA = NULL, int iMax = 0, int iStart = 0, int iLength = 0, int iSubLength = 1);
        void ShowMaxSubArray();
        void CalculateFixedLenMaxSubArray(int iSubLength = 1);
        void CalculateMaxSubArray();
};

ArraySum::ArraySum(int *piA, int iMax, int iStart, int iLength, int iSubLength)
{
    piArray = piA;
    iMAX_SUM = iMax;
    iSTART = iStart;
    iLen = iLength;
    iSubLen = iSubLength;
}

void ArraySum::SetArraySum(int *piA, int iMax, int iStart, int iLength, int iSubLength)
{
    piArray = piA;
    iMAX_SUM = iMax;
    iSTART = iStart;
    iLen = iLength;
    iSubLen = iSubLength;
}

void ArraySum::ShowMaxSubArray()
{
    cout << "The max subarray is:  a["<< iSTART << ":" << iSTART + iSubLen << "]" <<endl;
    cout << "The sum of the subarray is: ∑ a["<< iSTART << ":" << iSTART + iSubLen << "] = " << iMAX_SUM <<endl;
}

void ArraySum::CalculateFixedLenMaxSubArray(int iSubLength)
{
    int iSum = 0;

    for(int i=0; (i + iSubLength) < iLen; i++)
    {
        for(int j=0; (i + j) < (i + iSubLength); j++)
        {
            iSum += piArray[i+j];
        }
        if (iSum > iMAX_SUM)
        {
            iSTART = i;
            iMAX_SUM = iSum;
            iSubLen = iSubLength;
        }
        iSum = 0;
    }
}

void ArraySum::CalculateMaxSubArray()
{
    for(int i=1; i < iLen + 1; i++)
    {
        CalculateFixedLenMaxSubArray(i);
    }
}

int main()
{
    ArraySum ac;
    int a[ARRAY_SIZE];
    int i;

    cout << "Please input the array:\n" <<endl;
    for(i=0; i < ARRAY_SIZE; i++)
    {
        cin >> a[i];
    }

    ac.SetArraySum(a, a[0], 0, i, 1);
    ac.CalculateMaxSubArray();
    ac.ShowMaxSubArray();

    return 0;
}

