#include <cstdio>
#include <cstdlib>

// 动态数组结构体
typedef struct
{
	int n;         // 当前数组元素个数
	double *pData; // 指向动态数组内存的指针
} DArray;

/************************ 函数声明 ************************/
// 功能：初始化数组      输入：数组引用  输出：成功返回1
int InitArray(DArray &a);
// 功能：设置数组大小    输入：数组引用, 大小  输出：成功返回1，失败返回0
int SetArraySize(DArray &a, int size);
// 功能：释放数组内存    输入：数组引用  输出：成功返回1
int FreeArray(DArray &a);
// 功能：设置元素值     输入：数组引用, 位置, 值  输出：成功返回1，失败返回0
int SetValue(DArray &a, int k, double value);
// 功能：打印数组内容   输入：数组引用  输出：成功返回1，失败返回0
int PrintArray(DArray &a);

int main()
{
	DArray pa;

	InitArray( pa );
	
	SetArraySize( pa, 3 );
	SetValue( pa, 0, 1.0 );
	SetValue( pa, 1, 2.0 );
	SetValue( pa, 2, 3.0 );

	PrintArray(pa);

	FreeArray(pa);

	return 0;
}

/************************ 函数实现 ************************/
int InitArray(DArray &a)
{
	// 初始化数组参数
	a.n = 0;          // 元素个数归零
	a.pData = NULL;   // 指针置为空
	return 1;         // 总是返回成功
}

int SetArraySize(DArray &a, int size)
{
	// 设置数组容量并分配内存
	a.n = size;
	a.pData = (double*)malloc(size * sizeof(double));
	if(a.pData == NULL) {  // 内存分配失败处理
		printf("内存不足!\n");
		return 0;
	}
	return 1;
}

int FreeArray(DArray &a)
{
	// 安全释放动态内存
	if(a.pData != NULL) {
		free(a.pData);   // 释放内存
		a.pData = NULL;  // 指针置空防止野指针
	}
	return 1;
}

int SetValue(DArray &a, int k, double value)
{
	// 参数有效性检查
	if(a.pData == NULL) return 0;          // 数组未初始化
	if(k<0 || k>=a.n) return 0;           // 越界检查
	
	a.pData[k] = value;  // 设置指定位置的值
	return 1;
}

int PrintArray(DArray &a)
{
	// 打印前检查有效性
	if(a.n == 0) return 0;               // 空数组检查
	if(a.pData == NULL) return 0;        // 未初始化检查
	
	for(int i=0; i<a.n; i++) {
		printf("%lf \n", a.pData[i]);    // 逐元素打印
	}
	return 1;
}
