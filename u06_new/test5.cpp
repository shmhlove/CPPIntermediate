/* 빌드 하는 법
	g++ test1.cpp
	cl test2.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(10, 0);
    
    // 메모리를 제거하지 않기 때문에(오버헤드가 크다)
    // 소멸자의 명시적 호출이 필요할 수 있다.
    // resize호출 시 생성자, 소멸자만 호출된다.
    v.resize(7);
    
    printf("size : %d\n", v.size()); // 7
    printf("capacity : %d\n", v.capacity()); // 10
}