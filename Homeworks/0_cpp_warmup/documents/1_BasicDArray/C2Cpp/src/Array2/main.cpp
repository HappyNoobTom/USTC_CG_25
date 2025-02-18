#include <cstdio>
#include <cstdlib>

// 动态数组结构体定义
typedef struct DArray 
{
	int n;          // 数组元素个数
	double *pData;  // 指向动态数组内存的指针

	// 成员函数声明
	int		InitArray( );          // 初始化数组
	int		SetArraySize( int size ); // 设置数组大小
	int		FreeArray( );          // 释放数组内存
	int		SetValue( int k, double value ); // 设置元素值
	int		PrintArray(  );         // 打印数组内容
} DArray;


//double pData[100];


int main()
{
	DArray pa;  // 创建动态数组实例

	pa.InitArray();      // 初始化数组
	pa.SetArraySize(3);  // 设置数组大小为3
	pa.SetValue(0, 1.0); // 设置第0个元素为1.0
	pa.SetValue(1, 2.0); // 设置第1个元素为2.0
	pa.SetValue(2, 3.0); // 设置第2个元素为3.0

	pa.PrintArray();     // 打印数组内容
	pa.FreeArray();      // 释放数组内存
	return 0;
}

// 初始化数组（构造函数）
// 输入：无
// 输出：总是返回1（成功）
int DArray::InitArray()
{
	n = 0;
	pData = NULL;
	return 1;
}

// 设置数组大小并分配内存
// 输入：size - 要分配的数组大小
// 输出：成功返回1，内存不足返回0
int DArray::SetArraySize(int size)
{
	n = size;
	pData = (double*)malloc(size * sizeof(double));
	if(pData == NULL) {
		printf("no enough memory!\n");
		return 0;
	}
	return 1;
}

// 释放数组内存
// 输入：无
// 输出：总是返回1（成功）
int DArray::FreeArray()
{
	if(pData != NULL) {
		free(pData);
		pData = NULL;
	}
	return 1;
}

// 设置指定位置的元素值
// 输入：k - 元素位置（0-based），value - 要设置的值
// 输出：成功返回1，无效位置或未初始化返回0
int DArray::SetValue(int k, double value)
{
	if(pData == NULL)
		return 0;

	if(k < 0 || k >= n)
		return 0;

	pData[k] = value;
	return 1;
}

// 打印数组内容
// 输入：无
// 输出：成功返回1，空数组或未初始化返回0
int DArray::PrintArray()
{
	if(n == 0)
		return 0;

	if(pData == NULL)
		return 0;

	for(int i = 0; i < n; i++) {
		printf("%lf \n", pData[i]);
	}
	return 1;
}
