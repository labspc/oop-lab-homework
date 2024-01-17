#include "mainwindow.h" // include the header of the main window 这通常是一个 Qt 窗口类的声明
#include "connection.h" // include the header of the database connection 一个数据库连接的相关代码
#include <QApplication> // include the header of the application 这是每个 Qt GUI 应用程序的基础
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // 创建一个 QApplication 对象。这个对象在 Qt GUI 应用程序中是必需的
    if(!createConnection()) {
        std::cout << "database open failed" << std::endl;
        return 0;
    }
    MainWindow w; // 创建一个 MainWindow 对象。这个对象是我们在 mainwindow.h 中声明的
    w.show(); // 调用 show() 函数来显示这个窗口
    return a.exec(); // 调用 exec() 函数来开始事件循环。事件循环是一个无限循环，它等待用户的输入，鼠标点击，窗口移动等等
}
