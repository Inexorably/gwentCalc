/********************************************************************************
** Form generated from reading UI file 'deckeditorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECKEDITORWINDOW_H
#define UI_DECKEDITORWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeckEditorWindow
{
public:
    QAction *actionOpen_deck;
    QAction *actionSave_deck;
    QAction *actionSave_deck_as;
    QAction *actionNew_deck;
    QAction *actionSettings;
    QAction *actionReload_Card_List;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *cardSelectionLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *cardSelectionComboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *addPushButton;
    QPushButton *removePushButton;
    QTableWidget *deckTableWidget;
    QPushButton *spawnComboWindowButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSimulation;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DeckEditorWindow)
    {
        if (DeckEditorWindow->objectName().isEmpty())
            DeckEditorWindow->setObjectName(QString::fromUtf8("DeckEditorWindow"));
        DeckEditorWindow->resize(988, 453);
        QIcon icon;
        icon.addFile(QString::fromUtf8("gwentcalc.ico"), QSize(), QIcon::Normal, QIcon::Off);
        DeckEditorWindow->setWindowIcon(icon);
        actionOpen_deck = new QAction(DeckEditorWindow);
        actionOpen_deck->setObjectName(QString::fromUtf8("actionOpen_deck"));
        actionSave_deck = new QAction(DeckEditorWindow);
        actionSave_deck->setObjectName(QString::fromUtf8("actionSave_deck"));
        actionSave_deck_as = new QAction(DeckEditorWindow);
        actionSave_deck_as->setObjectName(QString::fromUtf8("actionSave_deck_as"));
        actionNew_deck = new QAction(DeckEditorWindow);
        actionNew_deck->setObjectName(QString::fromUtf8("actionNew_deck"));
        actionSettings = new QAction(DeckEditorWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionReload_Card_List = new QAction(DeckEditorWindow);
        actionReload_Card_List->setObjectName(QString::fromUtf8("actionReload_Card_List"));
        centralWidget = new QWidget(DeckEditorWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cardSelectionLineEdit = new QLineEdit(centralWidget);
        cardSelectionLineEdit->setObjectName(QString::fromUtf8("cardSelectionLineEdit"));

        gridLayout->addWidget(cardSelectionLineEdit, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cardSelectionComboBox = new QComboBox(centralWidget);
        cardSelectionComboBox->setObjectName(QString::fromUtf8("cardSelectionComboBox"));
        cardSelectionComboBox->setEnabled(true);
        cardSelectionComboBox->setMinimumSize(QSize(200, 0));
        cardSelectionComboBox->setEditable(false);

        horizontalLayout_2->addWidget(cardSelectionComboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addPushButton = new QPushButton(centralWidget);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        horizontalLayout->addWidget(addPushButton);

        removePushButton = new QPushButton(centralWidget);
        removePushButton->setObjectName(QString::fromUtf8("removePushButton"));

        horizontalLayout->addWidget(removePushButton);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        deckTableWidget = new QTableWidget(centralWidget);
        deckTableWidget->setObjectName(QString::fromUtf8("deckTableWidget"));
        deckTableWidget->setSortingEnabled(true);

        gridLayout->addWidget(deckTableWidget, 1, 0, 1, 2);

        spawnComboWindowButton = new QPushButton(centralWidget);
        spawnComboWindowButton->setObjectName(QString::fromUtf8("spawnComboWindowButton"));

        gridLayout->addWidget(spawnComboWindowButton, 2, 0, 1, 2);

        DeckEditorWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DeckEditorWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 988, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSimulation = new QMenu(menuBar);
        menuSimulation->setObjectName(QString::fromUtf8("menuSimulation"));
        DeckEditorWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DeckEditorWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DeckEditorWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DeckEditorWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DeckEditorWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSimulation->menuAction());
        menuFile->addAction(actionNew_deck);
        menuFile->addAction(actionOpen_deck);
        menuFile->addAction(actionSave_deck);
        menuFile->addAction(actionSave_deck_as);
        menuSimulation->addAction(actionSettings);

        retranslateUi(DeckEditorWindow);

        QMetaObject::connectSlotsByName(DeckEditorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DeckEditorWindow)
    {
        DeckEditorWindow->setWindowTitle(QApplication::translate("DeckEditorWindow", "DeckEditorWindow", nullptr));
        actionOpen_deck->setText(QApplication::translate("DeckEditorWindow", "Open deck...", nullptr));
        actionSave_deck->setText(QApplication::translate("DeckEditorWindow", "Save deck...", nullptr));
        actionSave_deck_as->setText(QApplication::translate("DeckEditorWindow", "Save deck as...", nullptr));
        actionNew_deck->setText(QApplication::translate("DeckEditorWindow", "New deck...", nullptr));
        actionSettings->setText(QApplication::translate("DeckEditorWindow", "Settings", nullptr));
        actionReload_Card_List->setText(QApplication::translate("DeckEditorWindow", "Reload Card List", nullptr));
        addPushButton->setText(QApplication::translate("DeckEditorWindow", "Add", nullptr));
        removePushButton->setText(QApplication::translate("DeckEditorWindow", "Remove", nullptr));
        spawnComboWindowButton->setText(QApplication::translate("DeckEditorWindow", "Combo Editor", nullptr));
        menuFile->setTitle(QApplication::translate("DeckEditorWindow", "File", nullptr));
        menuSimulation->setTitle(QApplication::translate("DeckEditorWindow", "Simulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeckEditorWindow: public Ui_DeckEditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECKEDITORWINDOW_H
