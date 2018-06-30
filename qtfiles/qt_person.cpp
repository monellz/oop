#include "qt_person.h"
#include "qt_config.h"
Person::Person(QString _name, QWidget *_central, QWidget *parent):Details(_central,parent,false)
{
    //object initial
    BaseStrategy* _strategy=Config::instance().getStrategy(parent,true);
    std::string str_name=_name.toStdString();
    obj=new PersonObject(str_name,_strategy);





    //image
    /*
    QDir dir("./images");
    if(!dir.exists()){
        qDebug() << "wrong dir" ;
    }
    */
    poster=new QLabel(parent);
    QImage image("/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/photos/0.jpg");
    QPixmap temppix=QPixmap::fromImage(image);
    temppix=temppix.scaled(300,380,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    poster->setPixmap(temppix);
    poster->resize(image.width(),image.height());

    moreimage=new QPushButton("more images",parent);
    moreintro=nullptr; //this is movie???????


    //input data(base class)
    inputdata();


    score=nullptr;


    //size and position(base class)
    pushlayout();
}
