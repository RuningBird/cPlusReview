#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

// 显示本机各个类型的大小
void showTypeSize() {
	cout << "Size of char : " << sizeof(char) << endl;
	cout << "Size of int : " << sizeof(int) << endl;
	cout << "Size of short int : " << sizeof(short int) << endl;
	cout << "Size of long int : " << sizeof(long int) << endl;
	cout << "Size of float : " << sizeof(float) << endl;
	cout << "Size of double : " << sizeof(double) << endl;
	cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
}

/*enum 复习*/
void enumDemo() {
	enum Sexy
	{
		male,
		female
	};
	Sexy s = male;
	switch (s)
	{
	case male:
		cout << "男" << endl;
		break;
	case female:
		cout << "女" << endl;
		break;
	default:
		break;
	}
	cout << s << endl;
}

/*变量声明/同函数声明*/
extern int ext = 5;
void changeExternVarable() {
	int ext = 4;
	ext++;
}
void showExternVarable() {
	changeExternVarable();
	cout << ext << endl;
}

/*常量和字符常量*/
/*整型常量*/
void showConst() {
	int octonary = 077;
	int decimal = 10;
	int hexadecimal = 0xFF;

	cout << octonary << endl << decimal << endl << hexadecimal << endl;

}
void area() {//常量
	const double WIDTH = 10;
	const double HIGHT = 10;
	double area = WIDTH * HIGHT;

	cout << "area = " << area << endl;
}

/*c plus 修饰符：signed unsigned long int*/
void showModifier() {
	unsigned x = 5;
	short x1 = 5;
	cout << sizeof(x) << endl;
	cout << sizeof(x1) << endl;

}
/*static 关键字详解： static int test =cnt 与 static int test; test = cnt是不等价的*/
int t1 = 0;
void f1() {
	static int test = t1;//静态变量只初始化一次，第二次调用不执行；
	cout << test << endl;
	t1++;
}
/*static测试1:*/
void showStaticF1() {
	f1();
	f1();
	f1();
	cout << "-------------------------------" << endl;
}

int t2 = 0;
void f2() {
	static int test;//作用域仅限于该函数，但是该变量会持续到程序结束
	test = t2;//此处是复制，上一行已初始化
	cout << test << endl;
	t2++;
}
/*static测试2：*/
void showStaticF2() {
	f2();
	f2();
	f2();
}

/*lambda表达式*/
void showLambda() {
	auto addFun = [](int a, int b) {return a + b;};
	cout << addFun(2, 3) << endl;
}
/*cmath库*/
void showCmath() {
	cout << "floor(2.5) is " << floor(2.5) << endl;
	cout << "floor(-2.5) is " << floor(-2.5) << endl;
	cout << "fabs(2.5) is " << fabs(2.5) << endl;
	cout << "fabs(-2.5) is " << fabs(-2.5) << endl;
	cout << "hypot(2, 2) is " << hypot(2, 2) << endl;//平方根
	cout << "pow(2, 3) is " << pow(2, 3) << endl;
}

/*随机数*/
void showRandom() {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++) {
		cout << rand() << endl;
	}
}
/*[a,b]之间，随机数*/
void showRandom(int a, int b) {
	for (int i = 0; i < 70; i++) {
		int res = a + rand() % (b - a + 1);
		cout << res << endl;
	}
}

int main() {
	//showTypeSize();//本机各个类型大小
	//enumDemo();//枚举
	//showExternVarable();//外部变量
	//area();//const
	//showConst(); //变量
	//showModifier(); //修饰符
	//showStaticF1();//静态变量示例
	//showStaticF2();

	//showLambda();//lambda表达式
	//showCmath();//数学相关计算

	//showRandom();
	showRandom(2, 6);	//随机数




	return 0;
}