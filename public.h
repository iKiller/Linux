#include<string.h>

#ifndef _PUBILC_H
#define _PUBILC_H
#endif

#define VOID   void
#define UINT   unsigned int
#define INT    int
#define ULONG  unsigned long
#define LONG   long
#define STATIC static
#define CHAR   char
#define UCHAR  unsigned char

#define INOUT  /* input and output  */
#define IN     /* input             */
#define OUT    /* output            */

size_t strlcpy(char *dst,
               const char *src,
               size_t size)
{
    register char *d = dst;
    register const char *s = src;
    register size_t n = size;

    /* Copy as many bytes as will fit */
    if ((0 != n) && (0 != (--n)))
    {
        do
        {
            if (0 == (*(d++) = *(s++)))
            {
                break;
            }
        }while(0 != (--n));
    }

    /* Not enough room in dst, add NUL and traverse rest of src */
    if (0 == n)
    {
        if (0 != size)
        {
            *d = '\0';
        }

        while (*(s++))
        {
            ;
        }
    }

    /* count dest not include NUL */
    return (s-src-1);
}
