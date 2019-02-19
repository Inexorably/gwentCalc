/********************************************************************************
** Form generated from reading UI file 'deckeditorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
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
    QAction *actionDebug;
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
            DeckEditorWindow->setObjectName(QStringLiteral("DeckEditorWindow"));
        DeckEditorWindow->resize(988, 453);
        QIcon icon;
        icon.addFile(QStringLiteral("gwentcalc.ico"), QSize(), QIcon::Normal, QIcon::Off);
        DeckEditorWindow->setWindowIcon(icon);
        actionOpen_deck = new QAction(DeckEditorWindow);
        actionOpen_deck->setObjectName(QStringLiteral("actionOpen_deck"));
        actionSave_deck = new QAction(DeckEditorWindow);
        actionSave_deck->setObjectName(QStringLiteral("actionSave_deck"));
        actionSave_deck_as = new QAction(DeckEditorWindow);
        actionSave_deck_as->setObjectName(QStringLiteral("actionSave_deck_as"));
        actionNew_deck = new QAction(DeckEditorWindow);
        actionNew_deck->setObjectName(QStringLiteral("actionNew_deck"));
        actionSettings = new QAction(DeckEditorWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionReload_Card_List = new QAction(DeckEditorWindow);
        actionReload_Card_List->setObjectName(QStringLiteral("actionReload_Card_List"));
        actionDebug = new QAction(DeckEditorWindow);
        actionDebug->setObjectName(QStringLiteral("actionDebug"));
        centralWidget = new QWidget(DeckEditorWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cardSelectionLineEdit = new QLineEdit(centralWidget);
        cardSelectionLineEdit->setObjectName(QStringLiteral("cardSelectionLineEdit"));

        gridLayout->addWidget(cardSelectionLineEdit, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cardSelectionComboBox = new QComboBox(centralWidget);
        cardSelectionComboBox->setObjectName(QStringLiteral("cardSelectionComboBox"));
        cardSelectionComboBox->setEnabled(true);
        cardSelectionComboBox->setMinimumSize(QSize(200, 0));
        cardSelectionComboBox->setEditable(false);

        horizontalLayout_2->addWidget(cardSelectionComboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addPushButton = new QPushButton(centralWidget);
        addPushButton->setObjectName(QStringLiteral("addPushButton"));

        horizontalLayout->addWidget(addPushButton);

        removePushButton = new QPushButton(centralWidget);
        removePushButton->setObjectName(QStringLiteral("removePushButton"));

        horizontalLayout->addWidget(removePushButton);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        deckTableWidget = new QTableWidget(centralWidget);
        deckTableWidget->setObjectName(QStringLiteral("deckTableWidget"));
        deckTableWidget->setSortingEnabled(true);

        gridLayout->addWidget(deckTableWidget, 1, 0, 1, 2);

        spawnComboWindowButton = new QPushButton(centralWidget);
        spawnComboWindowButton->setObjectName(QStringLiteral("spawnComboWindowButton"));

        gridLayout->addWidget(spawnComboWindowButton, 2, 0, 1, 2);

        DeckEditorWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DeckEditorWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 988, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSimulation = new QMenu(menuBar);
        menuSimulation->setObjectName(QStringLiteral("menuSimulation"));
        DeckEditorWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DeckEditorWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DeckEditorWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DeckEditorWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DeckEditorWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSimulation->menuAction());
        menuFile->addAction(actionNew_deck);
        menuFile->addAction(actionOpen_deck);
        menuFile->addAction(actionSave_deck);
        menuFile->addAction(actionSave_deck_as);
        menuSimulation->addAction(actionSettings);
        menuSimulation->addAction(actionDebug);

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
        actionDebug->setText(QApplication::translate("DeckEditorWindow", "Debug", nullptr));
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
