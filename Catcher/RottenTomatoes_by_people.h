//
// Created by lenovo on 2018/5/29.
//

#ifndef MICP_ROTTENTOMATOES_BY_PEOPLE_H
#define MICP_ROTTENTOMATOES_BY_PEOPLE_H
#include "BaseCatcher.h"
//类的具体含义详见Catcher说明文档
//函数的功能如BaseCatcher中的说明所述
class RottenTomatoes_by_people:public BaseCatcher{
public:
    RottenTomatoes_by_people(){}
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    std::ifstream SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_ROTTENTOMATOES_BY_PEOPLE_H
