/********************************************************************************
** Form generated from reading UI file 'progressdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSDIALOG_H
#define UI_PROGRESSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgressDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *messageLabel;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *ProgressDialog)
    {
        if (ProgressDialog->objectName().isEmpty())
            ProgressDialog->setObjectName(QStringLiteral("ProgressDialog"));
        ProgressDialog->resize(751, 409);
        gridLayoutWidget = new QWidget(ProgressDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(11, 11, 731, 301));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(ProgressDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 320, 731, 86));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        messageLabel = new QLabel(layoutWidget);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));

        verticalLayout->addWidget(messageLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(ProgressDialog);

        QMetaObject::connectSlotsByName(ProgressDialog);
    } // setupUi

    void retranslateUi(QDialog *ProgressDialog)
    {
        ProgressDialog->setWindowTitle(QApplication::translate("ProgressDialog", "Dialog", nullptr));
        messageLabel->setText(QApplication::translate("ProgressDialog", "Running Simulation...", nullptr));
        label->setText(QApplication::translate("ProgressDialog", "Iterations: 0", nullptr));
        pushButton->setText(QApplication::translate("ProgressDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgressDialog: public Ui_ProgressDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSDIALOG_H
