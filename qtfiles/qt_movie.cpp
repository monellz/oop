#include "qt_movie.h"
#include <QDebug>
#include <QDir>
#include "qt_config.h"
#include "ObjRanking/MovieObject.h"
#include <string>
Movie::Movie(QString _name, QWidget *_central, QWidget *parent):Details(_central,parent,true)
{
    //object initial
    BaseStrategy* _strategy=Config::instance().getStrategy(parent);
    std::string str_name=_name.toStdString();
    obj=new MovieObject(str_name,_strategy);





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
    moreintro=nullptr; //this is movie


    //input data(base class)
    inputdata();

    //intial score if has
    if(isScore){
        score=Config::instance().getScoreWidget(window);
         //score need obj info and init
    }
    else score=nullptr;


    //size and position(base class)
    pushlayout();
}

Movie::~Movie(){

}
