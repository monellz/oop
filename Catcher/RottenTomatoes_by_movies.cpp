#include "RottenTomatoes_by_movies.h"
void RottenTomatoes_by_movies::ExporttoDatabase() {

}
void RottenTomatoes_by_movies::MakeCatcher() {
    //该部分为使用C++中的python指针调用py工作
    //每个函数只有在PyImport_ImportModule时不同，每个去调用名称对应的xxx.py
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/monell/qtcode/InfoCS/Catcher')");
 

    pModule = PyImport_ImportModule("RottenTomatoes_by_movies");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream RottenTomatoes_by_movies::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/RottenTomatoes_by_movies.txt",std::ios::in);
    return readfile;
}
void RottenTomatoes_by_movies::SetBaseData() {

}
void RottenTomatoes_by_movies::SetParameter() {

}
