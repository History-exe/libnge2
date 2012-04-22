/***************************************************************************
 *            nge_png.h
 *
 *  2011/03/25 03:31:07
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

#ifndef _NGE_PNG_H
#define _NGE_PNG_H

#include "nge_common.h"
#include "nge_image.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *����pngͼƬ,���ļ�����
 *@param const char* filename,ͼƬ�ļ���
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����ͼƬ���˽ṹ
 */
	NGE_API image_p image_load_png(const char* filename, int displaymode);

/**
 *����pngͼƬ,���ڴ����
 *@param const char* mbuf,�ڴ��ַ
 *@param int bsize,����buffer��С
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
	NGE_API image_p image_load_png_buf(const char* mbuf,int bsize, int displaymode);

/**
 *����pngͼƬ,���ļ�ָ�����
 *@param int handle,�ļ�ָ��
 *@param int fsize,�����ļ���С
 *@param int autoclose,�Ƿ�ر��ļ�,0���ر�,1�ر�
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
	NGE_API image_p image_load_png_fp(int handle,int fsize, int autoclose,int displaymode);

/**
 * ͬimage_load_png����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
	NGE_API image_p image_load_png_colorkey(const char* filename, int displaymode,int colorkey);

/**
 * ͬimage_load_png_buf����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
	NGE_API image_p image_load_png_colorkey_buf(const char* mbuf, int bsize, int displaymode,int colorkey);

/**
 * ͬimage_load_png_fp����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
	NGE_API image_p image_load_png_colorkey_fp(int handle,int fsize, int autoclose,int displaymode,int colorkey);

/**
 *�洢pngͼƬ,��image_p�ṹ���ݴ洢Ϊpng�ļ�
 *@param image_p,image_p�ṹָ��,���汣��Ϊimage_t������
 *@param const char*,�����ļ���
 *@param uint8,�Ƿ񱣴�Ϊ��alphaͨ����ͼƬ
 *@return int,����0(����ʧ��)��1(���سɹ�)
 */
	NGE_API int image_save_png(image_p pimage,const char* filename,uint8 alpha);

#ifdef __cplusplus
}
#endif
#endif /* _NGE_PNG_H */
