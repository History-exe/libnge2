/***************************************************************************
 *            nge_gif.h
 *
 *  2011/03/26 02:03:11
 *  Copyright  2011  Kun Wang <ifreedom.cn@gmail.com>
 ****************************************************************************/
/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _NGE_GIF_H
#define _NGE_GIF_H

#include "nge_common.h"
#include "nge_image.h"
#include "nge_timer.h"

typedef struct _image_chain{
	image_p pimage;
	uint32  frame_delay;
	struct _image_chain* next;
}image_chains_t,*image_chains_p;

//struct tag_gif_desc_t;
#define GIF_SHOW_INIT 0
#define GIF_SHOW_PLAY 1
#define GIF_SHOW_STOP 2
//typedef image_p (*gif_nextframe)(struct tag_gif_desc_t* pgif);

typedef struct  tag_gif_desc_t{
	image_chains_p gif_image_chains;
	uint32	       gif_delay;
	sint32		   gif_transparent;
	uint32         gif_dispose;
	uint32		   gif_loopcount;
	sint32         gif_rgbtransparent;
	sint32         gif_rgbbackgnd;
	uint32         gif_w;
	uint32         gif_h;
	uint32         gif_texw;
	uint32         gif_texh;
	uint32         gif_framecount;
	/*for display*/
	nge_timer*     gif_inner_timer;
	uint32         gif_last_ticks;
	uint32         gif_current_ticks;
	uint32         gif_show_status;
	image_p        gif_current_frame;
	image_chains_p gif_current_chains;
}gif_desc_t,*gif_desc_p;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * gif�������س���,��gif����֡ȫ�����ص��ڴ�,
 * ��������Ԥ�ȼ��غ���,��ע���ڴ��ʹ����
 *@param[in] filename gif�ļ���
 *@param[in] displaymode ��ʾģʽ
 *@param[in] swizzle �Ż���־,ͨ����1
 *@return gif_desc_p gif��ͼ�ļ����,����ʾ��������
 */
	NGE_API gif_desc_p gif_animation_load(const char* filename,int displaymode,int swizzle);

/**
 * �ͷ�һ��gif������Դ
 *@param[in] pgif ��gif_animation_load���ص�������
 *@return
 */
	NGE_API void gif_animation_free(gif_desc_p pgif);

/**
 * ����Ļ����ʾһ��gif����1, Ч�����
 *@param[in] pgif ��gif_animation_load���ص�������
 *@param[in] x ��Ļx����
 *@param[in] y ��Ļy����
 *@return
 */
	NGE_API void GifAnimationToScreen(gif_desc_p pgif,float x,float y);

/**
 * ����Ļ����ʾһ��gif����2, Ч�����
 * sx,sy,sw,sh,���ɴ���ʾ�Ķ�����Χ������Ҫ��ʾһ��200*200�Ķ�����
 * 20��20��50��50�ߵ���ͼ�飬�����������20,20,50,50�����Ҫ��ʾԭͼ,������0
 * ����.����0����ʾ0,0,pgif->gif_w,pgif->gif_w��xscale,yscale�ǷŴ���С����1��ԭʼ������
 * ����Ŵ�һ��������2����С1����0.5��mask����ɫ���֣����ڶ�ͼƬ���л�ɫ��
 * �����͸��Ч���ȣ�Ĭ������ʾԭɫ��������pgif->gif_image_chains->pimage->mask����
 * ����1:��200*200�Ķ���pgif��ʾ����Ļ100��0�������Ŵ�һ����ʾ
 * RenderGifAnimation(pgif,0,0,0,0,100,0,2,2,0,pgif->gif_image_chains->pimage->mask);
 * ����2:������pgif��32��32��ʼ��64��,64�ߵĲ�����ʾ��40��80������ת90��
 * RenderGifAnimation(pgif,32,32,64,64,40,80,1,1,90,pgif->gif_image_chains->pimage->mask);
 * ����3:������pgif(pgif��ʾģʽ��8888)��80��80��ʼ��64��,64�ߵĲ�����ʾ��100��100������͸����ʾ
 * RenderGifAnimation(pgif,80,80,64,64,100,100,1,1,0,MAKE_RGBA_8888(255,255,255,128));
 *@param[in] pgif ��gif_animation_load���ص�������
 *@param[in] sx ����x����
 *@param[in] sy ����y����
 *@param[in] sw ������
 *@param[in] sh ������,
 *@param[in] dx ��Ļx����
 *@param[in] dy ��Ļy����
 *@param[in] xscale ����x����Ŵ���С����
 *@param[in] yscale ����y����Ŵ���С����
 *@param[in] angle ��ת�Ƕ�
 *@param[in] mask ��ɫ����
 *@return
 */
	NGE_API void RenderGifAnimation(gif_desc_p pgif,float sx ,float sy ,float sw ,float sh ,float dx ,float dy ,float xscale  ,float yscale ,float angle ,int mask);

/**
 * ����Ļ����ʾһ��gif����3
 * ͬDrawGifAnimation��ֻ�Ƕ��˸�MASK
 *@param[in] pgif ��gif_animation_load���ص�������
 *@param[in] sx ����x����
 *@param[in] sy ����y����
 *@param[in] sw ������
 *@param[in] sh ������
 *@param[in] dx ��Ļx����
 *@param[in] dy ��Ļy����
 *@param[in] dw ��Ļ��
 *@param[in] dh ��Ļ��
 *@param[in] mask ��ɫ����
 *@return ��
 */
	NGE_API void DrawGifAnimationMask(gif_desc_p pgif,float sx,float sy,float sw,float sh,float dx,float dy,float dw,float dh,int mask);

/**
 * ����Ļ����ʾһ��gif����3,sw,shΪ0�ǻ�ԭͼ��dw��dhΪ0����ʾsw��dh��С
 * ����1:��200*200��gif����pgif��ʾ����Ļ100��0��
 * DrawGifAnimation(pgif,0,0,0,0,100,0,0,0);
 * �������ϸ�ʽ��DrawGifAnimation(pgif,0,0,200,200,100,0,200,200);
 *@param[in] pgif ��gif_animation_load���ص�������
 *@param[in] sx ����x����
 *@param[in] sy ����y����
 *@param[in] sw ������
 *@param[in] sh ������
 *@param[in] dx ��Ļx����
 *@param[in] dy ��Ļy����
 *@param[in] dw ��Ļ��
 *@param[in] dh ��Ļ��
 *@return ��
 */
	NGE_API void DrawGifAnimation(gif_desc_p pgif,float sx,float sy,float sw,float sh,float dx,float dy,float dw,float dh);

#ifdef __cplusplus
}
#endif

#endif /* _NGE_GIF_H */
