#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include "date.h"
void Mainmenu();
void Createlist(pstu head);
char  Menuselect();
pstu Initlist();
int Iserror(char* c);
int Iserror1(char* c) ;
int Addrecord(pstu head);
void List(pstu head);
int Save(pstu head);
void Searchrecord(pstu head);
void Searchmenu( );
void Searchname(pstu head);
void Searchno(pstu head);
void Delemenu();
void Deletename(pstu head);
void Deteleno(pstu head);
void Deleterecod(pstu head);
void Modify(pstu head);
void Modifyname(pstu head);
void Modifyno(pstu head);
void Modifymenu();
void Sort(pstu head);
void Sortname(pstu head);
void Sortno(pstu head);
void Sortmenu();
void Destroylist(pstu head);
void Help();
//void Sound();
#endif // FUNCTION_H_INCLUDED
