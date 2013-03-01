#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *pcName;

    pcName = (char *)malloc(10*sizeof(char));

    printf("%s\n\n",pcName);
    printf("The length is %d\n",strlen(pcName));

    return 0;
}
