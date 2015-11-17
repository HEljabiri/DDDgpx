#ifndef RANDONNEUR_H
#define RANDONNEUR_H
#include <QGLViewer/qglviewer.h>
#include "Point.h"

class Randonneur
{
public:
    Randonneur();
    void init();
    void draw();
    void bouge();
    std::vector<Point> randonnee;
     qglviewer::Vec speed_, pos_;

   private :

     int age_, ageMax_;
     double pasX;
     double pasY;
     double pasZ;


     int i;
};

#endif // RANDONNEUR_H
