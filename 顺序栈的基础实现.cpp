#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define OVERFLOW -2
#define ERROR 0
#define OK 1
typedef int Status; 
typedef int SElemType;//暂时用int表示SElemType,需要变化时用typedef更加方便 

typedef struct//用结构体归类顺序栈所具有的基本特征 
{
	SElemType *base;//用指针表示栈顶与栈尾元素的位置，
	SElemType *top;//在顺序栈中方便用指针减指针算出栈内元素数 
	int stacksize;//定义栈是总大小 
}SqStack;//顺序栈类型 

//顺序栈的初始化 
Status InitStack(SqStack &S)
{
	S.base = new SElemType[MAXSIZE];//开辟一段共MAXSIZE个且每个有SElemType大小
									//的空间，并将第一个空间的地址赋给S.base 
	//S.base = (SElemType*)malloc(MAXSIZE*sizeod(SElemType));//C语言 
	if(!S.base)exit(OVERFLOW);//分配失败（可能是分配空间过大，超出内存） 
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK; 
}	

//判断栈是否为空栈
Status StackEmpty(SqStack S){
	if(S.base == S.top)//如果栈顶指针和栈尾指针指向同一个，则栈为空 
		return true;
	else
		return false;
} 

//求栈内的元素数,并返回 
int StackLength(SqStack S){
	return S.top - S.base;//直接用栈顶指针减栈尾指针 
} 

//清空顺序栈
Status ClearStack(SqStack &S){
	if(S.base)
		S.top = S.base;//栈顶指针指向栈尾，中间内容被自动释放？ 
} 

//销毁顺序栈
Status DestroyStack(SqStack &S){
	if(S.base){
		delete S.base;
		S.stacksize = 0;
		S.base = NULL;
		S.top = NULL;
	}
} 

//顺序栈的入栈
Status Push(SqStack &S,SElemType e){
	if(S.top - S.base == S.stacksize)
		return ERROR;//栈满返回0
	*S.top++ = e;//先将e赋给*S.top再对S.top++使栈顶指针指向下一位 
	return OK;
}

//顺序栈的出栈,并将出栈的元素赋值给e 
Status Pop(SqStack &S,SElemType &e){
	if(S.top <= S.base)
		return ERROR;
	S.top--;
	e = *S.top;
	return OK;
} 

int main(){
	SqStack S;
	InitStack(S);
	//入栈1，2，3，4，5
	for(int i = 1;i <= 5;i++){
		Push(S,i);
	}
	//一个一个出栈,出栈3次 
	for(int i = 1;i <= 3;i++){
		int e = 0;
		Pop(S,e);
		printf("%d\n",e);
	}
	//清空顺序栈
	ClearStack(S);
	//判断是否清空成功
	printf("%d",StackEmpty(S)); 
	
	return 0;
}

