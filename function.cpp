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

void Mainmenu()    //���˵�
{
    cout<<"\n\t|------------------------------------|\n";
    cout<<"\t|     Please Select The Functions    |\n";
    cout<<"\t|    Though The Following Number     |\n";
    cout<<"\t|------------------------------------|\n";
    cout<<"\t**************************************\n";
    cout<<"\t|       1.Add        ���Ӽ�¼        |\n";
    cout<<"\t|       2.Delete     ɾ����¼        |\n";
    cout<<"\t|       3.List       ��ʾ��¼        |\n";
    cout<<"\t|       4.Search     ��ѯ��¼        |\n";
    cout<<"\t|       5.Modify     �޸ļ�¼        |\n";
    cout<<"\t|       6.Sort       �����¼        |\n";
    cout<<"\t|       7.Save       �����¼        |\n";
    cout<<"\t|       8.Help       ����            |\n";
    cout<<"\t|       0.Exit       �˳�ϵͳ        |\n";
    cout<<"\t**************************************\n";

}

int Iserror(char* c) //�ж�������ַ��ǲ��ǺϷ�
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
int Iserror1(char* c) //�ж�������ַ��ǲ��ǺϷ�
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



void Createlist(pstu head)//��������
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
char  Menuselect()//����menu
{
    cout<<"\t���ֶ�Ӧ������ѡ��(0-8)�Ĺ���:";
    char c[]="";
    cin>>c;
    //cout<<endl;
    if(Iserror(c))
        return 'a';
    else
        return c[0];

}

pstu Initlist() //����ͷ���
{
    pstu head=new stu;
    if(NULL==head) return NULL;
    (*head).m_next=NULL;
    return head;
}


int Addrecord(pstu head) //��Ӽ�¼
{
    system("cls");
    while((*head).m_next!=NULL)
        head=(*head).m_next;
    pstu p=new stu;
    (*p).m_no++;
    if(NULL==p) return 0;
    (*head).m_next=p;
    (*p).m_next=NULL;
    cout<<"������ѧ��(int)��";
    cin>>(*p).m_no;
    cout<<endl;
    cout<<"����������(string)��";
    cin>>(*p).m_name;
    cout<<endl;
    cout<<"�������Ա�(w/m)(char)��";
    cin>>(*p).m_sex;
    cout<<endl;
    cout<<"����������(int)��";
    cin>>(*p).m_age;
    cout<<endl;
    cout<<"������绰����(string)��";
    cin>>(*p).m_tel;
    cout<<endl;
    cout<<"�������ַ(string)��";
    cin>>(*p).m_address;
    cout<<endl;
    cout<<"������QQ(string)��";
    cin>>(*p).m_qq;
    cout<<endl;
    return 1;
}

void List(pstu head) //��ʾ��¼
{
    head=(*head).m_next;
    system("cls");
    cout<<"                         -------��ʾ���---------"<<endl;
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

int Save(pstu head)//����
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
void Searchmenu() //����menu
{
    cout<<"----------���Ҳ˵�-------------"<<endl;
    cout<<"1.����������"<<endl;
    cout<<"2.��ѧ�Ų���"<<endl;
    cout<<"0.����"<<endl;
    cout<<"--------------------------------"<<endl;
}


void Searchname(pstu ahead)// ����������ɾ��
{
    string str;
    cout<<"��������Ҫ���ҵ�������";
    cin>>str;
    system("cls");
    cout<<"                  -----------���ҽ��------------"<<endl;
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
void Searchno(pstu ahead)// ��ѧ�Ž��в���
{
    int str;
    cout<<"��������Ҫ���ҵ�ѧ�ţ�";
    cin>>str;
    system("cls");
    cout<<"                       -----------���ҽ��------------"<<endl;
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

void Searchrecord(pstu head)  //���Ҽ�¼
{
    while(1)
    {
        system("cls");
        Searchmenu();
        char i[]="";
        cout<<"�������ѯ��ʽ[0-2]��";
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
            cout<<"��������ַ����淶�������������룡"<<endl;
            system("PAUSE");
            break;
        }


    }

}
void Delemenu() //ɾ���˵�
{
    cout<<"----------ɾ���˵�-------------"<<endl;
    cout<<"1.������ɾ��"<<endl;
    cout<<"2.��ѧ��ɾ��"<<endl;
    cout<<"0.����"<<endl;
    cout<<"--------------------------------"<<endl;

}

void Modifymenu()   //�޸Ĳ˵�
{
    cout<<"----------�޸Ĳ˵�-------------"<<endl;
    cout<<"1.�������޸�"<<endl;
    cout<<"2.��ѧ���޸�"<<endl;
    cout<<"0.����"<<endl;
    cout<<"--------------------------------"<<endl;

}
void Deletename(pstu ahead)// ����������ɾ��
{
    string str;
    cout<<"��������Ҫɾ����������";
    cin>>str;
    system("cls");
    cout<<"                    -----------Ҫɾ���ļ�¼------------"<<endl;
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
void Deleteno(pstu ahead)  // ���绰�������ɾ��
{
    int str;
    cout<<"��������Ҫɾ����ѧ�ţ�";
    cin>>str;
    system("cls");
    cout<<"                   -----------Ҫɾ���ļ�¼------------"<<endl;
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

void Deleterecod(pstu head) //ɾ����¼
{
    while(1)
    {
        system("cls");
        Delemenu();
        char i[]="";
        cout<<"�������ѯ��ʽ[0-2]��";
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
            cout<<"��������ַ����淶�������������룡"<<endl;
            system("PAUSE");
            break;
        }

    }

}
void  Modify(pstu head)   //�޸ļ�¼
{
    while(1)
    {
        system("cls");
        Modifymenu();
        char i[]="";
        cout<<"�������ѯ��ʽ[0-2]��";
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
            cout<<"��������ַ����淶�������������룡"<<endl;
            system("PAUSE");
            break;
        }

    }


}
void Modifyname(pstu ahead)  //�������޸�
{
    string str;
    cout<<"��������Ҫ�޸ĵ�������";
    cin>>str;
    system("cls");
    cout<<"                    -----------Ҫ�޸ĵļ�¼------------"<<endl;
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
       	cout<<"��ȷ��Ҫ�޸������¼?(y/n):";
            char c;
            cin>>c;
            if(c=='y'||c=='Y')
            {
                cout<<"������ѧ��(int)��";
                cin>>(*p).m_no;
                cout<<endl;
                cout<<"����������(string)��";
                cin>>(*p).m_name;
                cout<<endl;
                cout<<"�������Ա�(w/m)(char)��";
                cin>>(*p).m_sex;
                cout<<endl;
                cout<<"����������(int)��";
                cin>>(*p).m_age;
                cout<<endl;
                cout<<"������绰����(string)��";
                cin>>(*p).m_tel;
                cout<<endl;
                cout<<"�������ַ(string)��";
                cin>>(*p).m_address;
                cout<<endl;
                cout<<"������QQ(string)��";
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
void Modifyno(pstu ahead)    //��ѧ���޸�
{
    int str;
    cout<<"��������Ҫ�޸ĵ�ѧ�ţ�";
    cin>>str;
    system("cls");
    cout<<"                         -----------Ҫ�޸ĵļ�¼------------"<<endl;
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
        cout<<"��ȷ��Ҫ�޸�������¼?(y/n):";
            char c;
            cin>>c;
            if(c=='y'||c=='Y')
            {
                cout<<"������ѧ��(int)��";
                cin>>(*p).m_no;
                cout<<endl;
                cout<<"����������(string)��";
                cin>>(*p).m_name;
                cout<<endl;
                cout<<"�������Ա�(w/m)(char)��";
                cin>>(*p).m_name;
                cout<<endl;
                cout<<"����������(int)��";
                cin>>(*p).m_age;
                cout<<endl;
                cout<<"������绰����(string)��";
                cin>>(*p).m_tel;
                cout<<endl;
                cout<<"�������ַ(string)��";
                cin>>(*p).m_address;
                cout<<endl;
                cout<<"������QQ(string)��";
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


void Sort(pstu ahead)  //����
{
    while(1)
    {
        system("cls");
        Sortmenu();
        char i[]="";
        cout<<"�������ѯ��ʽ[0-2]��";
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
            cout<<"��������ַ����淶�������������룡"<<endl;
            system("PAUSE");
            break;
        }

    }


}

void Sortname(pstu ahead)  //���������򣬲��õ���ð������
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
    cout<<"����ɹ���"<<endl;
    cout<<"-----------������------------"<<endl;
    List(p1);
    system("PAUSE");
}
void Sortno(pstu ahead)//��ѧ�����򣬲��õ���ð������
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
    cout<<"����ɹ���"<<endl;
    cout<<"                     -----------������------------"<<endl;
    List(p1);
    system("PAUSE");
}

void Sortmenu()   //����˵�
{
    cout<<"----------����˵�-------------"<<endl;
    cout<<"1.����������"<<endl;
    cout<<"2.��ѧ������"<<endl;
    cout<<"0.����"<<endl;
    cout<<"--------------------------------"<<endl;

}

void Destroylist(pstu head)   //�������������
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

void Help()    //�����ĵ�
{
    system("cls");
    cout<<"\n\t   |--------------------------------------|\n";
    cout<<"\t                    Help                   \n";
    cout<<"\n\t   |--------------------------------------|\n";
    cout<<"   **********************************************************\n";
    cout<<" 0����8����ʱ��"<<endl;
    cout<<"��1������ѡ���Ϊ0ʱ��ִ���˳�����"<<endl;
    cout<<"��2������ѡ���Ϊ1ʱ��ִ�����Ӽ�¼�����û������ļ�¼��ӵ��洢�ռ䣻"<<endl;
    cout<<"��3������ѡ���Ϊ2ʱ�������û������������Ҫ��ɾ������Ϣ����ɾ�������洢�ռ��е�һ����¼ɾ����"<<endl;
    cout<<"��4������ѡ���Ϊ3ʱ������Ļ�ϴ�ӡ��ʾ���еļ�¼��"<<endl;
    cout<<"��5������ѡ���Ϊ4ʱ��ִ�в��ҹ��ܣ������ҵ�����Ϣ��ʾ����Ļ�ϣ�"<<endl;
    cout<<"��6������ѡ���Ϊ5ʱ������Ļ�ϴ�����ķ�ʽ��ִ�в��ҹ����򲢽������ʾ����Ļ�ϣ�"<<endl;
    cout<<"��7������ѡ���Ϊ6ʱ������Ļ�ϴ�����ķ�ʽ��ִ�в��ҹ����򲢽������ʾ����Ļ�ϣ�"<<endl;
    cout<<"��8������ѡ���Ϊ7ʱ���������е��û���Ϣ���ļ���ȥ��     \n";
    cout<<"��9������ѡ���Ϊ8ʱ����ʾ������Ϣ��     \n";
    cout<<"   **********************************************************\n";

}

/*void Sound()
{
   PlaySound("backmuxic.wav",0,SND_FILENAME|SND_ASYNC);
}
*/