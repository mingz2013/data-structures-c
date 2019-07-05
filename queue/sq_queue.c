/*
 *
 *from 《大话数据结构》
 * 循环队列
 * */



typedef int QElemType; /* QElemType类型根据实际情况而定，这里假设为int */

/* 循环队列的顺序存储结构 */
{
	QElemType data[MAXSIZE];
	int front; /* 头指针 */
	int rear; /* 尾指针，若队列不变，指向队列尾元素的下一个位置 */
}SqQueue;


/* 初始化一个空队列Q */
Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

/* 返回Q的元素个数，也就是队列的当前长度 */
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}


/* 若队列未满，则插入元素e为Q新的队列元素 */
Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) /* 队列满的判断 */
		return ERROR;
	Q->data[Q->rear] = e; /* 将元素e赋值给队尾 */
	Q->rear = (Q->rear + 1) % MAXSIZE; /* read指针向后移一位置, 若到最后则转到数组头部 */
	return OK;
}

/* 若队列不空，则删除Q中队头元素，用e返回其值 */
Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear) /* 队列空的判断 */
		return ERROR;
	*e = Q->data[Q->front]; /* front指针向后移一位置，若到最后则转到数组头部 */
	return OK;
	
}


