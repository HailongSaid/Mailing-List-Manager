#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include "iostream"
#include <string>
using namespace std;
#define len sizeof(stu)
/*#define max_size_name 20
#define max_size_tel 20
#define max_size_address 20
#define max_size_qq 20*/
typedef struct  Person
{

	  int m_no;
    Person *m_next;
    string m_name;
    char  m_sex;                        /*m/w*/
    int  m_age ;
    string m_tel;
    string m_address;
    string m_qq;

}stu,*pstu;

//typedef person stu,*pstu;
#endif // DATE_H_INCLUDED

