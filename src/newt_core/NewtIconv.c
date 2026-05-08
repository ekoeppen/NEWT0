/**
 * @file	NewtIconv.c
 * @brief   Character encoding conversion (Internal implementation)
 *
 * @author  M.Nukui
 * @date	2005-07-17
 *
 * Copyright (C) 2005 M.Nukui All rights reserved.
 */

#include <stdlib.h>
#include <string.h>
#include "NewtIconv.h"

enum {
    kNewtConvUTF16BE_To_Internal = 1,
    kNewtConvInternal_To_UTF16BE,
    kNewtConvMacRoman_To_Internal,
    kNewtConvInternal_To_MacRoman
};

newt_iconv_t NewtIconvOpen(const char *tocode, const char *fromcode)
{
    if (strcmp(tocode, "UTF-16BE") == 0) return kNewtConvInternal_To_UTF16BE;
    if (strcmp(tocode, "MACROMAN") == 0) return kNewtConvInternal_To_MacRoman;
    if (strcmp(fromcode, "UTF-16BE") == 0) return kNewtConvUTF16BE_To_Internal;
    if (strcmp(fromcode, "MACROMAN") == 0) return kNewtConvMacRoman_To_Internal;
    return -1;
}

size_t NewtIconv(newt_iconv_t cd, char **inbuf, size_t *inbytesleft, char **outbuf, size_t *outbytesleft)
{
    size_t n = 0;
    switch (cd) {
        case kNewtConvInternal_To_UTF16BE:
            while (*inbytesleft >= 1 && *outbytesleft >= 2) {
                (*outbuf)[0] = 0;
                (*outbuf)[1] = (*inbuf)[0];
                *inbuf += 1; *inbytesleft -= 1;
                *outbuf += 2; *outbytesleft -= 2;
                n++;
            }
            break;
        case kNewtConvUTF16BE_To_Internal:
            while (*inbytesleft >= 2 && *outbytesleft >= 1) {
                (*outbuf)[0] = (*inbuf)[1];
                *inbuf += 2; *inbytesleft -= 2;
                *outbuf += 1; *outbytesleft -= 1;
                n++;
            }
            break;
        case kNewtConvInternal_To_MacRoman:
        case kNewtConvMacRoman_To_Internal:
            // Minimalist identity mapping for ASCII. 
            // Real MacRoman mapping could be added here if needed.
            while (*inbytesleft >= 1 && *outbytesleft >= 1) {
                (*outbuf)[0] = (*inbuf)[0];
                *inbuf += 1; *inbytesleft -= 1;
                *outbuf += 1; *outbytesleft -= 1;
                n++;
            }
            break;
        default:
            return (size_t)-1;
    }
    return n;
}

int NewtIconvClose(newt_iconv_t cd)
{
    return 0;
}

char * NewtIconvConvert(newt_iconv_t cd, const char * src, size_t srclen, size_t* dstlenp)
{
    char *	dst = NULL;
    size_t	dstlen = 0;

    if (cd != (newt_iconv_t)-1)
    {
        size_t	bufflen;
        bufflen = srclen * 2 + 2; // Sufficient for UTF-16
        dst = malloc(bufflen);

        if (dst)
        {
            char *	inbuf_p = (char *)src;
            char *	outbuf_p = dst;
            size_t	inbytesleft = srclen;
            size_t	outbytesleft = bufflen;
            size_t	status;

            status = NewtIconv(cd, &inbuf_p, &inbytesleft, &outbuf_p, &outbytesleft);

            if (status == (size_t)-1)
            {
                free(dst);
                dst = NULL;
            }
            else
            {
                dstlen = bufflen - outbytesleft;
                dst = realloc(dst, dstlen);
            }
        }
    }

    if (dstlenp) *dstlenp = dstlen;
    return dst;
}
