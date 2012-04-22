#ifndef __NGE_CHARSET__H
#define __NGE_CHARSET__H

#include "nge_common.h"

#define NGE_RET_BUFFER_SMALL -1

#ifdef __cplusplus
extern "C"{
#endif

/*���º���Ϊ�ڲ�ʹ��,ͨ���������*/

/**
 *��GBK������ַ�ת��Ϊunicode(ucs-2)�ַ�
 *ע��out buffer��ҪԤ�ȷ����㹻��С.
 *@param const uint8* in,�����ַ���
 *@param uint8* out,ת����unicode�ַ�����������,ע����ҪԤ�ȷ����㹻��С
 *@param int len,in�ַ������������ֽڼǣ���strlen����ĸ���
 *@param int n,out buffer�Ĵ�С�����ֽڼ�
 *@return int,ת������ַ���������uint16�����ƣ�0�븺����Ϊerror
 */
	NGE_API int nge_charset_gbk_to_ucs2(const uint8* in, uint16* out, int len, int n);

/**
 *��utf8������ַ�ת��Ϊunicode(ucs-2)�ַ�
 *ע��out buffer��ҪԤ�ȷ����㹻��С.
 *@param const uint8* in,�����ַ���
 *@param uint8* out,ת����unicode�ַ�����������,ע����ҪԤ�ȷ����㹻��С
 *@param int len,in�ַ������������ֽڼǣ���strlen����ĸ���
 *@param int n,out buffer�Ĵ�С�����ֽڼ�
 *@return int,ת������ַ���������uint16�����ƣ�0�븺����Ϊerror
 */
	NGE_API int nge_charset_utf8_to_ucs2(const uint8* in, uint16* out, int len, int n);

/**
 *��utf8������ַ�ת��Ϊgbk�ַ�
 *ע��out buffer��ҪԤ�ȷ����㹻��С.
 *@param const uint8* in,�����ַ���
 *@param uint8* out,ת����gbk�ַ�����������,ע����ҪԤ�ȷ����㹻��С
 *@param int len,in�ַ������������ֽڼǣ���strlen����ĸ���
 *@param int n,out buffer�Ĵ�С�����ֽڼ�
 *@return int,ת������ַ����������ֽڼƣ�0�븺����Ϊerror
 */
	NGE_API int nge_charsets_utf8_to_gbk(const uint8* in, uint8* out, int len, int n);

/**
 *��gbk������ַ�ת��Ϊutf8�ַ�
 *ע��out buffer��ҪԤ�ȷ����㹻��С.
 *@param const uint8* in,�����ַ���
 *@param uint8* out,ת����utf8�ַ�����������,ע����ҪԤ�ȷ����㹻��С
 *@param int len,in�ַ������������ֽڼǣ���strlen����ĸ���
 *@param int n,out buffer�Ĵ�С�����ֽڼ�
 *@return int,ת������ַ����������ֽڼƣ�0�븺����Ϊerror
 */
	NGE_API int nge_charsets_gbk_to_utf8(const uint8* in, uint8* out, int len, int n);

#ifdef __cplusplus
}
#endif

#endif
