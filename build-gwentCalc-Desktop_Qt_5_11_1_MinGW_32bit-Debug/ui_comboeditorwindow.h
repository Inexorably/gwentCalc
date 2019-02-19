/********************************************************************************
** Form generated from reading UI file 'comboeditorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
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
    QLabel *label;
    QTableWidget *damagedTableWidget;
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
    QTableWidget *valuePerTurnTableWidget;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuRun;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ComboEditorWindow)
    {
        if (ComboEditorWindow->objectName().isEmpty())
            ComboEditorWindow->setObjectName(QStringLiteral("ComboEditorWindow"));
        ComboEditorWindow->resize(1132, 694);
        actionOpen = new QAction(ComboEditorWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(ComboEditorWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(ComboEditorWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionNew = new QAction(ComboEditorWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionRun = new QAction(ComboEditorWindow);
        actionRun->setObjectName(QStringLiteral("actionRun"));
        actionSettings = new QAction(ComboEditorWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        centralwidget = new QWidget(ComboEditorWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 3, 1, 1);

        damagedTableWidget = new QTableWidget(centralwidget);
        damagedTableWidget->setObjectName(QStringLiteral("damagedTableWidget"));
        damagedTableWidget->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(damagedTableWidget, 1, 3, 1, 1);

        comboTableWidget = new QTableWidget(centralwidget);
        comboTableWidget->setObjectName(QStringLiteral("comboTableWidget"));

        gridLayout->addWidget(comboTableWidget, 1, 0, 1, 1);

        valueTableWidget = new QTableWidget(centralwidget);
        valueTableWidget->setObjectName(QStringLiteral("valueTableWidget"));
        valueTableWidget->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(valueTableWidget, 1, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        comboValueLabel = new QLabel(centralwidget);
        comboValueLabel->setObjectName(QStringLiteral("comboValueLabel"));

        gridLayout->addWidget(comboValueLabel, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cardSelectionLineEdit = new QLineEdit(centralwidget);
        cardSelectionLineEdit->setObjectName(QStringLiteral("cardSelectionLineEdit"));

        horizontalLayout_3->addWidget(cardSelectionLineEdit);

        comboCardSelectionComboBox = new QComboBox(centralwidget);
        comboCardSelectionComboBox->setObjectName(QStringLiteral("comboCardSelectionComboBox"));
        comboCardSelectionComboBox->setMinimumSize(QSize(230, 0));

        horizontalLayout_3->addWidget(comboCardSelectionComboBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        addComboButton = new QPushButton(centralwidget);
        addComboButton->setObjectName(QStringLiteral("addComboButton"));

        horizontalLayout_2->addWidget(addComboButton);

        removeComboButton = new QPushButton(centralwidget);
        removeComboButton->setObjectName(QStringLiteral("removeComboButton"));

        horizontalLayout_2->addWidget(removeComboButton);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 4);

        valuePerTurnTableWidget = new QTableWidget(centralwidget);
        valuePerTurnTableWidget->setObjectName(QStringLiteral("valuePerTurnTableWidget"));
        valuePerTurnTableWidget->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(valuePerTurnTableWidget, 1, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        ComboEditorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ComboEditorWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1132, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuRun = new QMenu(menubar);
        menuRun->setObjectName(QStringLiteral("menuRun"));
        ComboEditorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ComboEditorWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
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
        label->setText(QApplication::translate("ComboEditorWindow", "Value per # damaged enemies", nullptr));
        label_3->setText(QApplication::translate("ComboEditorWindow", "Combo Pieces", nullptr));
        comboValueLabel->setText(QApplication::translate("ComboEditorWindow", "Base Value", nullptr));
        addComboButton->setText(QApplication::translate("ComboEditorWindow", "Add", nullptr));
        removeComboButton->setText(QApplication::translate("ComboEditorWindow", "Remove", nullptr));
        label_2->setText(QApplication::translate("ComboEditorWindow", "Value per turn", nullptr));
        menuFile->setTitle(QApplication::translate("ComboEditorWindow", "File", nullptr));
        menuRun->setTitle(QApplication::translate("ComboEditorWindow", "Simulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComboEditorWindow: public Ui_ComboEditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBOEDITORWINDOW_H
