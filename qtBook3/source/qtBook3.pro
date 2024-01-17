QT += gui
QT += sql
QT += widgets
INCLUDEPATH +=  D:/Qt6/6.5.3/mingw_64/include
CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# to sovle mysql unconnection problems  2024.1.6
# TARGET = qsqlmysql
# HEADERS += $$PWD/qsql_mysql_p.h
# SOURCES += $$PWD/qsql_mysql.cpp $$PWD/main.cpp
# OTHER_FILES += mysql.json

# 这个变量包含了所有的源文件（.cpp 文件）。这些文件包含了项目的主要代码。
SOURCES += \
    addbookwindow.cpp \
    cardwindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp

# 这个变量包含了所有的头文件（.h 文件）。这些文件通常包含类的声明和函数的原型。
HEADERS += \
    addbookwindow.h \
    cardwindow.h \
    connection.h \
    loginwindow.h \
    mainwindow.h
# 这个变量包含了所有的用户界面文件（.ui 文件）。这些文件是用 Qt Designer 创建的，包含了用户界面的布局和元素。
FORMS += \
    addbookwindow.ui \
    cardwindow.ui \
    loginwindow.ui \
    mainwindow.ui

# qnx: 是一个条件，表示只有在目标平台是 QNX 时，这行代码才会被执行。
# QNX 是一个商业的、实时的、嵌入式的操作系统，主要用于嵌入式系统中。它由加拿大的 QNX Software Systems（现在是黑莓公司的一部分）开发。
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

