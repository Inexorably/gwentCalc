/********************************************************************************
** Form generated from reading UI file 'chartwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTWINDOW_H
#define UI_CHARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChartWindow)
    {
        if (ChartWindow->objectName().isEmpty())
            ChartWindow->setObjectName(QStringLiteral("ChartWindow"));
        ChartWindow->resize(800, 600);
        centralwidget = new QWidget(ChartWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);

        ChartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChartWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        ChartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChartWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ChartWindow->setStatusBar(statusbar);

        retranslateUi(ChartWindow);

        QMetaObject::connectSlotsByName(ChartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChartWindow)
    {
        ChartWindow->setWindowTitle(QApplication::translate("ChartWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("ChartWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChartWindow: public Ui_ChartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTWINDOW_H
