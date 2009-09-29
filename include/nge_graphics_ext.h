#ifndef NGE_GRAPHICS_EXT_H
#define NGE_GRAPHICS_EXT_H

#include "nge_define.h"

#include "nge_debug_log.h"

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

#ifdef __cplusplus
}
#endif

#endif
