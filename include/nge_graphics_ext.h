#ifndef NGE_GRAPHICS_EXT_H
#define NGE_GRAPHICS_EXT_H
#include "nge_graphics.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * ���� src ͼ��ĻҶȰ汾
 *
 * @param src Դͼ��
 * @param gray �Ҷ� 0 �� 100, 0 ΪԴͼ��, 100 Ϊ����ɫͼ��
 */
image_p create_gray_image(image_p src, int gray);


/**
 * ���� src ͼ������ȣ����ͶȰ汾
 *
 * @param src Դͼ��
 * @param saturation ���϶� -100(�Ҷ�ͼ��) �� 100(�߲�ɫ��ͼ��)
 * @param brightness ���� -100(ȫ��) �� 100(ȫ��)
 */
image_p create_saturation_brightness_image(image_p src, int saturation, int brightness);

/**
 * ���� src ͼ���������ɫģʽͼƬ
 * @param src Դͼ��
 * @param dtype ��ɫģʽ,DISPLAY_PIXEL_FORMAT_XXXX��һ��
 * @return image_p ���ɵ�ͼƬ
 */
image_p image_conv(image_p src, int dtype);

/**
 * ���� src ͼ�������ͼ���ṩ0-4���������˾�
 * @param src Դͼ��
 * @param w ���ŵĿ�
 * @param h ���ŵĸ�
 * @param mode ����ģʽ0-4
 * @return image_p ����ͼ
 */
image_p image_scale(image_p src, int w, int h,int mode);

#ifdef __cplusplus
}
#endif

#endif
