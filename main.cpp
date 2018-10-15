/**
* @��Ŀ: �麯�������֤����
* @����: ����CoolShell���Ĳ��� https://coolshell.cn/articles/12165.html��������֤�麯�������ʽ
* @��������:
* @�������:
* @ʾ��:
* @˼·: �����ʼ�ĵط���ŵľ����麯��ָ�룬
		 �麯��ָ�뱾���Ͼ���һ��ָ����ָ���ָ�룬
		 ��˿���ͨ���麯��ָ���ҵ������麯����
*/
#include <iostream>

using namespace std;

class Base1
{
public:
	virtual void f() { cout << "Base1::f" << endl; }

	virtual void f(int) { cout << "Base1::f(int)" << endl; }

	virtual void f(double) { cout << "Base1::f(double)" << endl; }

	virtual void g() { cout << "Base1::g" << endl; }

	virtual void h() { cout << "Base1::h" << endl; }

};

class Base2
{
public:
	virtual void f() { cout << "Base2::f" << endl; }

	virtual void g() { cout << "Base2::g" << endl; }

	virtual void h() { cout << "Base2::h" << endl; }
};

class Base3
{
public:
	virtual void f() { cout << "Base3::f" << endl; }

	virtual void g() { cout << "Base3::g" << endl; }

	virtual void h() { cout << "Base3::h" << endl; }
};

class Derive : public Base1, public Base2, public Base3
{
public:
	virtual void f() { cout << "Derive::f" << endl; }

	virtual void f(int) { cout << "Derive::f(int)" << endl; }

	virtual void f(double) { cout << "Derive::f(double)" << endl; }

	virtual void g1() { cout << "Derive::g1" << endl; }
};

/* ���庯��ָ������ */
typedef void(*Fun)(void);


int main()
{
	Fun pFun = NULL;

	Base1 b1, b2, b3;
	Derive d;
	Fun **pVtab_b1 = (Fun **)&b1;  // ָ����ָ���ָ��
	Fun **pVtab_b2 = (Fun **)&b2;
	Fun **pVtab_b3 = (Fun **)&b3;
	Fun **pVtab = (Fun **)&d;

	cout << "Base1�麯����:" << endl;
	cout << "����������������������������������" << endl;
	pFun = (Fun)pVtab_b1[0][0];
	pFun();
	pFun = (Fun)pVtab_b1[0][1];
	pFun();
	pFun = (Fun)pVtab_b1[0][2];
	pFun();
	pFun = (Fun)pVtab_b1[0][3];
	pFun();
	pFun = (Fun)pVtab_b1[0][4];
	pFun();
	/* �麯����Ľ�β(�����ַ�����β��'\0'һ��)*/
	pFun = (Fun)pVtab_b1[0][5];
	cout << "end:" << pFun << endl;
	cout << "����������������������������������" << endl << endl;

	cout << "Base2�麯����:" << endl;
	cout << "����������������������������������" << endl;
	pFun = (Fun)pVtab_b2[0][0];
	pFun();
	pFun = (Fun)pVtab_b2[0][1];
	pFun();
	pFun = (Fun)pVtab_b2[0][2];
	pFun();
	pFun = (Fun)pVtab_b2[0][3];
	cout << "end:" << pFun << endl;
	cout << "����������������������������������" << endl << endl;

	cout << "Base3�麯����:" << endl;
	cout << "����������������������������������" << endl;
	pFun = (Fun)pVtab_b3[0][0];
	pFun();
	pFun = (Fun)pVtab_b3[0][1];
	pFun();
	pFun = (Fun)pVtab_b3[0][2];
	pFun();
	pFun = (Fun)pVtab_b1[0][3];
	cout << "end:" << pFun << endl;
	cout << "����������������������������������" << endl << endl;


	 /* Derive��̳в�����Base1����麯����1 */
	cout << "Derive�麯����:" << endl;
	cout << "����������������������������������" << endl;
	pFun = (Fun)pVtab[0][0];
	pFun();
	pFun = (Fun)pVtab[0][1];
	pFun();
	pFun = (Fun)pVtab[0][2];
	pFun();
	pFun = (Fun)pVtab[0][3];
	pFun();
	pFun = (Fun)pVtab[0][4];
	pFun();
	pFun = (Fun)pVtab[0][5];
	pFun();
	pFun = (Fun)pVtab[0][6];
	cout << "end1:" << pFun << endl;
	cout << "-----------------" << endl;

	pFun = (Fun)pVtab[1][0];
	pFun();
	pFun = (Fun)pVtab[1][1];
	pFun();
	pFun = (Fun)pVtab[1][2];
	pFun();
	pFun = (Fun)pVtab[1][3];
	cout << "end2:" << pFun << endl;
	cout << "-----------------" << endl;

	pFun = (Fun)pVtab[2][0];
	pFun();
	pFun = (Fun)pVtab[2][1];
	pFun();
	pFun = (Fun)pVtab[2][2];
	pFun();
	pFun = (Fun)pVtab[2][3];
	cout << "end3:" << pFun << endl;
	cout << "����������������������������������" << endl;

	return 0;
}

