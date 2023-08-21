#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define OVERFLOW -2
#define ERROR 0
#define OK 1
typedef int Status; 
typedef int SElemType;//��ʱ��int��ʾSElemType,��Ҫ�仯ʱ��typedef���ӷ��� 

typedef struct//�ýṹ�����˳��ջ�����еĻ������� 
{
	SElemType *base;//��ָ���ʾջ����ջβԪ�ص�λ�ã�
	SElemType *top;//��˳��ջ�з�����ָ���ָ�����ջ��Ԫ���� 
	int stacksize;//����ջ���ܴ�С 
}SqStack;//˳��ջ���� 

//˳��ջ�ĳ�ʼ�� 
Status InitStack(SqStack &S)
{
	S.base = new SElemType[MAXSIZE];//����һ�ι�MAXSIZE����ÿ����SElemType��С
									//�Ŀռ䣬������һ���ռ�ĵ�ַ����S.base 
	//S.base = (SElemType*)malloc(MAXSIZE*sizeod(SElemType));//C���� 
	if(!S.base)exit(OVERFLOW);//����ʧ�ܣ������Ƿ���ռ���󣬳����ڴ棩 
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK; 
}	

//�ж�ջ�Ƿ�Ϊ��ջ
Status StackEmpty(SqStack S){
	if(S.base == S.top)//���ջ��ָ���ջβָ��ָ��ͬһ������ջΪ�� 
		return true;
	else
		return false;
} 

//��ջ�ڵ�Ԫ����,������ 
int StackLength(SqStack S){
	return S.top - S.base;//ֱ����ջ��ָ���ջβָ�� 
} 

//���˳��ջ
Status ClearStack(SqStack &S){
	if(S.base)
		S.top = S.base;//ջ��ָ��ָ��ջβ���м����ݱ��Զ��ͷţ� 
} 

//����˳��ջ
Status DestroyStack(SqStack &S){
	if(S.base){
		delete S.base;
		S.stacksize = 0;
		S.base = NULL;
		S.top = NULL;
	}
} 

//˳��ջ����ջ
Status Push(SqStack &S,SElemType e){
	if(S.top - S.base == S.stacksize)
		return ERROR;//ջ������0
	*S.top++ = e;//�Ƚ�e����*S.top�ٶ�S.top++ʹջ��ָ��ָ����һλ 
	return OK;
}

//˳��ջ�ĳ�ջ,������ջ��Ԫ�ظ�ֵ��e 
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
	//��ջ1��2��3��4��5
	for(int i = 1;i <= 5;i++){
		Push(S,i);
	}
	//һ��һ����ջ,��ջ3�� 
	for(int i = 1;i <= 3;i++){
		int e = 0;
		Pop(S,e);
		printf("%d\n",e);
	}
	//���˳��ջ
	ClearStack(S);
	//�ж��Ƿ���ճɹ�
	printf("%d",StackEmpty(S)); 
	
	return 0;
}

