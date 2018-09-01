
#if 0
// []
int BinarySearch(int* array, int size, int data)
{
	int left = 0;
	int right = size-1;
	int mid = 0;

	while(left <= right)
	{
		mid = left + ((right - left)>>1);

		if(data == array[mid])
			return mid;
		else if(data < array[mid])
			right = mid-1;
		else
			left = mid+1;
	}

	return -1;

}

int main()
{
	return 0;
}
#endif

// [）f(n) = 3---》O(1)
int BinarySearch(int* array, int size, int data)
{
	int left = 0;
	int right = size;
	int mid = 0;

	while(left < right)
	{
		mid = left + ((right - left)>>1);

		if(data == array[mid])
			return mid;
		else if(data < array[mid])
			right = mid;
		else
			left = mid+1;
	}

	return -1;

}

/*1+2+3+……+n*/
#include <stdio.h>
int Sum(int N)
{
	if(1 == N)
		return 1;

	return Sum(N-1)+N;
}

int Fac(int N)
{
	if(0 == N)
		return 1;

	return Fac(N-1)*N;
}

#if 0

// 什么是全角 半角
int Fib(int N)
{
	return (N < 3)? 1 : Fib(N-1) + Fib(N-2);
}

// O(N)---递归的

// O(N)---->O(1)
#endif

#if 0
// 时间复杂度：O(N)
// 空间复杂度：O(N)
// 尾递归：O(1)
long long Fib(long long first, long long second, int N)
{
	if(N < 3)
		return 1;

	if(N == 3)
		return first + second;

	return Fib(second, first+second, N - 1);
}
#endif


// 时间复杂的：O(N)
// 空间复杂度：O(1)
long long Fib(int N)
{
	long long first = 1;
	long long second = 1;
	long long ret = 0;
	int i = 3;

	for(; i <= N; ++i)
	{
		ret = first + second;
		first = second;
		second = ret;
	}

	return ret;

}

int main()
{
	//printf("%d\n", Sum(5));
	//printf("%d\n", Fac(5));
	printf("%d\n", Fib(10));
	//printf("%d\n", Fib(1,1,10));
	return 0;
}