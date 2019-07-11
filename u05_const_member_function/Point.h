/* 빌드 하는 법
	g++ test1.cpp
	cl test1.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0);
	void set(int a, int b);
	void print() const;
};