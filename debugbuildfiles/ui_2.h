/********************************************************************************
** Form generated from reading UI file '2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_2_H
#define UI_2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>

QT_BEGIN_NAMESPACE

class Ui_ComboEditorWindow
{
public:
    QMenuBar *menuBar;
    QMenu *menut;

    void setupUi(QMainWindow *ComboEditorWindow)
    {
        if (ComboEditorWindow->objectName().isEmpty())
            ComboEditorWindow->setObjectName(QString::fromUtf8("ComboEditorWindow"));
        ComboEditorWindow->setEnabled(true);
        ComboEditorWindow->resize(675, 388);
        QIcon icon;
        icon.addFile(QString::fromUtf8("gwentcalc.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ComboEditorWindow->setWindowIcon(icon);
        menuBar = new QMenuBar(ComboEditorWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 675, 20));
        menut = new QMenu(menuBar);
        menut->setObjectName(QString::fromUtf8("menut"));
        ComboEditorWindow->setMenuBar(menuBar);

        menuBar->addAction(menut->menuAction());

        retranslateUi(ComboEditorWindow);

        QMetaObject::connectSlotsByName(ComboEditorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ComboEditorWindow)
    {
        ComboEditorWindow->setWindowTitle(QApplication::translate("ComboEditorWindow", "Dialog", nullptr));
        menut->setTitle(QApplication::translate("ComboEditorWindow", "t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComboEditorWindow: public Ui_ComboEditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_2_H
