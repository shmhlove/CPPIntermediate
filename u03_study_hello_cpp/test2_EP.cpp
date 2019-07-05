// cl test2_EP.cpp /EP
// => 전체빌드X, 전처리만

#define MAX 10
#define SQUARE(a) ((a)*(a))

int main ()
{
    int arr[MAX] = { 0 };
    int n = SQUARE(3);
}