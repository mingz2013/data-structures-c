/*
 *
 *双向链表
 *
 *
 * */


/* 线性表的双向链表存储结构 */
typedef struct DulNode
{
	ElemType data;
	struct DulNode *prior; /* 直接前驱指针 */
	struct DulNode *next; /* 直接后继指针 */
}DulNode, *DuLinkList;



