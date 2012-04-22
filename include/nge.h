/**
 * @file  nge.h
 * @author Kun Wang <ifreedom.cn@gmail.com>
 * @date 2012/02/12 09:34:32
 *
 *  Copyright  2012  Kun Wang <ifreedom.cn@gmail.com>
 *
 */

#ifndef _NGE_H
#define _NGE_H

#include "nge_common.h"

#define INIT_VIDEO 1
#define INIT_AUDIO 2
#define INIT_ALL   INIT_VIDEO|INIT_AUDIO

enum NotifyType
{
	NGE_NOTIFY_PAUSE = 0,
	NGE_NOTIFY_RESUME,
	NGE_NOTIFY_STOP
};

/**
 *�ص�����
 *@param int type, ֪ͨ����
 *@param void* data, ֪ͨ����
 *@param void* pCookie, �û�����
 */
typedef void (*NotifyCallback)(int type, void* data, void* pCookie);

#ifdef __cplusplus
extern "C"{
#endif

/**
 *NGE��ʼ������
 *@param int flags,��ʼ����־λ,INIT_VIDEO(��Ƶ),INIT_AUDIO(��Ƶ)����INIT_ALL
 *@return ��
 */
	NGE_API void NGE_Init(int flags);

/**
 *NGE�˳�����
 *@return ��
 */
	NGE_API void NGE_Quit();

/**
 *������Ļ����
 *@param const char* winname,��������
 *@param int screen_width,���ڿ�
 *@param int screen_height,���ڸ�
 *@param int screen_bpp,����bpp,ͨ����32
 *@param int screen_full,�Ƿ�ȫ��0-����,1-ȫ��
 *@return
 */
	NGE_API void NGE_SetScreenContext(const char* winname,int screen_width,int screen_height,int screen_bpp,int screen_full);

/**
 *����ϵͳԭ����Ļ�ֱ���
 *@param int width,���
 *@param int height,�߶�
 */
	NGE_API void NGE_SetNativeResolution(int width,int height);

/**
 *����Ƭͷ������ַ
 *@param const char* path,��ַ
 */
	NGE_API void NGE_SetOPMoviePath(const char* path);

/**
 *ע��֪ͨ�ص�����
 *@param NotifyCallback cb, �ص�����
 */
	NGE_API void NGE_RegisterNotifyCallback(NotifyCallback cb, void* pCookie);

#ifdef NGE_PSP
/**
 *ע��PSP���˳��ص�
 *@param int cb_id, �ص���ʶ��
 */
	NGE_API void NGE_RegisterPSPExitCallback(int cb_id);
#endif

#ifdef __cplusplus
}
#endif

#endif /* _NGE_H */
