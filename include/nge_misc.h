#ifndef NGE_MISC_H_
#define NGE_MISC_H_

//���ߺ�����
#if defined WIN32
#include "SDL.h"
#define nge_sleep(tick) SDL_Delay(tick)

#elif defined _PSP
#include <pspthreadman.h>
#define nge_sleep(tick) sceKernelDelayThread((tick)*1000)

#elif defined IPHONEOS || defined(__linux__)
#include <stdlib.h>
#define nge_sleep(tick) usleep(tick)
#endif

#ifdef __cplusplus
extern "C"{
#endif

//����һ��min---max�ĸ�����
float rand_float(float min, float max);
//����һ��(min,max)������
int rand_int(int min, int max);

/**
 *��GBK������ַ�ת��Ϊunicode�ַ�
 *ע��outbuffer��ҪԤ�ȷ����㹻��С.
 *@param unsigned short* out,ת����unicode�ַ�����������,ע����ҪԤ�ȷ����㹻��С
 *@param const char* in,�����ַ�����
 *@param int n,GBK�ַ��������ֽڼ�,strlen����ĸ���(����һ������Ϊ2���ַ�)
 *@return int n,ת����unicode�ַ�����
 */
int gbk_to_unicode(unsigned short* out,const char* in,int n);

#ifdef __cplusplus
}
#endif

#endif
