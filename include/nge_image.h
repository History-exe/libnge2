/***************************************************************************
 *            nge_image.h
 *
 *  2011/03/25 04:56:54
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

#ifndef _NGE_IMAGE_H
#define _NGE_IMAGE_H

#include "nge_common.h"
#include "nge_color.h"

typedef struct tagImage{
	uint32  w;        /**< ͼƬԭ�� */
	uint32  h;        /**< ͼƬԭ�� */
	uint32  texw;     /**< ͼƬ��ͼ�� */
	uint32  texh;     /**< ͼƬ��ͼ�� */
	uint8   bpb;      /**< ÿ�����ֽ���(16λ2�ֽ�,32λ4�ֽ�) */
	uint8   swizzle;  /**< �Ƿ��data swizzle �Ż�*/
	uint32  mode;     /**< GSM��ʾmode for psp */
	uint32  dtype;    /**< ��ʾģʽ(DISPLAY_PIXEL_FORMAT_XXX��һ��) */
	uint8*  data;     /**< ͼ������ */
	float   rcentrex; /**< ͼ������x */
	float   rcentrey; /**< ͼ������y */
	uint32  texid;    /**< ͼ��id */
	uint8   modified; /**< ǿ�Ƹ����Դ�*/
	uint8   dontswizzle; /**ǿ�Ʋ�swizzle �Ż�*/
	int     mask;     /**< ��ɫ����,������ʾ����Ч��*/
}image_t,*image_p;

extern uint32 image_tid;

#ifdef __cplusplus
extern "C" {
#endif

/**
 *����ͼƬ,���ļ�����
 *@param const char* filename,ͼƬ�ļ���
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@param int swizzle,�Ƿ����Ż�,��0�����Ż�,ͨ����1
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
	NGE_API image_p image_load(const char* filename, int displaymode,int swizzle);

/**
 *����ͼƬ,���ڴ����
 *@param const char* mbuf,�ڴ��ַ
 *@param int bsize,����buffer��С
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@param int swizzle,�Ƿ����Ż�,��0�����Ż�,ͨ����1
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
	NGE_API image_p image_load_buf(const char* mbuf,int bsize, int displaymode,int swizzle);

/**
 *����ͼƬ,���ļ�ָ�����
 *@param int handle,�ļ�ָ��
 *@param int fsize,�����ļ���С
 *@param int autoclose,�Ƿ�ر��ļ�,�Ƿ�ر��ļ�,0���ر�,1�ر�
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@param int swizzle,�Ƿ����Ż�,��0�����Ż�,ͨ����1
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
	NGE_API image_p image_load_fp(int handle,int fsize, int autoclose,int displaymode,int swizzle);

/**
 * ͬimage_load����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
	NGE_API image_p image_load_colorkey(const char* filename, int displaymode,int colorkey,int swizzle);

/**
 * ͬimage_load_buf����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
	NGE_API image_p image_load_colorkey_buf(const char* mbuf,int bsize, int displaymode,int colorkey,int swizzle);

/**
 *����һ��image�ṹ,��ʾģʽ��displaymode
 *@param int w,image�Ŀ�
 *@param int h,image�ĸ�
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p pimage,����imageָ��
 */
	NGE_API image_p image_create(int w,int h,int displaymode);

/**
 *����һ��image�ṹ,��ʾģʽ��displaymode
 *@param int w,image�Ŀ�
 *@param int h,image�ĸ�
 *@param int color,��ɫ,Ϊ��֤����������MAKE_RGBA_XXXX���������ɫ
 *@param int displaymode,��ʾģʽ,����ɫһ��,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p pimage,����imageָ��
 */
	NGE_API image_p image_create_ex(int w,int h,int color,int displaymode);

/**
 *��image���棬�����ļ����жϱ���ĸ�ʽ��Ŀǰ֧��png��tga��ʽ
 *@param image_p pimage,�������imageָ��
 *@param const char* filename, ������ļ���
 *@param uint8 alpha,�Ƿ񱣴�Ϊ��alphaͨ����ͼƬ
 *@param uint8 rle,�Ƿ񱣴�Ϊrleѹ����ʽ��ͼƬ
 *@return int,����0(����ʧ��)��1(���سɹ�)
 */
	NGE_API int image_save(image_p pimage,const char* filename,uint8 alpha,uint8 rle);

/**
 *�ͷ�һ��image
 *@param image_p pimage,���ͷŵ�imageָ��
 *@return void,�޷���
 */
	NGE_API void image_free(image_p pimage);

/**
 *cloneһ��image,����image_p����һ��pimage�����
 *@param image_p pimage,��clone��imageָ��
 *@return image_p,pimage�����
 */
	NGE_API image_p image_clone(image_p pimage);

/**
 *���������,ͼ���Ϊ��ɫ͸��
 *@param image_p pimage,�������imageָ��
 *@return void,�޷���
 */
	NGE_API void image_clear(image_p pimage);

/**
 *��Դimage_p src������image_p des.ע��˺���ͨ��ֻ������������ʹ��
 *ͨ��ֱ����DrawImage��screen��Ӳ������.
 *@param const image_p src,Դ�ڴ�ͼ
 *@param const image_p des,Ŀ���ڴ�ͼ
 *@param uint32 dx,Ŀ���ڴ�ͼ��x����
 *@param uint32 dy,Ŀ���ڴ�ͼ��y����
 *@return
 */
	NGE_API void image_to_image(const image_p src,const image_p des,uint32 dx,uint32 dy);

/**
 *��Դimage_p src��sx,sh,sw,sh������image_p des.ע��˺���ͨ��ֻ������������ʹ��
 *ͨ��ֱ����DrawImage��screen��Ӳ������.
 *@param const image_p src,Դ�ڴ�ͼ
 *@param const image_p des,Ŀ���ڴ�ͼ
 *@param uint32 sx,Դ�ڴ�ͼ��x����
 *@param uint32 sy,Դ�ڴ�ͼ��y����
 *@param uint32 sw,Դ�ڴ�ͼ�Ŀ�
 *@param uint32 sh,Դ�ڴ�ͼ�ĸ�
 *@param uint32 dx,Ŀ���ڴ�ͼ��x����
 *@param uint32 dy,Ŀ���ڴ�ͼ��y����
 *@return
 */
	NGE_API void image_to_image_ex(const image_p src,const image_p des,uint32 sx,uint32 sy,uint32 sw,uint32 sh,uint32 dx,uint32 dy);

/**
 *��Դimage_p src������image_p des ��alpha���.ע��˺���ͨ��ֻ������������ʹ��
 *ͨ��ֱ����DrawImage��screen��Ӳ������.
 *@param const image_p src,Դ�ڴ�ͼ
 *@param const image_p des,Ŀ���ڴ�ͼ
 *@param uint32 dx,Ŀ���ڴ�ͼ��x����
 *@param uint32 dy,Ŀ���ڴ�ͼ��y����
 *@param int alpha,alpha���ֵ,0-255(͸��->��͸��),����128���ǰ�͸��
 *@return
 */
	NGE_API void image_to_image_alpha(const image_p src,const image_p des,uint32 dx,uint32 dy,int alpha);

/**
 *��Դimage_p src��sx,sh,sw,sh������image_p des.ע��˺���ͨ��ֻ������������ʹ��
 *ͨ��ֱ����DrawImage��screen��Ӳ������.
 *@param const image_p src,Դ�ڴ�ͼ
 *@param const image_p des,Ŀ���ڴ�ͼ
 *@param uint32 sx,Դ�ڴ�ͼ��x����
 *@param uint32 sy,Դ�ڴ�ͼ��y����
 *@param uint32 sw,Դ�ڴ�ͼ�Ŀ�
 *@param uint32 sh,Դ�ڴ�ͼ�ĸ�
 *@param uint32 dx,Ŀ���ڴ�ͼ��x����
 *@param uint32 dy,Ŀ���ڴ�ͼ��y����
 *@param int alpha,alpha���ֵ,0-255(͸��->��͸��),����128���ǰ�͸��
 *@return
 */
	NGE_API void image_to_image_alpha_ex(const image_p src,const image_p des,uint32 sx,uint32 sy,uint32 sw,uint32 sh,uint32 dx,uint32 dy,int alpha);

/**
 *��ԭʼλͼ��ʽ���ݿ�����image,���ǵ�Ч������,ֻ֧��ͬ��displaymode,
 *ע��˴�δ���ж�,������Ҫ��֤data������ȷ��
 *@param void* data,λͼ����
 *@param image_p ,imageָ��,Ŀ��image
 *@param int x,������image�ϵ�dxλ��
 *@param int y,������image�ϵ�dyλ��
 *@param int w,data��w
 *@param int h,data��h
 *@return void,�޷���
 */
	NGE_API void rawdata_to_image(void* data,const image_p des,uint32 x,uint32 y,uint32 w,uint32 h);

/**
 * ��ͼ����ˮƽ��ת��ͼ������x����
 *@param image_p pimage,����תͼ��
 *@return int,�ɹ�1,ʧ��0
 */
	NGE_API int image_fliph(image_p pimage);

/**
 * ��ͼ������ֱ��ת����ת��x��Գ�
 *@param image_p pimage,����תͼ��
 *@return int,�ɹ�1,ʧ��0
 */
	NGE_API int image_flipv(image_p pimage);

//���º���Ϊ�ڲ�ʹ��
int GET_PSM_COLOR_MODE(int dtype);
int roundpower2(int width);

#ifdef NGE_PSP
void swizzle_swap(image_p pimage);
void unswizzle_swap(image_p pimage);
#else
#define swizzle_swap(p)
#define unswizzle_swap(p)
#endif

#define CHECK_AND_UNSWIZZLE(img)				\
	if(img->swizzle ==1) {						\
		unswizzle_swap(img);					\
	}

#define CHECK_AND_SWIZZLE(img)					\
	if(img->swizzle ==1) {						\
		swizzle_swap(img);						\
	}

#define CHECK_AND_UNSWIZZLE_ALL(src, des)		\
	CHECK_AND_UNSWIZZLE(src);					\
	CHECK_AND_UNSWIZZLE(des)

#ifdef __cplusplus
}
#endif

#endif /* _NGE_IMAGE_H */
