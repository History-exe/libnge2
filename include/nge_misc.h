﻿#ifndef NGE_MISC_H_
#define NGE_MISC_H_

#include "nge_common.h"

//休眠毫秒数
#if defined WIN32
#include <winbase.h>
#define nge_sleep(tick) Sleep(tick)

#elif defined _PSP
#include <pspthreadman.h>
#define nge_sleep(tick) sceKernelDelayThread((tick)*1000)

#elif defined __linux__
#include <unistd.h>
#define nge_sleep(tick) usleep(tick)
#endif

#ifdef __cplusplus
extern "C"{
#endif

/**
 *生成一个min---max的浮点数
 */
	NGE_API float rand_float(float min, float max);
/**
 *生成一个(min,max)的整数
 */
	NGE_API int rand_int(int min, int max);

/**
 *将GBK编码的字符转化为unicode字符
 *注意outbuffer需要预先分配足够大小.
 *@param unsigned short* out,转换后unicode字符保存在这里,注意需要预先分配足够大小
 *@param const char* in,输入字符缓存
 *@param int n,GBK字符个数以字节记,strlen计算的个数(例如一个汉字为2个字符)
 *@return int n,转换的unicode字符个数
 */
	NGE_API int gbk_to_unicode(unsigned short* out,const char* in,int n);

#ifdef __cplusplus
}
#endif

#endif
