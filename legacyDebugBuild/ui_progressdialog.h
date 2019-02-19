/********************************************************************************
** Form generated from reading UI file 'progressdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSDIALOG_H
#define UI_PROGRESSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ProgressDialog
{
public:
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QPushButton *pushButton;

    void setupUi(QDialog *ProgressDialog)
    {
        if (ProgressDialog->objectName().isEmpty())
            ProgressDialog->setObjectName(QString::fromUtf8("ProgressDialog"));
        ProgressDialog->resize(311, 118);
        gridLayout = new QGridLayout(ProgressDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        progressBar = new QProgressBar(ProgressDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 0, 0, 1, 1);

        pushButton = new QPushButton(ProgressDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);


        retranslateUi(ProgressDialog);

        QMetaObject::connectSlotsByName(ProgressDialog);
    } // setupUi

    void retranslateUi(QDialog *ProgressDialog)
    {
        ProgressDialog->setWindowTitle(QApplication::translate("ProgressDialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("ProgressDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgressDialog: public Ui_ProgressDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSDIALOG_H
