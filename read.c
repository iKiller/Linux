WORDS_S *ReadWordsV2(IN FILE *pf)
{
	CHAR cCH;
	CHAR szWord[30] = '\0';
	CHAR *pcCH;
    UINT uiLen = 0;
	WORDS_S *pstHead = NULL;
	WORDS_S *pstNode;

	cCH = fgetc(pf);                    /* 读取空格 */
	while (' ' == cCH)
	{
		cCH = fgetc(pf);
	}
	while (EOF != cCH)
	{

        /* 判断是否是单词组成字符，a~z、A~Z、“'”、“-” ，It's 、inter-bank\
        * 将被识别为一个单词*/
        while (((cCH >= 'a') && (cCH <= 'z')) || ((cCH >= 'A') && (cCH <= 'Z'))\
                || (cCH == 39) || (cCH == '-'))
        {
			szWord[uiLen] = cCH;
            uiLen++;                        /* 一个单词的长度 */
            cCH = fgetc(pf);
            if (EOF == cCH)                 /* 读到文件末尾 */
            {
                break;
            }
        }
        if (0 != uiLen)
        {
            pcCH = (CHAR *)malloc(uiLen + 1);
            if (NULL == pcCH)
            {
                printf("%s\n",ErrorInfo[APPLY_MEMORY_FAILED]);
                return NULL;
            }
            /* 字符串读取，从pf当前位置读取 (uiLen - 1) 个字符 */
            strncpy(pcCH,szWord,uiLen);
            pcCH[uiLen] = '\0';                 /* 字符串结束符 */

            pstNode = (WORDS_S *)malloc(sizeof(WORDS_S));
            if (NULL == pstNode)
            {
                printf("%s\n",ErrorInfo[APPLY_MEMORY_FAILED]);
                return NULL;
            }
            pstNode->pszWord = pcCH;
            pstNode->uiNum = 1;
            pstNode->pstNext = pstHead;
            pstHead = pstNode;
        }
        if (EOF == cCH)                     /* 读至文件末尾，结束读取单词*/
        {
            return pstHead;
        }
        cCH = fgetc(pf);                    /* 读取空格 */
        while (' ' == cCH)
        {
            cCH = fgetc(pf);
        }
        uiLen=0;
	}
	return pstHead;
}	
