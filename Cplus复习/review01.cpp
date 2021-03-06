#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<cstdlib>

#include<random>
#include<string>

#include<sstream> //可以判断字符串是否为数字
#include<cctype> //可以判断单个字符是否是数字，字母等；
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

void showRandom1() {
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(1, 10);

	for (int n = 0; n < 20; ++n)
		//Use dis to transform the random unsigned int generated by gen into an int in [1, 6]
		std::cout << dis(gen) << ' ';
	std::cout << '\n';
}

void showArray() {
	int arr[6] = { 0,1,2,3,4,5 };
	int *p;
	p = arr;
	cout << *(p + 1) << endl;
	for (int i = 0; i < 6; i++) {
		cout << *(p + i) << endl;
	}
}

/*一维数组测试*/
void changeArray(int arr[5]) {
	arr[0] = 10000;
}

void showArray(int arr[5]) {

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
}
/*与：void showArray(int arr[], int length) 为重复定义*/
//void showArray(int *p, int length) {
//	for (int i = 0; i < length; i++)
//	{
//		cout << *(p + i) << endl;
//	}
//}
/*推荐这种传参方式*/
void showArray(int arr[], int length) {
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << endl;
	}
}

/*返回数组：*/
int * getArray() {
	// 违背函数可重入性的理念，不建议这么写
	static int arr[] = { 1,2,3,4,5 };//函数内，局部变量无法返回地址给外部变量，只能static
	return arr;
}

void showCharArray() {
	char str1[] = { 'a','b','c' };
	char str2[] = { 'a','b','c','\0' };
	cout << strlen(str1) << setw(3) << strlen(str2) << setw(2) << sizeof(str1) / sizeof(str1[0]) << endl;
}

void showString() {
	char arrStr[] = "abc";
	string str1 = string(arrStr);
	string str2 = "abc";

	cout << "rrStr[] = \"abc\" len:"<<strlen(arrStr) << endl;
	cout << "string(arrStr) len is " << str1.length() << endl;
	cout << "length of str2 is " << str2.length() << endl;

}

void showString1() {
	string str = "abcdefg";
	str.assign( "dcba",0,2);//dcBa前[0,2)个元素赋值给str
	string str1 = "bcd";
	cout << ("abc" < "abc") << endl;
	cout << (str < str1) << endl;
	cout << str << endl;
	cout << str.find("cd") << endl;
	cout << str.substr(0, 2) << endl; //substr[a, b)
	cout << str.substr(0, string::npos)<<endl;

	string *str2 = new string("new string");
	cout << *str2 << endl;

	string &str3 = *str2;
	cout << str3 << endl;

	

}

void showTypeString() {
	cout << isdigit('A') << endl;
	cout << isalpha('A') << endl;

	cout << isalnum('a');
	
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
	//showRandom(2, 6);	//随机数
	//showRandom1();
	//showArray();

	//int arr[] = { 1,2,3,4,5 };
	///*changeArray(arr);
	//showArray(arr);*/

	//showArray(&arr[0], 5);
	//showArray(arr, 5);

	//int *arr2 = getArray();
	//showArray(arr2, 5);
	//showCharArray();

	/*string类*/
	//showString1();
	showTypeString();
	



	return 0;
}