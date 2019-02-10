#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    //Set the title.
    this->setWindowTitle("Settings");
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_cancelButton_clicked(){
    close();
}
