#include "mnt.h"
#include <math.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;
Mnt::Mnt()
{
}

void Mnt::loadMnt(string fileName)
{
    //Lecture du fichier et construction des points
    std::cout << "loading " <<fileName << " : debut..." << std::endl;
    ifstream fichier( fileName.data() );
    int nb=0;
    while(!fichier.eof())
    {
        Point p; char sep = '\0';
        float x = -1, y = -1, z = -1;
        if(fichier >> p.x>> p.y>>p.z)
        {
            nb++;
            p.id_point=nb;
            lesPoints.push_back(p);
            cout << p.id_point<<" "<<p.x<<" "<<p.y<<" "<<p.z<<endl;

        }

    }

    cout << "fin de lecture du fichier"<<endl;
    fichier.close();
    ///Construction des triangles
    ///1-vérification du nombre des points
    int racine=sqrt(lesPoints.size());
    if(racine*racine!= lesPoints.size())
    {
        cout<<"impossible de construire les triangles!"<<endl;
        return;
    }
    //2-création des triangles
    /*for(int i=0;i<lesPoints.size()-2;i++)
    {
        Triangle t;
        t.id_Triangle=i+1;
        t.id_Sommet1=lesPoints[i].id_point;
        t.id_Sommet2=lesPoints[i+1].id_point;
        t.id_Sommet3=lesPoints[i+2].id_point;
        lesTriangles.push_back(t);
        cout << "mon triangle"<<t.id_Sommet1<<" "<<t.id_Sommet2<<" "<<t.id_Sommet3<<endl;

    }*/
    for(int i=0;i<racine-1;i++)
        {   for(int j=(i+1)*racine-1;j<(i+2)*racine;j++)
            {
                Triangle t1,t2;
                t1.id_Triangle=j+1;
                t1.id_Sommet1=lesPoints[i].id_point;
                t1.id_Sommet2=lesPoints[i+1].id_point;
                t1.id_Sommet3=lesPoints[j].id_point;
                lesTriangles.push_back(t1);
                cout << "mon triangle"<<t1.id_Sommet1<<" "<<t1.id_Sommet2<<" "<<t1.id_Sommet3<<endl;
                t2.id_Triangle=j+1;
                t2.id_Sommet1=lesPoints[i+1].id_point;
                t2.id_Sommet2=lesPoints[j].id_point;
                t2.id_Sommet3=lesPoints[j+1].id_point;
                lesTriangles.push_back(t2);
                cout << "mon triangle"<<t2.id_Sommet1<<" "<<t2.id_Sommet2<<" "<<t2.id_Sommet3<<endl;
            }

        }

    cout<<"le nombre de triangles crées :"<<lesTriangles.size();
      /*for(int i=0;i<lesTriangles.size();i++)
      { cout<<"/******triangle "<<i<<endl;
        cout<<lesPoints[(lesTriangles[i].id_Sommet1)-1].getX()<<" "<<lesPoints[(lesTriangles[i].id_Sommet1)-1].getY()<<" "<<lesPoints[(lesTriangles[i].id_Sommet1)-1].getZ()<<endl;
        cout<<lesPoints[(lesTriangles[i].id_Sommet2)-1].getX()<<" "<<lesPoints[(lesTriangles[i].id_Sommet2)-1].getY()<<" "<<lesPoints[(lesTriangles[i].id_Sommet2)-1].getZ()<<endl;
       }*/

  }

