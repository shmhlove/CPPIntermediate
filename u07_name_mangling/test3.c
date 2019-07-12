/* 빌드 하는 법
	g++ test3.c square.c
    gcc test3.c square.c
	cl test3.c square.c /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <stdio.h>
#include "square.h"

int main()
{
    printf("%d\n", square(3));
}