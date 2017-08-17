#include<iostream>
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

int main() {
	//showTypeSize();
	//enumDemo();
	showExternVarable();
	return 0;
}