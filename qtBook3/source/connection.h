#ifndef CONNECTION_H // 防止头文件重复包含
#define CONNECTION_H
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>


/*
编译器发出这个警告是为了提醒你，这个函数可能是无用的，你可能忘记了在某个地方调用它，
或者你可能不再需要这个函数.你可以添加一个编译器指令来禁止这个警告。
这个指令的具体形式取决于你的编译器

static bool __attribute__((unused)) createConnection () {
    // ...
}
*/


/*
static bool createConnection () {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    // 这句是构造函数就是这样写的，具体看 Qt Doc
    db.setHostName("127.0.0.1");//localhost
    db.setPort(3306);           //默认端口
    db.setDatabaseName("demo_data"); //用户自建数据库名称
    db.setUserName("root");     //用户名
    db.setPassword("123456");   //数据库的密码
    
    // 如下代码用于检测数据库是否连接成功
    bool ok = db.open();
    if (ok){
        QMessageBox::information(nullptr, "infor", "success");
    }
    else {
        QMessageBox::information(nullptr, "infor", "open failed");
    }
    return true;
}
#endif // CONNECTION_H
*/

/*
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    // 需要改成自己的用户名和密码
    db.setUserName("postgres");
    db.setPassword("123456");
    if (db.open()) {
    QMessageBox::information(this, "infor", "success");
    } else {
    QMessageBox::information(this, "infor", "open failed");
    }
*/


/*
static bool createConnection () {
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    // 这句是构造函数就是这样写的，具体看 Qt Doc
    db.setHostName("127.0.0.1");//localhost
    db.setPort(5432);           //默认端口
    db.setDatabaseName("demo_data"); //用户自建数据库名称
    db.setUserName("root");     //用户名
    db.setPassword("123456");   //数据库的密码
    
    // 如下代码用于检测数据库是否连接成功
    bool ok = db.open();
    if (ok){
        QMessageBox::information(nullptr, "infor", "success");
    }
    else {
        QMessageBox::information(nullptr, "infor", "open failed");
    }
    return true;
}
#endif // CONNECTION_H
*/

// 使用Qt自带的sqlite数据库
static bool createConnection () {
    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connection_name"); // 创建一个 QSqlDatabase 对象 db
    //db.setHostName("127.0.0.1");//localhost
    //db.setPort(5432);           //默认端口
    //db.setDatabaseName("qtBook.sqlite3"); //用户自建数据库名称
    //db.setDatabaseName("E:/Qt6Proj/qtBook/qsqlite/qtBook.sqlite");  //sqlite3 数据库存储位置

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydatabase.db");
    db.setUserName("root");     //用户名
    db.setPassword("123456");   //数据库的密码
    
    
    // 如下代码用于检测数据库是否连接成功
    bool ok = db.open();
    if (ok){
        QMessageBox::information(nullptr, "infor", "success");
    }
    else {
        QMessageBox::information(nullptr, "infor", "open failed");
    }
    // return true;  定义为静态函数，返回值为bool类型
    return ok; //在这个例子中，ok 是一个 bool 变量，它的值取决于 db.open() 的执行结果。如果数据库连接成功，db.open() 将返回 true，否则返回 false。
}
#endif // CONNECTION_H 



/**************************
 * connection.h
 * this file is to define a database, eg: mysql, pgsql, sqlite
*******************************/

