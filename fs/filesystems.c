/*
 *  linux/fs/filesystems.c
 *
 *  Copyright (C) 1991, 1992  Linus Torvalds
 *
 *  table of configured filesystems
 */

#include <linux/config.h>
#include <linux/fs.h>
#ifdef CONFIG_PROC_FS
#include <linux/proc_fs.h>
#endif
#ifdef CONFIG_EXT2_FS
#include <linux/ext2_fs.h>
#endif
#ifdef CONFIG_NFS_FS
#include <linux/nfs_fs.h>
#endif
#ifdef CONFIG_SYSV_FS
#include <linux/sysv_fs.h>
#endif

struct file_system_type file_systems[] = {
#ifdef CONFIG_EXT2_FS
	{ext2_read_super,	"ext2",		1},
#endif
#ifdef CONFIG_PROC_FS
	{proc_read_super,	"proc",		0},
#endif
#ifdef CONFIG_NFS_FS
	{nfs_read_super,	"nfs",		0},
#endif
#ifdef CONFIG_SYSV_FS
	{sysv_read_super,	"xenix",	1},
	{sysv_read_super,	"sysv",		1},
	{sysv_read_super,	"coherent",	1},
#endif
	{NULL,			NULL,		0}
};
