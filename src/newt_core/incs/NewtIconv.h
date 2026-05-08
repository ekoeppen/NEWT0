/*------------------------------------------------------------------------*/
/**
 * @file	NewtIconv.h
 * @brief   文字コード処理（libiconv使用）
 *
 * @author  M.Nukui
 * @date	2005-07-17
 *
 * Copyright (C) 2005 M.Nukui All rights reserved.
 */


#ifndef	NEWTICONV_H
#define	NEWTICONV_H


/* ヘッダファイル */
#include "NewtType.h"


/* マクロ */
typedef intptr_t newt_iconv_t;


/* 関数プロトタイプ */

#ifdef __cplusplus
extern "C" {
#endif


newt_iconv_t	NewtIconvOpen(const char *tocode, const char *fromcode);
size_t			NewtIconv(newt_iconv_t cd, char **inbuf, size_t *inbytesleft, char **outbuf, size_t *outbytesleft);
int				NewtIconvClose(newt_iconv_t cd);

char *			NewtIconvConvert(newt_iconv_t cd, const char* src, size_t srclen, size_t* dstlenp);


#ifdef __cplusplus
}
#endif


#endif /* NEWTICONV_H */
