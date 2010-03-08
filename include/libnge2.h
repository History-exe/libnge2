#ifndef LIBNGE2_H_
#define LIBNGE2_H_
#if defined WIN32 || defined IPHONEOS
#include <SDL.h>
#endif

#ifdef __cplusplus
extern "C"{
#endif

#include "nge_image_load.h"
#include "nge_io_file.h"
#include "nge_debug_log.h"
#include "nge_font.h"
#include "nge_graphics.h"
#include "nge_input_proc.h"
#include "nge_main.h"
#include "nge_misc.h"
#include "nge_timer.h"
#include "audio_interface.h"
#include "movieplay/nge_movie.h"
#include "nge_gif_animation.h"
#include "nge_gif_show.h"
#include "nge_sys_compatible.h"
#include "nge_io_dir.h"
#include "nge_graphics_ext.h"

#ifdef __cplusplus
}
#endif


#if defined WIN32 || defined IPHONEOS
#define INIT_VIDEO SDL_INIT_VIDEO
#define INIT_AUDIO SDL_INIT_AUDIO
#define INIT_ALL   INIT_VIDEO|INIT_AUDIO
#else
#define INIT_VIDEO 1
#define INIT_AUDIO 2
#define INIT_ALL   INIT_VIDEO|INIT_AUDIO
#endif

#define NGE_VERSION "2.0.0"


#ifdef __cplusplus
extern "C"{
#endif
/**
 *NGE��ʼ������
 *@param int flags,��ʼ����־λ,INIT_VIDEO(��Ƶ),INIT_AUDIO(��Ƶ)����INIT_ALL
 *@return ��
 */
void NGE_Init(int flags);
/**
 *NGE�˳�����
 *@return ��
 */
void NGE_Quit();
/**
 *������Ļ����
 *@param const char* winname,��������
 *@param int screen_width,���ڿ�
 *@param int screen_height,���ڸ�
 *@param int screen_bpp,����bpp,ͨ����32
 *@param int screen_full,�Ƿ�ȫ��0-����,1-ȫ��
 *@return 
 */
void NGE_SetScreenContext(const char* winname,int screen_width,int screen_height,int screen_bpp,int screen_full);

#ifdef __cplusplus
}
#endif

#endif