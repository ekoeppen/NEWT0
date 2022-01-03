/**
 * @file	config.h
 * @brief   コンフィグ設定
 *
 * @author  M.Nukui
 * @date	2005-04-30
 *
 * Copyright (C) 2005 M.Nukui All rights reserved.
 */


#ifndef	CONFIG_H
#define	CONFIG_H


/* マクロ定義 */
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_MEMORY_H 1
#define HAVE_UNISTD_H 1
/* #undef HAVE_ENDIAN_H */
/* #undef HAVE_MACHINE_ENDIAN_H 1 */
#define HAVE_TERMIOS_H 1

#define HAVE_DLOPEN 1
#define HAVE_MMAP 1
#define HAVE_CHDIR 1
#define HAVE_GETCWD 1
#define HAVE_GETPWNAM 1

#define __PLATFORM__ "linux"
#define __DYLIBSUFFIX__ ".so"
#define __LIBDIR__ "/usr/local/lib/newt0"

/* #undef __IPOD__ */


#endif /* CONFIG_H */
