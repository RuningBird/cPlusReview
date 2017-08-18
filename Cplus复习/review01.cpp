#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

// ��ʾ�����������͵Ĵ�С
void showTypeSize() {
	cout << "Size of char : " << sizeof(char) << endl;
	cout << "Size of int : " << sizeof(int) << endl;
	cout << "Size of short int : " << sizeof(short int) << endl;
	cout << "Size of long int : " << sizeof(long int) << endl;
	cout << "Size of float : " << sizeof(float) << endl;
	cout << "Size of double : " << sizeof(double) << endl;
	cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
}

/*enum ��ϰ*/
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
		cout << "��" << endl;
		break;
	case female:
		cout << "Ů" << endl;
		break;
	default:
		break;
	}
	cout << s << endl;
}

/*��������/ͬ��������*/
extern int ext = 5;
void changeExternVarable() {
	int ext = 4;
	ext++;
}
void showExternVarable() {
	changeExternVarable();
	cout << ext << endl;
}

/*�������ַ�����*/
/*���ͳ���*/
void showConst() {
	int octonary = 077;
	int decimal = 10;
	int hexadecimal = 0xFF;

	cout << octonary << endl << decimal << endl << hexadecimal << endl;

}
void area() {//����
	const double WIDTH = 10;
	const double HIGHT = 10;
	double area = WIDTH * HIGHT;

	cout << "area = " << area << endl;
}

/*c plus ���η���signed unsigned long int*/
void showModifier() {
	unsigned x = 5;
	short x1 = 5;
	cout << sizeof(x) << endl;
	cout << sizeof(x1) << endl;

}
/*static �ؼ�����⣺ static int test =cnt �� static int test; test = cnt�ǲ��ȼ۵�*/
int t1 = 0;
void f1() {
	static int test = t1;//��̬����ֻ��ʼ��һ�Σ��ڶ��ε��ò�ִ�У�
	cout << test << endl;
	t1++;
}
/*static����1:*/
void showStaticF1() {
	f1();
	f1();
	f1();
	cout << "-------------------------------" << endl;
}

int t2 = 0;
void f2() {
	static int test;//����������ڸú��������Ǹñ�����������������
	test = t2;//�˴��Ǹ��ƣ���һ���ѳ�ʼ��
	cout << test << endl;
	t2++;
}
/*static����2��*/
void showStaticF2() {
	f2();
	f2();
	f2();
}

/*lambda���ʽ*/
void showLambda() {
	auto addFun = [](int a, int b) {return a + b;};
	cout << addFun(2, 3) << endl;
}
/*cmath��*/
void showCmath() {
	cout << "floor(2.5) is " << floor(2.5) << endl;
	cout << "floor(-2.5) is " << floor(-2.5) << endl;
	cout << "fabs(2.5) is " << fabs(2.5) << endl;
	cout << "fabs(-2.5) is " << fabs(-2.5) << endl;
	cout << "hypot(2, 2) is " << hypot(2, 2) << endl;//ƽ����
	cout << "pow(2, 3) is " << pow(2, 3) << endl;
}

/*�����*/
void showRandom() {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++) {
		cout << rand() << endl;
	}
}
/*[a,b]֮�䣬�����*/
void showRandom(int a, int b) {
	for (int i = 0; i < 70; i++) {
		int res = a + rand() % (b - a + 1);
		cout << res << endl;
	}
}

int main() {
	//showTypeSize();//�����������ʹ�С
	//enumDemo();//ö��
	//showExternVarable();//�ⲿ����
	//area();//const
	//showConst(); //����
	//showModifier(); //���η�
	//showStaticF1();//��̬����ʾ��
	//showStaticF2();

	//showLambda();//lambda���ʽ
	//showCmath();//��ѧ��ؼ���

	//showRandom();
	showRandom(2, 6);	//�����




	return 0;
}