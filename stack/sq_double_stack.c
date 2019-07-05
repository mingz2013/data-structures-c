/*
 *from 《大话数据结构》
 *两栈共享空间结构
 *
 * */



/* 两栈共享空间结构 */
typedef struct
{
	SElemType data[MAXSIZE];
	int top1; /* 栈1栈顶指针 */
	int top2; /* 栈2栈顶指针 */
}SqDoubleStack;

/* 插入元素e为新的栈顶元素 */
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
	if (S->top1 + 1 == S->top2) /* 栈已满，不能再push新元素了 */
		return ERROR;
	if (stackNumber == 1) /* 栈1有元素进栈 */
		S->data[++S->top1] = e; /* 若栈1 则先top1+1后给数组元素赋值 */
	else if (stackNumber == 2)/* 栈2有元素进栈 */
		S->data[--S->top2] = e; /* 若栈2 则先top2-1 后给数组元素赋值 */
	return OK;
}


/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S->top1 == -1)
			return ERROR; /* 说明栈1已经是空栈，溢出 */
		*e = S->data[S->top1--]; /* 将栈1的栈顶元素出栈 */

	}
	else if (stackNumber == 2)
	{
		if (S->top2 == MAXSIZE)
			return ERROR; /* 说明栈2已经是空栈，溢出 */
		*e = S->data[S->top2++]; /* 将栈顶元素出栈 */
	}
	return OK;
}


