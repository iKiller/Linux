WORDS_S *ReadWordsV2(IN FILE *pf)
{
	CHAR cCH;
	CHAR szWord[30] = '\0';
	CHAR *pcCH;
    UINT uiLen = 0;
	WORDS_S *pstHead = NULL;
	WORDS_S *pstNode;

	cCH = fgetc(pf);                    /* ��ȡ�ո� */
	while (' ' == cCH)
	{
		cCH = fgetc(pf);
	}
	while (EOF != cCH)
	{

        /* �ж��Ƿ��ǵ�������ַ���a~z��A~Z����'������-�� ��It's ��inter-bank\
        * ����ʶ��Ϊһ������*/
        while (((cCH >= 'a') && (cCH <= 'z')) || ((cCH >= 'A') && (cCH <= 'Z'))\
                || (cCH == 39) || (cCH == '-'))
        {
			szWord[uiLen] = cCH;
            uiLen++;                        /* һ�����ʵĳ��� */
            cCH = fgetc(pf);
            if (EOF == cCH)                 /* �����ļ�ĩβ */
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
            /* �ַ�����ȡ����pf��ǰλ�ö�ȡ (uiLen - 1) ���ַ� */
            strncpy(pcCH,szWord,uiLen);
            pcCH[uiLen] = '\0';                 /* �ַ��������� */

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
        if (EOF == cCH)                     /* �����ļ�ĩβ��������ȡ����*/
        {
            return pstHead;
        }
        cCH = fgetc(pf);                    /* ��ȡ�ո� */
        while (' ' == cCH)
        {
            cCH = fgetc(pf);
        }
        uiLen=0;
	}
	return pstHead;
}	
