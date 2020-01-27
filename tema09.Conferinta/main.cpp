#include <iostream>
#include <stdlib.h>
#include "Participant.h"
#include "Roman.h"
#include "Francez.h"
#include "German.h"
#include <vector>

using namespace std;

void Meniu()
{
    system("CLS");
    cout<<"Alegeti optiunea dorita:"<<endl;
    cout<<"1. Adaugare participant"<<endl;
    cout<<"2. Afisare sumar"<<endl;
    cout<<"0. Iesire"<<endl;
}

Participant* CreazaParticipant()
{
    short n;
    system("CLS");
    cout<<"Alegeti nationalitatea:"<<endl;
    cout<<"1. Roman"<<endl;
    cout<<"2. Francez"<<endl;
    cout<<"3. German"<<endl;
    cout<<"4. Alta"<<endl;
    cout<<endl;
    cout<<"Introduceti nationalitatea : ";
    cin>>n;
    switch (n)
    {
        case 1: {Participant* par=new Roman(); return par;break;}
        case 2: {Participant* par=new Francez(); return par;break;}
        case 3: {Participant* par=new German(); return par;break;}
        default: {Participant* par=new Participant(); return par; break;}
    }
    /*if (n==1) { Participant* par=new Roman(); return par;}
        else if (n==2) { Participant* par=new Francez(); return par; }
          else if (n==3) { Participant* par=new German(); return par; }
             else  { Participant* par=new Participant(); return par; }*/
}

int main()
{
  vector<Participant*> pntParticipanti;
  Meniu();
  cout<<"Introduceti optiunea : ";
  short n;
  cin>>n;
  while (n!=0)
  {
    short ro=0,fr=0,ger=0,alt=0;
    if (n==1) pntParticipanti.push_back(CreazaParticipant());
     else if (n==2)
     {
         system("CLS");
         for (unsigned short i=0;i<pntParticipanti.size();i++)
             switch (pntParticipanti[i]->Vorbeste())
                {
                    case 0: alt++;break;
                    case 1: ro++;break;
                    case 2: ger++;break;
                    case 3: fr++;break;
                }
       if (alt>0||ro>0||ger>0||fr>0) cout<<"Participanti inscrisi pana acum:"<<endl;
       if (ro>0) cout<<ro<<" Romani"<<endl;
       if (fr>0) cout<<fr<<" Francezi"<<endl;
       if (ger>0) cout<<ger<<" Germani"<<endl;
       if (alt>0) cout<<alt<<" Altii"<<endl;
       system("pause");
     }
     system("CLS");
     Meniu();
     cout<<"Introduceti optiunea : ";
     cin>>n;
  }
 return 0;
}

