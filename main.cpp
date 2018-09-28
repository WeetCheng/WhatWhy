/** 
* @题目: 虚函数表的验证程序
* @描述: 看了CoolShell陈皓的博客 https://coolshell.cn/articles/12165.html，用来验证虚函数表的形式
* @输入描述:
* @输出描述:
* @示例:
* @思路: 对象最开始的地方存放的就是虚函数指针，
         虚函数指针本质上就是一个指向函数指针的指针，
         因此可以通过虚函数指针找到整个虚函数表。
*/
//#include <iostream>
//
//using namespace std;
//
//class Base1
//{
//public:
//    virtual void f() { cout << "Base1::f" << endl; }
//
//    virtual void f(int) { cout << "Base1::f(int)" << endl; }
//
//    virtual void f(double) { cout << "Base1::f(double)" << endl; }
//
//    virtual void g() { cout << "Base1::g" << endl; }
//
//    virtual void h() { cout << "Base1::h" << endl; }
//
//};
//
//class Base2
//{
//public:
//    virtual void f() { cout << "Base2::f" << endl; }
//
//    virtual void g() { cout << "Base2::g" << endl; }
//
//    virtual void h() { cout << "Base2::h" << endl; }
//};
//
//class Base3
//{
//public:
//    virtual void f() { cout << "Base3::f" << endl; }
//
//    virtual void g() { cout << "Base3::g" << endl; }
//
//    virtual void h() { cout << "Base3::h" << endl; }
//};
//
//class Derive : public Base1, public Base2, public Base3
//{
//public:
//    virtual void f() { cout << "Derive::f" << endl; }
//
//    virtual void f(int) { cout << "Derive::f(int)" << endl; }
//
//    virtual void f(double) { cout << "Derive::f(double)" << endl; }
//
//    virtual void g1() { cout << "Derive::g1" << endl; }
//};
//
///* 定义函数指针类型 */
//typedef void(*Fun)(void);
//
//
//int main()
//{
//    Fun pFun = NULL;
//
//    Base1 b1, b2, b3;
//    Derive d;
//    Fun **pVtab_b1 = (Fun **) &b1;  // 指向函数指针的指针
//    Fun **pVtab_b2 = (Fun **) &b2;
//    Fun **pVtab_b3 = (Fun **) &b3;
//    Fun **pVtab = (Fun **) &d;
//
//    cout << "Base1虚函数表:" << endl;
//    cout << "—————————————————" << endl;
//    pFun = (Fun) pVtab_b1[0][0];
//    pFun();
//    pFun = (Fun) pVtab_b1[0][1];
//    pFun();
//    pFun = (Fun) pVtab_b1[0][2];
//    pFun();
//    pFun = (Fun) pVtab_b1[0][3];
//    pFun();
//    pFun = (Fun) pVtab_b1[0][4];
//    pFun();
//    /* 虚函数表的结尾(就像字符串结尾有'\0'一样)*/
//    pFun = (Fun) pVtab_b1[0][5];
//    cout << "end:" << pFun << endl;
//    cout << "—————————————————" << endl << endl;
//
//    cout << "Base2虚函数表:" << endl;
//    cout << "—————————————————" << endl;
//    pFun = (Fun) pVtab_b2[0][0];
//    pFun();
//    pFun = (Fun) pVtab_b2[0][1];
//    pFun();
//    pFun = (Fun) pVtab_b2[0][2];
//    pFun();
//    pFun = (Fun) pVtab_b2[0][3];
//    cout << "end:" << pFun << endl;
//    cout << "—————————————————" << endl << endl;
//
//    cout << "Base3虚函数表:" << endl;
//    cout << "—————————————————" << endl;
//    pFun = (Fun) pVtab_b3[0][0];
//    pFun();
//    pFun = (Fun) pVtab_b3[0][1];
//    pFun();
//    pFun = (Fun) pVtab_b3[0][2];
//    pFun();
//    pFun = (Fun) pVtab_b1[0][3];
//    cout << "end:" << pFun << endl;
//    cout << "—————————————————" << endl << endl;
//
//
//    /* Derive类继承并覆盖Base1后的虚函数表1 */
//    cout << "Derive虚函数表:" << endl;
//    cout << "—————————————————" << endl;
//    pFun = (Fun) pVtab[0][0];
//    pFun();
//    pFun = (Fun) pVtab[0][1];
//    pFun();
//    pFun = (Fun) pVtab[0][2];
//    pFun();
//    pFun = (Fun) pVtab[0][3];
//    pFun();
//    pFun = (Fun) pVtab[0][4];
//    pFun();
//    pFun = (Fun) pVtab[0][5];
//    pFun();
//    pFun = (Fun) pVtab[0][6];
//    cout << "end1:" << pFun << endl;
//    cout << "-----------------" << endl;
//
//    pFun = (Fun) pVtab[1][0];
//    pFun();
//    pFun = (Fun) pVtab[1][1];
//    pFun();
//    pFun = (Fun) pVtab[1][2];
//    pFun();
//    pFun = (Fun) pVtab[1][3];
//    cout << "end2:" << pFun << endl;
//    cout << "-----------------" << endl;
//
//    pFun = (Fun) pVtab[2][0];
//    pFun();
//    pFun = (Fun) pVtab[2][1];
//    pFun();
//    pFun = (Fun) pVtab[2][2];
//    pFun();
//    pFun = (Fun) pVtab[2][3];
//    cout << "end3:" << pFun << endl;
//    cout << "—————————————————" << endl;
//
//    return 0;
//}

