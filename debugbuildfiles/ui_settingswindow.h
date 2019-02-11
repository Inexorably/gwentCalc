/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QWidget *settingsLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QCheckBox *multithreadCheckBox;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *nIterationsCheckBox;
    QSpinBox *nIterationsSpinBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *percentCheckBox;
    QDoubleSpinBox *percentSpinBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpinBox *r1SpinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpinBox *r2SpinBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSpinBox *r3SpinBox;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *varyRoundCheckBox;
    QSpinBox *varyRoundSpinBox;

    void setupUi(QDialog *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QString::fromUtf8("SettingsWindow"));
        SettingsWindow->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingsWindow->sizePolicy().hasHeightForWidth());
        SettingsWindow->setSizePolicy(sizePolicy);
        settingsLayoutWidget = new QWidget(SettingsWindow);
        settingsLayoutWidget->setObjectName(QString::fromUtf8("settingsLayoutWidget"));
        settingsLayoutWidget->setGeometry(QRect(210, 250, 168, 23));
        horizontalLayout_3 = new QHBoxLayout(settingsLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(settingsLayoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_3->addWidget(okButton);

        cancelButton = new QPushButton(settingsLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);

        widget = new QWidget(SettingsWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 31, 274, 211));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        multithreadCheckBox = new QCheckBox(widget);
        multithreadCheckBox->setObjectName(QString::fromUtf8("multithreadCheckBox"));
        multithreadCheckBox->setChecked(true);

        verticalLayout->addWidget(multithreadCheckBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        nIterationsCheckBox = new QCheckBox(widget);
        nIterationsCheckBox->setObjectName(QString::fromUtf8("nIterationsCheckBox"));

        horizontalLayout_2->addWidget(nIterationsCheckBox);

        nIterationsSpinBox = new QSpinBox(widget);
        nIterationsSpinBox->setObjectName(QString::fromUtf8("nIterationsSpinBox"));
        nIterationsSpinBox->setMinimum(1);
        nIterationsSpinBox->setMaximum(1000000000);
        nIterationsSpinBox->setSingleStep(1000);
        nIterationsSpinBox->setValue(1000);

        horizontalLayout_2->addWidget(nIterationsSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        percentCheckBox = new QCheckBox(widget);
        percentCheckBox->setObjectName(QString::fromUtf8("percentCheckBox"));
        percentCheckBox->setChecked(true);

        horizontalLayout->addWidget(percentCheckBox);

        percentSpinBox = new QDoubleSpinBox(widget);
        percentSpinBox->setObjectName(QString::fromUtf8("percentSpinBox"));
        percentSpinBox->setDecimals(4);
        percentSpinBox->setMaximum(100.000000000000000);
        percentSpinBox->setSingleStep(0.010000000000000);
        percentSpinBox->setValue(1.000000000000000);

        horizontalLayout->addWidget(percentSpinBox);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        r1SpinBox = new QSpinBox(widget);
        r1SpinBox->setObjectName(QString::fromUtf8("r1SpinBox"));
        r1SpinBox->setValue(6);

        horizontalLayout_4->addWidget(r1SpinBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        r2SpinBox = new QSpinBox(widget);
        r2SpinBox->setObjectName(QString::fromUtf8("r2SpinBox"));
        r2SpinBox->setValue(4);

        horizontalLayout_5->addWidget(r2SpinBox);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        r3SpinBox = new QSpinBox(widget);
        r3SpinBox->setObjectName(QString::fromUtf8("r3SpinBox"));
        r3SpinBox->setEnabled(false);
        r3SpinBox->setValue(6);

        horizontalLayout_6->addWidget(r3SpinBox);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        varyRoundCheckBox = new QCheckBox(widget);
        varyRoundCheckBox->setObjectName(QString::fromUtf8("varyRoundCheckBox"));
        varyRoundCheckBox->setChecked(true);

        horizontalLayout_7->addWidget(varyRoundCheckBox);

        varyRoundSpinBox = new QSpinBox(widget);
        varyRoundSpinBox->setObjectName(QString::fromUtf8("varyRoundSpinBox"));
        varyRoundSpinBox->setValue(3);

        horizontalLayout_7->addWidget(varyRoundSpinBox);


        verticalLayout_3->addLayout(horizontalLayout_7);


        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "Dialog", nullptr));
        okButton->setText(QApplication::translate("SettingsWindow", "OK", nullptr));
        cancelButton->setText(QApplication::translate("SettingsWindow", "Cancel", nullptr));
#ifndef QT_NO_TOOLTIP
        multithreadCheckBox->setToolTip(QApplication::translate("SettingsWindow", "<html><head/><body><p>When simulating multiple deck/combo sets (.gwc files) against each other, allow each set to have it's own worker thread.  May disable some real-time ui elements.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        multithreadCheckBox->setText(QApplication::translate("SettingsWindow", "Allow multithreading", nullptr));
        nIterationsCheckBox->setText(QApplication::translate("SettingsWindow", "Run n iterations:", nullptr));
        percentCheckBox->setText(QApplication::translate("SettingsWindow", "Run until error drops below n %: ", nullptr));
        label->setText(QApplication::translate("SettingsWindow", "Cards played round 1:", nullptr));
        label_2->setText(QApplication::translate("SettingsWindow", "Cards played round 2:", nullptr));
        label_3->setText(QApplication::translate("SettingsWindow", "Cards played round 3:", nullptr));
        varyRoundCheckBox->setText(QApplication::translate("SettingsWindow", "Vary round length amount:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
