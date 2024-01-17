## Hello

This is a big assignment for the oop-lab class. 

Yep! You know that, this project is a fork repo. Thank you for the reference provided by the project of [@Zhytou](https://github.com/Zhytou).


Currently the project is based on Qt Widget (6.5.3), SQLite3, and C++17. This is a good example for learning Visual and Message-driven programming.


## Intro

the file tree:

```
.
├── deploy/
│  └── qtBook3-slim/
│    ├── platforms/
│    ├── Qt6Core.dll
│    ├── Qt6Gui.dll
│    ├── Qt6Sql.dll
│    ├── Qt6Widgets.dll
│    └── qtBook3.exe
├── README.md
└── source/
  ├── .qmake.stash
  ├── addbookwindow.cpp
  ├── addbookwindow.h
  ├── addbookwindow.ui
  ├── cardwindow.cpp
  ├── cardwindow.h
  ├── cardwindow.ui
  ├── connection.h
  ├── loginwindow.cpp
  ├── loginwindow.h
  ├── loginwindow.ui
  ├── main.cpp
  ├── mainwindow.cpp
  ├── mainwindow.h
  ├── mainwindow.ui
  ├── Makefile
  ├── Makefile.Debug
  ├── Makefile.Release
  ├── qtBook3.pro
  ├── ui_addbookwindow.h
  ├── ui_cardwindow.h
  ├── ui_loginwindow.h
  └── ui_mainwindow.h

```
This project is a Qt project with the main source code files in the source directory.

The *.cpp and *.h files are C++ source and header files, and the *.ui files are Qt user interface files.

The Makefile, Makefile.Debug, and Makefile.Release files are Makefile files used to build the project.

The qtBook3.pro file is the Qt project file, which defines the project's build rules and source files. The .qmake.stash file is a temporary file for the Qt qmake tool.

Here is a more detailed explanation of each file:

deploy/qtBook3-slim/
This directory contains the compiled executable and Qt libraries for the project.
README.md
This file contains information about the project, such as its purpose and how to use it.
source/
This directory contains the source code for the project.
*.cpp and *.h files
These files contain the C++ source and header code for the project's classes and functions.
*.ui files
These files contain the Qt user interface code for the project's windows and dialogs.
Makefile, Makefile.Debug, and Makefile.Release files
These files are used to build the project for different build configurations.
qtBook3.pro file
This file is the Qt project file, which defines the project's build rules and source files.
.qmake.stash file
This file is a temporary file for the Qt qmake tool.

## End

Bye for the fall 2023 semester.
