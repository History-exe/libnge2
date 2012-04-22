/**
 * @file  nge_package.h
 * @author Kun Wang <ifreedom.cn@gmail.com>
 * @date 2012/03/18 07:08:31
 *
 *  Copyright  2012  Kun Wang <ifreedom.cn@gmail.com>
 *
 */

#ifndef _NGE_PACKAGE_H
#define _NGE_PACKAGE_H

#include "nge_common.h"
#include "nge_ref_handle.h"
#include "nge_io_file.h"

typedef struct ngePackage ngePackage;

#ifdef __cplusplus
extern "C" {
#endif

/**
 *�������ļ�
 *@param const char*,�ļ���
 *@param int, һЩѡ���ѡ��
 *@return ngePackage*, ���ذ��ļ������ʧ�ܷ���NULL
 */
	NGE_API ngePackage* ngeLoadPackage(const char* fname, int option);
	NGE_API ngeRefHandle ngeCreatePackageHandle(ngePackage* pkg);

	NGE_API void ngeClosePackage(ngePackage* pkg);

/**
 *�򿪰����ļ�
 *@param ngePackage*, �����
 *@param const char*,�ļ���
 *@param int,�򿪱�־(IO_RDONLY,IO_WRONLY,IO_APPEND��һ��)
 *@return int,�ļ����,��д���ô��ļ�������в���
 */
	NGE_API int ngeOpenInPackage(ngePackage* pkg, const char* fname, int flag);

#ifdef __cplusplus
}
#endif

#endif /* _NGE_PACKAGE_H */
