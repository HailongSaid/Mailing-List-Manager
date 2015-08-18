#include "iostream"
#include "function.h"
#include <stdlib.h>
#include <stdio.h>
#include "fstream"
#include "strstream"
#include <string.h>
//#include <windows.h>
//#include <mmsystem.h>
using namespace std;

void Mainmenu()    //主菜单
{
    cout<<"\n\t|------------------------------------|\n";
    cout<<"\t|     Please Select The Functions    |\n";
    cout<<"\t|    Though The Following Number     |\n";
    cout<<"\t|------------------------------------|\n";
    cout<<"\t**************************************\n";
    cout<<"\t|       1.Add        增加记录        |\n";
    cout<<"\t|       2.Delete     删除记录        |\n";
    cout<<"\t|       3.List       显示记录        |\n";
    cout<<"\t|       4.Search     查询记录        |\n";
    cout<<"\t|       5.Modify     修改记录        |\n";
    cout<<"\t|       6.Sort       排序记录        |\n";
    cout<<"\t|       7.Save       保存记录        |\n";
    cout<<"\t|       8.Help       帮助            |\n";
    cout<<"\t|       0.Exit       退出系统        |\n";
    cout<<"\t**************************************\n";

}

int Iserror(char* c) //判断输入的字符是不是合法
{
    if(strlen(c)>1)
        return 1;
    else
    {
        if(c[0]>='0'&&c[0]<='8')
            return 0;
        else
            return 1;
    }

}
int Iserror1(char* c) //判断输入的字符是不是合法
{
    if(strlen(c)>1)
        return 1;
    else
    {
        if(c[0]>='0'&&c[0]<='2')
            return 0;
        else
            return 1;
    }

}



void Createlist(pstu head)//创建链表
{
    while(head->m_next !=NULL)
        head=head->m_next ;
    ifstream in("address.txt");
    for(string s; getline(in,s);)
    {
        istrstream in1(s.c_str(), 0);
        pstu p=new stu;
        in1>>(*p).m_no>>(*p).m_name>>(*p).m_sex>>(*p).m_age>>(*p).m_tel>>(*p).m_address>>(*p).m_qq;
        p->m_next =NULL;
        (*head).m_next=p;
        head=p;
    }
}
char  Menuselect()//查找menu
{
    cout<<"\t数字对应功能请选择(0-8)的功能:";
    char c[]="";
    cin>>c;
    //cout<<endl;
    if(Iserror(c))
        return 'a';
    else
        return c[0];

}

pstu Initlist() //创建头结点
{
    pstu head=new stu;
    if(NULL==head) return NULL;
    (*head).m_next=NULL;
    return head;
}


int Addrecord(pstu head) //添加记录
{
    system("cls");
    while((*head).m_next!=NULL)
        head=(*head).m_next;
    pstu p=new stu;
    (*p).m_no++;
    if(NULL==p) return 0;
    (*head).m_next=p;
    (*p).m_next=NULL;
    cout<<"请输入学号(int)：";
    cin>>(*p).m_no;
    cout<<endl;
    cout<<"请输入姓名(string)：";
    cin>>(*p).m_name;
    cout<<endl;
    cout<<"请输入性别(w/m)(char)：";
    cin>>(*p).m_sex;
    cout<<endl;
    cout<<"请输入年龄(int)：";
    cin>>(*p).m_age;
    cout<<endl;
    cout<<"请输入电话号码(string)：";
    cin>>(*p).m_tel;
    cout<<endl;
    cout<<"请输入地址(string)：";
    cin>>(*p).m_address;
    cout<<endl;
    cout<<"请输入QQ(string)：";
    cin>>(*p).m_qq;
    cout<<endl;
    return 1;
}

void List(pstu head) //显示记录
{
    head=(*head).m_next;
    system("cls");
    cout<<"                         -------显示结果---------"<<endl;
    while(head!=NULL)
    {
		
        cout.width(8);
		cout<<(*head).m_no;
		cout.width(8);
		cout<<(*head).m_name;
		cout.width(8);
		cout<<(*head).m_sex;
		cout.width(8);
		cout<<(*head).m_age;
		cout.width(12);
		cout<<(*head).m_tel;
		cout.width(12);
		cout<<(*head).m_address;
		cout.width(12);
		cout<<(*head).m_qq<<endl;
        
		head=(*head).m_next;
    }
}

int Save(pstu head)//保存
{
    ifstream in("address.txt");
    ofstream out("address.txt");

    head=(*head).m_next;
    while(head!=NULL)
    {
        out<<(*head).m_no<<"  "<<(*head).m_name<<"  "<<(*head).m_sex<<"  "<<(*head).m_age<<"  "<<(*head).m_tel<<"  "<<(*head).m_address<<"  "<<(*head).m_qq<<endl;
        head=(*head).m_next;
    }
    return 1;
}
void Searchmenu() //查找menu
{
    cout<<"----------查找菜单-------------"<<endl;
    cout<<"1.按姓名查找"<<endl;
    cout<<"2.按学号查找"<<endl;
    cout<<"0.返回"<<endl;
    cout<<"--------------------------------"<<endl;
}


void Searchname(pstu ahead)// 按姓名进行删除
{
    string str;
    cout<<"请输入你要查找的姓名：";
    cin>>str;
    system("cls");
    cout<<"                  -----------查找结果------------"<<endl;
    ahead=(*ahead).m_next;
    while(ahead!=NULL)
    {
        if((*ahead).m_name==str)
		{
			 cout.width(8);
		cout<<(*ahead).m_no;
		cout.width(8);
		cout<<(*ahead).m_name;
		cout.width(8);
		cout<<(*ahead).m_sex;
		cout.width(8);
		cout<<(*ahead).m_age;
		cout.width(12);
		cout<<(*ahead).m_tel;
		cout.width(12);
		cout<<(*ahead).m_address;
		cout.width(12);
		cout<<(*ahead).m_qq<<endl;
		}
        ahead=(*ahead).m_next;
    }
    system("PAUSE");

}
void Searchno(pstu ahead)// 按学号进行查找
{
    int str;
    cout<<"请输入你要查找的学号：";
    cin>>str;
    system("cls");
    cout<<"                       -----------查找结果------------"<<endl;
    ahead=(*ahead).m_next;
    while(ahead!=NULL)
    {
        if((*ahead).m_no==str)
		{
			 cout.width(8);
		cout<<(*ahead).m_no;
		cout.width(8);
		cout<<(*ahead).m_name;
		cout.width(8);
		cout<<(*ahead).m_sex;
		cout.width(8);
		cout<<(*ahead).m_age;
		cout.width(12);
		cout<<(*ahead).m_tel;
		cout.width(12);
		cout<<(*ahead).m_address;
		cout.width(12);
		cout<<(*ahead).m_qq<<endl;
		}
       ahead=(*ahead).m_next;

    }
    system("PAUSE");


}

void Searchrecord(pstu head)  //查找记录
{
    while(1)
    {
        system("cls");
        Searchmenu();
        char i[]="";
        cout<<"请输入查询方式[0-2]：";
        cin>>i;
        char p;
        if(Iserror(i))
            p='a';
        else
            p=i[0];
        switch(p)
        {
        case '1':
            Searchname(head);
            break;
        case '2':
            Searchno(head);
            break;
        case '0':
            return ;
            break;
        default:
            cout<<"你输入的字符不规范，请重新再输入！"<<endl;
            system("PAUSE");
            break;
        }


    }

}
void Delemenu() //删除菜单
{
    cout<<"----------删除菜单-------------"<<endl;
    cout<<"1.按姓名删除"<<endl;
    cout<<"2.按学号删除"<<endl;
    cout<<"0.返回"<<endl;
    cout<<"--------------------------------"<<endl;

}

void Modifymenu()   //修改菜单
{
    cout<<"----------修改菜单-------------"<<endl;
    cout<<"1.按姓名修改"<<endl;
    cout<<"2.按学号修改"<<endl;
    cout<<"0.返回"<<endl;
    cout<<"--------------------------------"<<endl;

}
void Deletename(pstu ahead)// 按姓名进行删除
{
    string str;
    cout<<"请输入你要删除的姓名：";
    cin>>str;
    system("cls");
    cout<<"                    -----------要删除的记录------------"<<endl;
    pstu p=(*ahead).m_next;
    while(p!=NULL)
    {
        if((*p).m_name==str)
        {
			 cout.width(8);
		cout<<(*p).m_no;
		cout.width(8);
		cout<<(*p).m_name;
		cout.width(8);
		cout<<(*p).m_sex;
		cout.width(8);
		cout<<(*p).m_age;
		cout.width(12);
		cout<<(*p).m_tel;
		cout.width(12);
		cout<<(*p).m_address;
		cout.width(12);
		cout<<(*p).m_qq<<endl;
	    (*ahead).m_next=(*p).m_next;
            delete p;
            p=ahead;
        }
        ahead=p;
        p=(*p).m_next;
    }
    system("PAUSE");


}
void Deleteno(pstu ahead)  // 按电话号码进行删除
{
    int str;
    cout<<"请输入你要删除的学号：";
    cin>>str;
    system("cls");
    cout<<"                   -----------要删除的记录------------"<<endl;
    pstu p=(*ahead).m_next;
    while(p!=NULL)
    {
        if((*p).m_no==str)
        {
			cout.width(8);
		cout<<(*p).m_no;
		cout.width(8);
		cout<<(*p).m_name;
		cout.width(8);
		cout<<(*p).m_sex;
		cout.width(8);
		cout<<(*p).m_age;
		cout.width(12);
		cout<<(*p).m_tel;
		cout.width(12);
		cout<<(*p).m_address;
		cout.width(12);
		cout<<(*p).m_qq<<endl;
        (*ahead).m_next=(*p).m_next;
            delete p;
            p=ahead;

        }
        ahead=p;
        p=(*p).m_next;
    }
	system("PAUSE");

}

void Deleterecod(pstu head) //删除记录
{
    while(1)
    {
        system("cls");
        Delemenu();
        char i[]="";
        cout<<"请输入查询方式[0-2]：";
        cin>>i;
        char p;
        if(Iserror(i))
            p='a';
        else
            p=i[0];
        switch(p)
        {
        case '1':
            Deletename(head);
            break;
        case '2':
            Deleteno(head);
            break;
        case '0':
            return ;
            break;
        default:
            cout<<"你输入的字符不规范，请重新再输入！"<<endl;
            system("PAUSE");
            break;
        }

    }

}
void  Modify(pstu head)   //修改记录
{
    while(1)
    {
        system("cls");
        Modifymenu();
        char i[]="";
        cout<<"请输入查询方式[0-2]：";
        cin>>i;
        char p;
        if(Iserror(i))
            p='a';
        else
            p=i[0];
        switch(p)
        {
        case '1':
            Modifyname(head);
            break;
        case '2':
            Modifyno(head);
            break;
        case '0':
            return ;
            break;
        default:
            cout<<"你输入的字符不规范，请重新再输入！"<<endl;
            system("PAUSE");
            break;
        }

    }


}
void Modifyname(pstu ahead)  //按姓名修改
{
    string str;
    cout<<"请输入你要修改的姓名：";
    cin>>str;
    system("cls");
    cout<<"                    -----------要修改的记录------------"<<endl;
    pstu p=(*ahead).m_next;
    while(p!=NULL)
    {
        if((*p).m_name==str)
        {
			cout.width(8);
		cout<<(*p).m_no;
		cout.width(8);
		cout<<(*p).m_name;
		cout.width(8);
		cout<<(*p).m_sex;
		cout.width(8);
		cout<<(*p).m_age;
		cout.width(12);
		cout<<(*p).m_tel;
		cout.width(12);
		cout<<(*p).m_address;
		cout.width(12);
		cout<<(*p).m_qq<<endl;
       	cout<<"你确定要修改这个记录?(y/n):";
            char c;
            cin>>c;
            if(c=='y'||c=='Y')
            {
                cout<<"请输入学号(int)：";
                cin>>(*p).m_no;
                cout<<endl;
                cout<<"请输入姓名(string)：";
                cin>>(*p).m_name;
                cout<<endl;
                cout<<"请输入性别(w/m)(char)：";
                cin>>(*p).m_sex;
                cout<<endl;
                cout<<"请输入年龄(int)：";
                cin>>(*p).m_age;
                cout<<endl;
                cout<<"请输入电话号码(string)：";
                cin>>(*p).m_tel;
                cout<<endl;
                cout<<"请输入地址(string)：";
                cin>>(*p).m_address;
                cout<<endl;
                cout<<"请输入QQ(string)：";
                cin>>(*p).m_qq;
                cout<<endl;
				cout.width(8);
	   	        cout<<(*p).m_no;
		        cout.width(8);
		        cout<<(*p).m_name;
		        cout.width(8);
	        	cout<<(*p).m_sex;
		    	cout.width(8);
		    	cout<<(*p).m_age;
		    	cout.width(12);
	    		cout<<(*p).m_tel;
		    	cout.width(12);
	    		cout<<(*p).m_address;
	    		cout.width(12);
	    		cout<<(*p).m_qq<<endl;
               
            }
        }
        p=(*p).m_next;
    }
    system("PAUSE");


}
void Modifyno(pstu ahead)    //按学号修改
{
    int str;
    cout<<"请输入你要修改的学号：";
    cin>>str;
    system("cls");
    cout<<"                         -----------要修改的记录------------"<<endl;
    pstu p=(*ahead).m_next;
    while(p!=NULL)
    {
        if((*p).m_no==str)
        {
			cout.width(8);
		cout<<(*p).m_no;
		cout.width(8);
		cout<<(*p).m_name;
		cout.width(8);
		cout<<(*p).m_sex;
		cout.width(8);
		cout<<(*p).m_age;
		cout.width(12);
		cout<<(*p).m_tel;
		cout.width(12);
		cout<<(*p).m_address;
		cout.width(12);
		cout<<(*p).m_qq<<endl;
        cout<<"你确定要修改这条记录?(y/n):";
            char c;
            cin>>c;
            if(c=='y'||c=='Y')
            {
                cout<<"请输入学号(int)：";
                cin>>(*p).m_no;
                cout<<endl;
                cout<<"请输入姓名(string)：";
                cin>>(*p).m_name;
                cout<<endl;
                cout<<"请输入性别(w/m)(char)：";
                cin>>(*p).m_name;
                cout<<endl;
                cout<<"请输入年龄(int)：";
                cin>>(*p).m_age;
                cout<<endl;
                cout<<"请输入电话号码(string)：";
                cin>>(*p).m_tel;
                cout<<endl;
                cout<<"请输入地址(string)：";
                cin>>(*p).m_address;
                cout<<endl;
                cout<<"请输入QQ(string)：";
                cin>>(*p).m_qq;
                cout<<endl;
				cout.width(8);
	    		cout<<(*p).m_no;
	    		cout.width(8);
	    		cout<<(*p).m_name;
	    		cout.width(8);
	    		cout<<(*p).m_sex;
	    		cout.width(8);
		    	cout<<(*p).m_age;
	    		cout.width(12);
	     	    cout<<(*p).m_tel;
	    		cout.width(12);
	    		cout<<(*p).m_address;
	    		cout.width(12);
	    		cout<<(*p).m_qq<<endl;
             }
        }
        p=(*p).m_next;
    }
    system("PAUSE");
}


void Sort(pstu ahead)  //排序
{
    while(1)
    {
        system("cls");
        Sortmenu();
        char i[]="";
        cout<<"请输入查询方式[0-2]：";
        cin>>i;
        char p;
        if(Iserror(i))
            p='a';
        else
            p=i[0];
        switch(p)
        {
        case '1':
            Sortname(ahead);
            break;
        case '2':
            Sortno(ahead);
            break;
        case '0':
            return ;
            break;
        default:
            cout<<"你输入的字符不规范，请重新再输入！"<<endl;
            system("PAUSE");
            break;
        }

    }


}

void Sortname(pstu ahead)  //按姓名排序，采用的是冒泡排序
{
    string str;
    system("cls");
    pstu curr=(*ahead).m_next;
    pstu p1=ahead;
    int num=0;
    while(curr!=NULL)
    {
        num++;
        curr=(*curr).m_next;
    }
    int i=0;
    while(num>1&&i<=num)
    {
        pstu p2=p1;
        ahead=(*p1).m_next;
        curr=(*ahead).m_next;
        while(curr!=NULL)
        {
            if((*curr).m_name<(*ahead).m_name)
            {
                (*ahead).m_next=(*curr).m_next;
                (*p2).m_next=curr;
                (*curr).m_next=ahead;
                pstu pp;
                pp=ahead;
                ahead=curr;
                curr=pp;

            }
            p2=ahead;
            ahead=curr;
            curr=(*curr).m_next;

        }
        i++;

    }
    cout<<"排序成功！"<<endl;
    cout<<"-----------排序结果------------"<<endl;
    List(p1);
    system("PAUSE");
}
void Sortno(pstu ahead)//按学号排序，采用的是冒泡排序
{
    system("cls");
    pstu curr=(*ahead).m_next;
    pstu p1=ahead;
    int num=0;
    while(curr!=NULL)
    {
        num++;
        curr=(*curr).m_next;
    }
    int i=0;
    while(num>1&&i<=num)
    {
        pstu p2=p1;
        ahead=(*p1).m_next;
        curr=(*ahead).m_next;
        while(curr!=NULL)
        {
            if((*curr).m_no<(*ahead).m_no)
            {
                (*ahead).m_next=(*curr).m_next;
                (*p2).m_next=curr;
                (*curr).m_next=ahead;
                pstu pp;
                pp=ahead;
                ahead=curr;
                curr=pp;

            }
            p2=ahead;
            ahead=curr;
            curr=(*curr).m_next;

        }
        i++;

    }
    cout<<"排序成功！"<<endl;
    cout<<"                     -----------排序结果------------"<<endl;
    List(p1);
    system("PAUSE");
}

void Sortmenu()   //排序菜单
{
    cout<<"----------排序菜单-------------"<<endl;
    cout<<"1.按姓名排序"<<endl;
    cout<<"2.按学号排序"<<endl;
    cout<<"0.返回"<<endl;
    cout<<"--------------------------------"<<endl;

}

void Destroylist(pstu head)   //对链表进行销毁
{
    pstu curr=(*head).m_next;
    while(head!=NULL)
    {
        delete head;
        head=curr;
        if(curr!=NULL)
            curr=(*curr).m_next;

    }

}

void Help()    //帮助文档
{
    system("cls");
    cout<<"\n\t   |--------------------------------------|\n";
    cout<<"\t                    Help                   \n";
    cout<<"\n\t   |--------------------------------------|\n";
    cout<<"   **********************************************************\n";
    cout<<" 0——8数字时："<<endl;
    cout<<"（1）、当选择的为0时，执行退出程序；"<<endl;
    cout<<"（2）、当选择的为1时，执行增加记录，将用户给出的记录添加到存储空间；"<<endl;
    cout<<"（3）、当选择的为2时，根据用户的需求对所需要的删除的信息进行删除，将存储空间中的一个记录删除；"<<endl;
    cout<<"（4）、当选择的为3时，在屏幕上打印显示所有的记录；"<<endl;
    cout<<"（5）、当选择的为4时，执行查找功能，将查找到得信息显示在屏幕上；"<<endl;
    cout<<"（6）、当选择的为5时，在屏幕上打排序改方式，执行查找功排序并将结果显示在屏幕上；"<<endl;
    cout<<"（7）、当选择的为6时，在屏幕上打排序改方式，执行查找功排序并将结果显示在屏幕上；"<<endl;
    cout<<"（8）、当选择的为7时，保存所有的用户信息到文件中去；     \n";
    cout<<"（9）、当选择的为8时，显示帮助信息；     \n";
    cout<<"   **********************************************************\n";

}

/*void Sound()
{
   PlaySound("backmuxic.wav",0,SND_FILENAME|SND_ASYNC);
}
*/