#ifndef NGE_RBTREE_H_
#define NGE_RBTREE_H_
// red-black tree

#include "nge_common.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//////////////////////
// supplied by user //
//////////////////////

typedef int KeyType;            // type of key

typedef struct {                // value related to key
    int stuff;
	void* node;
} ValType;

// how to compare keys
#define compLT(a,b) (a < b)
#define compEQ(a,b) (a == b)

/////////////////////////////////////
// implementation independent code //
/////////////////////////////////////

typedef enum {
		RBT_STATUS_OK, /** �ɹ�*/
		RBT_STATUS_MEM_EXHAUSTED,/** �ռ䲻��*/
		RBT_STATUS_DUPLICATE_KEY,/** �����ظ�*/
		RBT_STATUS_KEY_NOT_FOUND/** �����޷��ҵ�*/
} RbtStatus;

typedef enum { BLACK, RED } nodeColor;

typedef struct NodeTag {
    struct NodeTag *left;       // left child
    struct NodeTag *right;      // right child
    struct NodeTag *parent;     // parent
    nodeColor color;            // node color (BLACK, RED)
    KeyType key;                // key used for searching
    ValType val;                // data related to key
} NodeType;

typedef struct{
	NodeType* root;
	NodeType  sentinel;
}rbtree_t,*rbtree_p;

typedef void (*travelcall)(rbtree_p rb,NodeType *);

#ifdef __cplusplus
extern "C" {
#endif

/**
 *��һ�ú�����в���һ��key, val��
 *@param[IN, OUT] rb,Ҫ����ĺ����
 *@param[IN] key,��ʶֵ������
 *@param[IN] val,Ҫ�����ֵ
 *@return RbtStatus,�����ɹ���ΪRBT_STATUS_OK��������ο�RbtStatus����
 */
	NGE_API RbtStatus rbtInsert(rbtree_p rb,KeyType key, ValType val);

/**
 *��һ�ú������ɾ��һ���ڵ�
 *@param[IN, OUT] rb,Ҫɾ���ĺ����
 *@param[IN] z,��ɾ���ڵ�
 *@return RbtStatus,�����ɹ���ΪRBT_STATUS_OK��������ο�RbtStatus����
 */
	NGE_API RbtStatus rbtErase(rbtree_p rb,NodeType * z);

/**
 *��һ�ú�������ҵ�һ��������Ӧ�Ľڵ�
 *@param[IN] rb,Ҫ�����ĺ����
 *@param[IN] key,����������
 *@return NodeType*,�������Ľڵ�,������ʧ��,����NULL
 */
	NGE_API NodeType* rbtFind(rbtree_p rb,KeyType key);

/**
 *��һ�ú������ĳ���ڵ㿪ʼ�����������
 *@param[IN] rb,Ҫ�����ĺ����
 *@param[IN] p,Ҫ��ʼ�Ľڵ�
 *@param[IN] callback,�ص�����,��ÿһ���ڵ���е���
 */
	NGE_API void rbtInorder(rbtree_p rb,NodeType *p, travelcall callback);

/**
 *��һ�ú������ɾ��ĳ���ڵ����������
 *@param[IN] rb,Ҫɾ���ĺ����
 *@param[IN] z,��ʼ�Ľڵ�
 */
	NGE_API void rbtDelete(rbtree_p rb,NodeType *p);

/**
 *����һ�ú����
 *@return rbtree_p,�����ĺ����
 */
	NGE_API rbtree_p createTree();

/**
 *����һ�ú����
 *@param[IN] rb,Ҫ���ٵĺ����
*/
	NGE_API void destoryTree(rbtree_p rb);
#ifdef __cplusplus
}
#endif

#endif
