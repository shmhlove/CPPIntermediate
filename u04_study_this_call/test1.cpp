// cl test1.cpp /FAs => this1.asm
// g++ test1.cpp -S => this1.s

class Point
{
	int x = 0, y = 0;
public:
	void set(int a, int b)	// void set(Point* const this, int a, int b)
	{
		x = a;	// this->x = a;
		y = b;	// this->y = b;
	}
	static void foo(int a) // void foo(int a)
	{
		x = a;	// this->x = a; 변경해야하는데..  this 가 없다. error
	}
};

int main()
{
	Point p1;
	Point p2;
	
	Point::foo(10);
	
	// this call
	p1.set(10, 20);	// set(&p1, 10, 20)
					// push 20
					// push 10
					// mov ecx, &p1 rcx, &p1
					// call Point::set
}