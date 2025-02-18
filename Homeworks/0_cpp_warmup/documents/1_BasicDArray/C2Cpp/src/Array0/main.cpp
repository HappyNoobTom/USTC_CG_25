#include <cstdio>
#include <cstdlib>

// 全局变量声明
int n;         // 数组当前大小
double *pData; // 指向动态分配数组内存的指针

//double pData[100];

// 函数声明
/**
 * @brief 设置动态数组的大小
 * @param size 要创建的数组大小
 * @return 成功返回1，失败返回0
 */
int SetArraySize( int size );

/**
 * @brief 释放动态数组内存
 * @return 总是返回1
 */
int FreeArray();

/**
 * @brief 设置指定位置的元素值
 * @param k 要设置的位置索引
 * @param value 要设置的值
 * @return 成功返回1，失败返回0
 */
int SetValue( int k, double value );

/**
 * @brief 打印数组内容
 * @return 成功返回1，失败返回0
 */
int PrintArray();

int main()
{
	SetArraySize( 3 );
	SetValue( 0, 1.0 );
	SetValue( 1, 2.0 );
	SetValue( 2, 3.0 );

	PrintArray();

	FreeArray();

	return 0;
}

/**
 * @brief 初始化动态数组（分配内存）
 * @param size 数组大小
 * @return 成功返回1，内存不足返回0
 */
int SetArraySize( int size )
{
	n = size;
	pData = (double*)malloc( size * sizeof(double) ); // 分配内存空间
	if( pData == NULL ) // 检查内存分配是否成功
	{
		printf("内存不足!\n");
		return 0;
	}

	return 1;
}

/**
 * @brief 释放动态数组内存
 * @return 总是返回1
 */
int FreeArray()
{
	if( pData != NULL ) // 确保指针有效
	{
		free( pData );  // 释放内存
		pData = NULL;   // 指针置空防止野指针
	}

	return 1;
}

/**
 * @brief 设置数组元素值
 * @param k 要设置的索引位置
 * @param value 要设置的值
 * @return 成功返回1，无效索引或空数组返回0
 */
int SetValue( int k, double value )
{
	if( pData == NULL ) // 检查数组是否初始化
		return 0;

	if( k<0 || k>=n )   // 检查索引有效性
		return 0;

	pData[ k ] = value; // 设置数组元素值
	return 1;
}

/**
 * @brief 打印数组所有元素
 * @return 成功返回1，空数组或未初始化返回0
 */
int	PrintArray()
{
	if(n==0)            // 检查数组大小
		return 0;

	if( pData == NULL ) // 检查数组是否初始化
		return 0;

	for( int i=0; i<n; i++) 
	{
		printf("%lf \n", pData[i] ); // 打印每个元素
	}

	return 1;
}
