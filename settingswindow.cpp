#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    //Disable resize.
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    //Set the title.
    this->setWindowTitle("Settings");

    //Settings are seperated by newlines.
    /*bool multithread default 1
     *bool run n iterations default 0
     *int n iterations default 1000
     *bool run until error default 1
     *double error default 1
    */
    QString data;
    QFile infile(SETTINGSFILENAME);
    QStringList settingsList;

    if (infile.open(QFile::ReadOnly)){
        data = infile.readAll();
        settingsList = data.split("\n");
        //qDebug() << "Settings length: " << settingsList.size();
        //qDebug() << settingsList[9];
        infile.close();
    }
    else {
        qDebug() << "SettingsWindow::SettingsWindow(QWidget *parent) : File not found";
    }

    //Load the settings in the settingsList.
    ui->multithreadCheckBox->setChecked(static_cast<bool>(settingsList[0].toInt()));
    ui->nIterationsCheckBox->setChecked(static_cast<bool>(settingsList[1].toInt()));
    ui->nIterationsSpinBox->setValue(settingsList[2].toInt());
    ui->percentCheckBox->setChecked(static_cast<bool>(settingsList[3].toInt()));
    ui->percentSpinBox->setValue(settingsList[4].toDouble());
    ui->r1SpinBox->setValue(settingsList[5].toInt());
    ui->r2SpinBox->setValue(settingsList[6].toInt());
    ui->r3SpinBox->setValue(16-settingsList[5].toInt()-settingsList[6].toInt());
    ui->varyRoundCheckBox->setChecked(static_cast<bool>(settingsList[7].toInt()));
    ui->varyRoundSpinBox->setValue(settingsList[8].toInt());
    ui->closeParentWindowCheckBox->setChecked(static_cast<bool>(settingsList[9].toInt()));
    ui->bloodThirst1SpinBox->setValue(settingsList[10].toDouble());
    qDebug() << "a";
    ui->bloodThirst2SpinBox->setValue(settingsList[11].toDouble());
    qDebug() << "b";
    ui->bloodThirst3SpinBox->setValue(settingsList[12].toDouble());
    qDebug() << "c";
    //Note that blood thirst zero probability is dependant on the other blood thirst values (100 - all other values, we are in % not decimal).
    ui->bloodThirst0SpinBox->setValue(100.0-settingsList[10].toDouble()-settingsList[11].toDouble()-settingsList[12].toDouble());

    //Enable / disable interdependant widgets such as nIterations / percent.
    ui->nIterationsSpinBox->setEnabled(ui->nIterationsCheckBox->isChecked());
    ui->percentSpinBox->setEnabled(ui->percentCheckBox->isChecked());
    ui->varyRoundSpinBox->setEnabled(ui->varyRoundCheckBox->isChecked());
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_cancelButton_clicked(){
    close();
}

void SettingsWindow::on_okButton_clicked(){
    QFile outSettings(SETTINGSFILENAME);
    //Settings are seperated by newlines.
    /*bool multithread default 1
     *bool run n iterations default 0
     *int n iterations default 5000
     *bool run until error default 1
     *double error default 1
    */
    QString settings;
    settings += QString::number(static_cast<int>(ui->multithreadCheckBox->isChecked()))+"\n";
    settings += QString::number(static_cast<int>(ui->nIterationsCheckBox->isChecked()))+"\n";
    settings += QString::number(ui->nIterationsSpinBox->value())+"\n";
    settings += QString::number(static_cast<int>(ui->percentCheckBox->isChecked()))+"\n";
    settings += QString::number(ui->percentSpinBox->value())+"\n";
    settings += QString::number(ui->r1SpinBox->value())+"\n";
    settings += QString::number(ui->r2SpinBox->value())+"\n";
    settings += QString::number(static_cast<int>(ui->varyRoundCheckBox->isChecked()))+"\n";
    settings += QString::number(ui->varyRoundSpinBox->value())+"\n";
    settings += QString::number(static_cast<int>(ui->closeParentWindowCheckBox->isChecked()))+"\n";
    settings += QString::number(ui->bloodThirst1SpinBox->value())+"\n";
    settings += QString::number(ui->bloodThirst2SpinBox->value())+"\n";
    settings += QString::number(ui->bloodThirst3SpinBox->value());


    if(outSettings.open(QIODevice::WriteOnly | QIODevice::Truncate)){
        QTextStream out(&outSettings);
        out << settings;
        outSettings.close();
    }
    close();
}

void SettingsWindow::on_nIterationsCheckBox_clicked(){
    //If this box is now true, we set the percent box to false, disable the percent spin box, and enable the iterations spin box.
    if (ui->nIterationsCheckBox->isChecked()){
        ui->percentCheckBox->setChecked(false);
        ui->percentSpinBox->setEnabled(false);
        ui->nIterationsSpinBox->setEnabled(true);
    }
    else{
        //If this box is now false, set the nIterationsSpinBox to false and enable the percent widgets.
        ui->percentCheckBox->setChecked(true);
        ui->percentSpinBox->setEnabled(true);
        ui->nIterationsSpinBox->setEnabled(false);
    }
}

void SettingsWindow::on_percentCheckBox_clicked(){
    if (ui->percentCheckBox->isChecked()){
        ui->nIterationsCheckBox->setChecked(false);
        ui->percentSpinBox->setEnabled(true);
        ui->nIterationsSpinBox->setEnabled(false);
    }
    else{
        ui->nIterationsCheckBox->setChecked(true);
        ui->percentSpinBox->setEnabled(false);
        ui->nIterationsSpinBox->setEnabled(true);
    }
}

void SettingsWindow::on_r1SpinBox_valueChanged(int arg1){
    ui->r3SpinBox->setValue(16-ui->r2SpinBox->value()-arg1);
}

void SettingsWindow::on_r2SpinBox_valueChanged(int arg1){
    ui->r3SpinBox->setValue(16-ui->r1SpinBox->value()-arg1);
}

void SettingsWindow::on_varyRoundCheckBox_clicked(){
    ui->varyRoundSpinBox->setEnabled(ui->varyRoundCheckBox->isChecked());
}

//Whenever a damaged enemy distribution spin box is changed, modify the bloodThirst0SpinBox such that the sum of all values is 100.0.
//Also can set maximum / minimum value in the case that there is not enough variance in the 0 spin box to allow and == 100.0 sum.
void SettingsWindow::on_bloodThirst1SpinBox_valueChanged(double arg1){
    //Silence unused variable warning.
    (void)arg1;

    ui->bloodThirst0SpinBox->setValue(100.0-ui->bloodThirst1SpinBox->value()-ui->bloodThirst2SpinBox->value()-ui->bloodThirst3SpinBox->value());
    //Set the maximum and minimums of each box to current+-bloodThirstSpinBox0->value.
    //Set minimums.
    //This gets stuck when 0SpinBox == 0.
    ///*
    if (ui->bloodThirst1SpinBox->value()+ui->bloodThirst0SpinBox->value() < 100){
        ui->bloodThirst1SpinBox->setMaximum(ui->bloodThirst1SpinBox->value()+ui->bloodThirst0SpinBox->value());
    }
    else{
        ui->bloodThirst1SpinBox->setMaximum(100);
    }
    if (ui->bloodThirst2SpinBox->value()+ui->bloodThirst0SpinBox->value() < 100){
        ui->bloodThirst2SpinBox->setMaximum(ui->bloodThirst2SpinBox->value()+ui->bloodThirst0SpinBox->value());
    }
    else{
        ui->bloodThirst2SpinBox->setMaximum(100);
    }
    if (ui->bloodThirst3SpinBox->value()+ui->bloodThirst0SpinBox->value() < 100){
        ui->bloodThirst3SpinBox->setMaximum(ui->bloodThirst3SpinBox->value()+ui->bloodThirst0SpinBox->value());
    }
    else{
        ui->bloodThirst3SpinBox->setMaximum(100);
    }
    /*
    if (ui->bloodThirst1SpinBox->value()-ui->bloodThirst0SpinBox->value() > 0){
        ui->bloodThirst1SpinBox->setMinimum(ui->bloodThirst1SpinBox->value()-ui->bloodThirst0SpinBox->value());
    }
    else{
        ui->bloodThirst1SpinBox->setMinimum(0);
    }
    if (ui->bloodThirst2SpinBox->value()-ui->bloodThirst0SpinBox->value() > 0){
        ui->bloodThirst2SpinBox->setMinimum(ui->bloodThirst2SpinBox->value()-ui->bloodThirst0SpinBox->value());
    }
    else{
        ui->bloodThirst2SpinBox->setMinimum(0);
    }
    if (ui->bloodThirst3SpinBox->value()-ui->bloodThirst0SpinBox->value() > 0){
        ui->bloodThirst3SpinBox->setMinimum(ui->bloodThirst3SpinBox->value()-ui->bloodThirst0SpinBox->value());
    }
    else{
        ui->bloodThirst3SpinBox->setMinimum(0);
    }
    */
}

void SettingsWindow::on_bloodThirst2SpinBox_valueChanged(double arg1){
    //Silence unused variable warning.
    (void)arg1;

    ui->bloodThirst0SpinBox->setValue(100.0-ui->bloodThirst1SpinBox->value()-ui->bloodThirst2SpinBox->value()-ui->bloodThirst3SpinBox->value());
    //Set the maximum and minimums of each box to current+-bloodThirstSpinBox0->value.
    //Set minimums.
    //This gets stuck when 0SpinBox == 0.
    ///*
    if (ui->bloodThirst1SpinBox->value()+ui->bloodThirst0SpinBox->value() < 100){
        ui->bloodThirst1SpinBox->setMaximum(ui->bloodThirst1SpinBox->value()+ui->bloodThirst0SpinBox->value());
    }
    else{
        ui->bloodThirst1SpinBox->setMaximum(100);
    }
    if (ui->bloodThirst2SpinBox->value()+ui->bloodThirst0SpinBox->value() < 100){
        ui->bloodThirst2SpinBox->setMaximum(ui->bloodThirst2SpinBox->value()+ui->bloodThirst0SpinBox->value());
    }
    else{
        ui->bloodThirst2SpinBox->setMaximum(100);
    }
    if (ui->bloodThirst3SpinBox->value()+ui->bloodThirst0SpinBox->value() < 100){
        ui->bloodThirst3SpinBox->setMaximum(ui->bloodThirst3SpinBox->value()+ui->bloodThirst0SpinBox->value());
    }
    else{
        ui->bloodThirst3SpinBox->setMaximum(100);
    }
}

void SettingsWindow::on_bloodThirst3SpinBox_valueChanged(double arg1){
    //Silence unused variable warning.
    (void)arg1;

    ui->bloodThirst0SpinBox->setValue(100.0-ui->bloodThirst1SpinBox->value()-ui->bloodThirst2SpinBox->value()-ui->bloodThirst3SpinBox->value());
    //Set the maximum and minimums of each box to current+-bloodThirstSpinBox0->value.
    //Set minimums.
    //This gets stuck when 0SpinBox == 0.
    ///*
    if (ui->bloodThirst1SpinBox->value()+ui->bloodThirst0SpinBox->value() < 100){
        ui->bloodThirst1SpinBox->setMaximum(ui->bloodThirst1SpinBox->value()+ui->bloodThirst0SpinBox->value());
    }
    else{
        ui->bloodThirst1SpinBox->setMaximum(100);
    }
    if (ui->bloodThirst2SpinBox->value()+ui->bloodThirst0SpinBox->value() < 100){
        ui->bloodThirst2SpinBox->setMaximum(ui->bloodThirst2SpinBox->value()+ui->bloodThirst0SpinBox->value());
    }
    else{
        ui->bloodThirst2SpinBox->setMaximum(100);
    }
    if (ui->bloodThirst3SpinBox->value()+ui->bloodThirst0SpinBox->value() < 100){
        ui->bloodThirst3SpinBox->setMaximum(ui->bloodThirst3SpinBox->value()+ui->bloodThirst0SpinBox->value());
    }
    else{
        ui->bloodThirst3SpinBox->setMaximum(100);
    }
}
