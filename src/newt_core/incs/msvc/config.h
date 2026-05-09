/*------------------------------------------------------------------------*/
/**
 * @file	config.h
 * @brief   Configuration for MSVC
 *
 * @author  M.Nukui
 * @date	2005-04-30
 *
 * Copyright (C) 2005 M.Nukui All rights reserved.
 */


#ifndef	CONFIG_H
#define	CONFIG_H

/* マクロ定義 */
#undef HAVE_INTTYPES_H
#define HAVE_STDINT_H 1
#define HAVE_MEMORY_H 1
#undef HAVE_UNISTD_H
#undef HAVE_ENDIAN_H
#undef HAVE_MACHINE_ENDIAN_H
#undef HAVE_TERMIOS_H 

#undef HAVE_LIBICONV
#undef HAVE_DLOPEN
#undef HAVE_MMAP
#define HAVE_CHDIR 1
#define HAVE_GETCWD 1
#undef HAVE_GETPWNAM

#define __PLATFORM__ "msvc"
#define __DYLIBSUFFIX__ ".dll"
#define __LIBDIR__ ""

#undef __IPOD__

#if defined(_MSC_VER)
    #include <BaseTsd.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include <direct.h>
    #include <io.h>
    #include <errno.h>
    typedef SSIZE_T ssize_t;
    #include <string.h>
    #include <ctype.h>
    static inline char *strcasestr(const char *s, const char *find) {
        char c, sc;
        size_t len;
        if ((c = *find++) != 0) {
            c = (char)tolower((unsigned char)c);
            len = strlen(find);
            do {
                do {
                    if ((sc = *s++) == 0) return (NULL);
                } while ((char)tolower((unsigned char)sc) != c);
            } while (_strnicmp(s, find, len) != 0);
            s--;
        }
        return ((char *)s);
    }
#endif

#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#define chdir _chdir
#define getcwd _getcwd

static inline int safe_isatty(int fd) {
    if (fd >= 0) {
        return _isatty(fd);
    }
    return 0;
}

#define isatty safe_isatty
#define fileno _fileno

#endif /* CONFIG_H */
