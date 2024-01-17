#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>

LogInWindow::LogInWindow(QWidget *parent, bool *admin_on, int *admin_id) :
    QMainWindow(parent),
    _ui(new Ui::LogInWindow),
    _admin_on(admin_on),
    _admin_id(admin_id)
{
    _ui->setupUi(this);
    _model = new QSqlTableModel();
    _model->setTable("manage");
}

LogInWindow::~LogInWindow()
{
    delete _ui;
}



/**
 * @brief This slot function is called when the push button is clicked in the login window.
 * It retrieves the entered manager ID and password from line edits, and performs a database query
 * to check if the manager ID and password match. If the login is successful, it sets the admin flag
 * to true and closes the login window.
 * If the manager ID is incorrect, it displays an error message.
 * If the password is incorrect, it displays a critical error message.
 * @return void
 */
/*
void LogInWindow::on_pushButton_clicked()
{
    QString manager_id = _ui->lineEdit->text();
    QString password = _ui->lineEdit_2->text();

    //@brief The SQL query statement used to retrieve the password from the "manage" table based on the manager_id.
    QString query_statement = " select password"
                              " from manage"
                              " where manager_id = ";
    query_statement.append(manager_id);


    //Error: not positioned on a valid record
    //Solution: query.first() before query.value()
    QSqlQuery query;
    query.exec(query_statement);

    if (query.size() == 0) {
        QMessageBox::about(this,"登录失败","用户ID错误");
    }
    else {
        query.first();
        if(query.value(0).toString() != password) {
            QMessageBox::critical(this,"登录失败","密码错误");
        }
        else {
            QMessageBox::about(this,"登录成功","登录成功");
            *_admin_on = true;
            *_admin_id = manager_id.toInt();
            this->close();
        }
    }
}
*/

void LogInWindow::on_pushButton_clicked()
{
    QString manager_id = _ui->lineEdit->text();
    QString password = _ui->lineEdit_2->text();

    /* Solution veersion 1
    QString query_statement = " select password"
                              " from manage"
                              " where manager_id = ";
    query_statement.append(manager_id);

    QSqlQuery query;
    query.exec(query_statement);
    query.next();
*/
    // Solution version 2
    QSqlQuery query;
    query.exec("INSERT INTO manage (manage_id, password) "
               "VALUES (151219117, 202401)");
    query.next(); // 在查询之前去移动数据指针
//****这样写有一个弊端就是需要在源代码里面修改


    /*
     * 移动完数据指针就可以进行查询
     * query.size() == 0 >> 修改0为-1
     *  the result (number of rows returned),
     *  or -1 if the size cannot be determined
     *  经过测试 ==0，==-1 不影响程序运行，根据文档显示，改为-1比较标准。
    */
    if (query.size() == 0) {
        QMessageBox::about(this,"登录失败","用户ID错误");
    }
    else {
        //query.next();
        // query.value(1).toString()
        if(query.next()){
        //if(query.value(0).toString() != password) 这样的写法是导致error的根源所在
        // 数据指针停留在 query.exec() 在要做值比较的时候，并没有进行更新。
            query.value(0).toString() != password;
            QMessageBox::critical(this,"登录失败","密码错误");
        }
        else {
            QMessageBox::about(this,"登录成功","登录成功");
            *_admin_on = true;
            *_admin_id = manager_id.toInt();
            this->close();
        }
    }
}

void LogInWindow::on_pushButton_2_clicked()
{
    this->close();
}

