#include "iostream"
#include "stdlib.h"
using namespace std;
#include "date.h"
#include "function.h"
#include "fstream"
#include "strstream"

int main()
{   
//	Sound();
    pstu head=NULL;
    head=Initlist();
    Createlist(head);
    while(1)
    {
        system("cls");
        system("COLOR 1C");
        Mainmenu();
        switch(Menuselect())
        {
        case  '1':
            if(NULL==head)
            {
                cout<<"intilist error"<<endl;
                system("PAUSE");
                break;
            }
            if(Addrecord(head)==1)
            {
                cout<<"input success!"<<endl;
                system("PAUSE");
            }
            break;
        case  '2':
            Deleterecod(head);
            break;
        case  '3':
            List(head);
            system("PAUSE");
            break;
        case  '4' :
            Searchrecord(head);
	           break;
        case  '5':
			Modify(head);
            break;
        case '7':
            if(Save(head))
                cout<<"Save success!"<<endl;
            else
            {
                cout<<"can not save!"<<endl;
            }
            system("PAUSE");
            break;
        case '6':
            Sort(head);
            break;
        case '8':
            Help();
            system("PAUSE");
            break;
        case '0':
            system("PAUSE");
            Destroylist(head);
            exit(0);
            break;
        default:
            cout<<"ÇëÖØÐÂÑ¡Ôñ"<<endl;
            system("PAUSE");

        }
    }

   return 0;
}
