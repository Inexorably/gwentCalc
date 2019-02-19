/********************************************************************************
** Form generated from reading UI file 'analysiswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISWINDOW_H
#define UI_ANALYSISWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnalysisWindow
{
public:
    QAction *actionScore_vs_Round_Length;
    QAction *actionScore_per_Card_vs_Round_Length;
    QAction *combosTimesPlayed;
    QAction *actionAverage_Combo_Value;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *scoreLabel;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AnalysisWindow)
    {
        if (AnalysisWindow->objectName().isEmpty())
            AnalysisWindow->setObjectName(QStringLiteral("AnalysisWindow"));
        AnalysisWindow->resize(1121, 755);
        actionScore_vs_Round_Length = new QAction(AnalysisWindow);
        actionScore_vs_Round_Length->setObjectName(QStringLiteral("actionScore_vs_Round_Length"));
        actionScore_vs_Round_Length->setCheckable(true);
        actionScore_vs_Round_Length->setChecked(true);
        actionScore_per_Card_vs_Round_Length = new QAction(AnalysisWindow);
        actionScore_per_Card_vs_Round_Length->setObjectName(QStringLiteral("actionScore_per_Card_vs_Round_Length"));
        actionScore_per_Card_vs_Round_Length->setCheckable(true);
        actionScore_per_Card_vs_Round_Length->setChecked(true);
        combosTimesPlayed = new QAction(AnalysisWindow);
        combosTimesPlayed->setObjectName(QStringLiteral("combosTimesPlayed"));
        combosTimesPlayed->setCheckable(true);
        combosTimesPlayed->setChecked(true);
        actionAverage_Combo_Value = new QAction(AnalysisWindow);
        actionAverage_Combo_Value->setObjectName(QStringLiteral("actionAverage_Combo_Value"));
        actionAverage_Combo_Value->setCheckable(true);
        actionAverage_Combo_Value->setChecked(true);
        centralwidget = new QWidget(AnalysisWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(140, 20));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        scoreLabel = new QLabel(centralwidget);
        scoreLabel->setObjectName(QStringLiteral("scoreLabel"));

        gridLayout_2->addWidget(scoreLabel, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 2);

        AnalysisWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AnalysisWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1121, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        AnalysisWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AnalysisWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AnalysisWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menuView->addAction(actionScore_vs_Round_Length);
        menuView->addAction(actionScore_per_Card_vs_Round_Length);
        menuView->addAction(combosTimesPlayed);
        menuView->addAction(actionAverage_Combo_Value);

        retranslateUi(AnalysisWindow);

        QMetaObject::connectSlotsByName(AnalysisWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AnalysisWindow)
    {
        AnalysisWindow->setWindowTitle(QApplication::translate("AnalysisWindow", "MainWindow", nullptr));
        actionScore_vs_Round_Length->setText(QApplication::translate("AnalysisWindow", "Score vs Round Length", nullptr));
        actionScore_per_Card_vs_Round_Length->setText(QApplication::translate("AnalysisWindow", "Score per Card vs Round Length", nullptr));
        combosTimesPlayed->setText(QApplication::translate("AnalysisWindow", "Combo Occurrences", nullptr));
        actionAverage_Combo_Value->setText(QApplication::translate("AnalysisWindow", "Average Combo Value", nullptr));
        label->setText(QApplication::translate("AnalysisWindow", "Overall Average Score:", nullptr));
        scoreLabel->setText(QApplication::translate("AnalysisWindow", "1", nullptr));
        menuFile->setTitle(QApplication::translate("AnalysisWindow", "File", nullptr));
        menuView->setTitle(QApplication::translate("AnalysisWindow", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnalysisWindow: public Ui_AnalysisWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISWINDOW_H
