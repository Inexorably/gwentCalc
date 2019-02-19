/********************************************************************************
** Form generated from reading UI file 'comboeditorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMBOEDITORWINDOW_H
#define UI_COMBOEDITORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComboEditorWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionNew;
    QAction *actionRun;
    QAction *actionSettings;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableWidget *comboTableWidget;
    QTableWidget *valueTableWidget;
    QLabel *label_3;
    QLabel *comboValueLabel;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *cardSelectionLineEdit;
    QComboBox *comboCardSelectionComboBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addComboButton;
    QPushButton *removeComboButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuRun;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ComboEditorWindow)
    {
        if (ComboEditorWindow->objectName().isEmpty())
            ComboEditorWindow->setObjectName(QString::fromUtf8("ComboEditorWindow"));
        ComboEditorWindow->resize(917, 555);
        actionOpen = new QAction(ComboEditorWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(ComboEditorWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(ComboEditorWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionNew = new QAction(ComboEditorWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionRun = new QAction(ComboEditorWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        actionSettings = new QAction(ComboEditorWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        centralwidget = new QWidget(ComboEditorWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboTableWidget = new QTableWidget(centralwidget);
        comboTableWidget->setObjectName(QString::fromUtf8("comboTableWidget"));

        gridLayout->addWidget(comboTableWidget, 1, 0, 1, 1);

        valueTableWidget = new QTableWidget(centralwidget);
        valueTableWidget->setObjectName(QString::fromUtf8("valueTableWidget"));
        valueTableWidget->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(valueTableWidget, 1, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        comboValueLabel = new QLabel(centralwidget);
        comboValueLabel->setObjectName(QString::fromUtf8("comboValueLabel"));

        gridLayout->addWidget(comboValueLabel, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cardSelectionLineEdit = new QLineEdit(centralwidget);
        cardSelectionLineEdit->setObjectName(QString::fromUtf8("cardSelectionLineEdit"));

        horizontalLayout_3->addWidget(cardSelectionLineEdit);

        comboCardSelectionComboBox = new QComboBox(centralwidget);
        comboCardSelectionComboBox->setObjectName(QString::fromUtf8("comboCardSelectionComboBox"));
        comboCardSelectionComboBox->setMinimumSize(QSize(230, 0));

        horizontalLayout_3->addWidget(comboCardSelectionComboBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        addComboButton = new QPushButton(centralwidget);
        addComboButton->setObjectName(QString::fromUtf8("addComboButton"));

        horizontalLayout_2->addWidget(addComboButton);

        removeComboButton = new QPushButton(centralwidget);
        removeComboButton->setObjectName(QString::fromUtf8("removeComboButton"));

        horizontalLayout_2->addWidget(removeComboButton);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 2);

        ComboEditorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ComboEditorWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 917, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuRun = new QMenu(menubar);
        menuRun->setObjectName(QString::fromUtf8("menuRun"));
        ComboEditorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ComboEditorWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ComboEditorWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuRun->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuRun->addSeparator();
        menuRun->addAction(actionRun);
        menuRun->addAction(actionSettings);

        retranslateUi(ComboEditorWindow);

        QMetaObject::connectSlotsByName(ComboEditorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ComboEditorWindow)
    {
        ComboEditorWindow->setWindowTitle(QApplication::translate("ComboEditorWindow", "MainWindow", nullptr));
        actionOpen->setText(QApplication::translate("ComboEditorWindow", "Open...", nullptr));
        actionSave->setText(QApplication::translate("ComboEditorWindow", "Save...", nullptr));
        actionSave_as->setText(QApplication::translate("ComboEditorWindow", "Save as...", nullptr));
        actionNew->setText(QApplication::translate("ComboEditorWindow", "New...", nullptr));
        actionRun->setText(QApplication::translate("ComboEditorWindow", "Run", nullptr));
        actionSettings->setText(QApplication::translate("ComboEditorWindow", "Settings", nullptr));
        label_3->setText(QApplication::translate("ComboEditorWindow", "Combo Pieces", nullptr));
        comboValueLabel->setText(QApplication::translate("ComboEditorWindow", "Unconditional Combo Value", nullptr));
        addComboButton->setText(QApplication::translate("ComboEditorWindow", "Add", nullptr));
        removeComboButton->setText(QApplication::translate("ComboEditorWindow", "Remove", nullptr));
        menuFile->setTitle(QApplication::translate("ComboEditorWindow", "File", nullptr));
        menuRun->setTitle(QApplication::translate("ComboEditorWindow", "Simulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComboEditorWindow: public Ui_ComboEditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBOEDITORWINDOW_H
