/********************************************************************************
** Form generated from reading UI file 'Tubing.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUBING_H
#define UI_TUBING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TubingClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TubingClass)
    {
        if (TubingClass->objectName().isEmpty())
            TubingClass->setObjectName(QStringLiteral("TubingClass"));
        TubingClass->resize(600, 400);
        menuBar = new QMenuBar(TubingClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TubingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TubingClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TubingClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TubingClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TubingClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TubingClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TubingClass->setStatusBar(statusBar);

        retranslateUi(TubingClass);

        QMetaObject::connectSlotsByName(TubingClass);
    } // setupUi

    void retranslateUi(QMainWindow *TubingClass)
    {
        TubingClass->setWindowTitle(QApplication::translate("TubingClass", "Tubing", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TubingClass: public Ui_TubingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUBING_H
