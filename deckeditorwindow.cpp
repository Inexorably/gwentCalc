#include "deckeditorwindow.h"
#include "ui_deckeditorwindow.h"

#include <QDebug>

std::vector<QString> DeckEditorWindow::getDeck() const{
    std::vector<QString> deck;
    for (int i = 0; i < ui->deckTableWidget->rowCount(); ++i){
        //qDebug() << ui->deckTableWidget->item(i, 1)->text();
        deck.push_back(ui->deckTableWidget->item(i, 1)->text());
    }
    //qDebug() << deck.size();
    return deck;
}

DeckEditorWindow::DeckEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeckEditorWindow){
    ui->setupUi(this);

    //*****************Base Widget Setup****************************

    //Set default text on QLineEdit object on search bar.
    ui->cardSelectionLineEdit->setPlaceholderText("Card Name");

    //Set up deck list table.
    ui->deckTableWidget->setColumnCount(2);
    ui->deckTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //We begin working with an untitled deck.
    currentDeckFilename = "untitled deck";
    this->setWindowTitle(DECKBUILDERWINDOWTITLE + currentDeckFilename);
}

DeckEditorWindow::~DeckEditorWindow()
{
    delete ui;
}

void DeckEditorWindow::on_spawnComboWindowButton_clicked(){
    this->hide();
    ComboEditorWindow comboEditor(this->getDeck(), currentDeckFilename);
    comboEditor.setModal(true);
    comboEditor.exec();
    this->show();
}

void DeckEditorWindow::on_cardSelectionLineEdit_editingFinished(){
    ui->cardSelectionComboBox->addItem("Old Speartip: Asleep");
    ui->cardSelectionComboBox->addItem("Behemoth");
    ui->cardSelectionComboBox->addItem("Obelisk the Tormenter");
}

void DeckEditorWindow::on_addPushButton_clicked(){
    //We first check if we can add anymore copies to the deck.
    QString name = ui->cardSelectionComboBox->currentText();
    bool alreadyInDeck = false;
    for (int i = 0; i < ui->deckTableWidget->rowCount(); ++i){
        if (ui->deckTableWidget->item(i, 1)->text() == name){
            alreadyInDeck = true;
            //There are either 1 or 2 copies of the card in the deck.
            if (ui->deckTableWidget->item(i, 0)->text().toInt() == 1){
                ui->deckTableWidget->setItem(i,0,new QTableWidgetItem("2"));
            }
            //Else do nothing as we can't have more than two copies in the deck.
        }
    }
    //If it wasn't in the deck already, we insert into the deck.
    if (!alreadyInDeck){
        ui->deckTableWidget->setRowCount(ui->deckTableWidget->rowCount()+1);
        ui->deckTableWidget->setItem(ui->deckTableWidget->rowCount()-1, 0, new QTableWidgetItem("1"));
        ui->deckTableWidget->setItem(ui->deckTableWidget->rowCount()-1, 1, new QTableWidgetItem(name));
    }
}

void DeckEditorWindow::on_removePushButton_clicked(){
    //Get row of selected item.
    QModelIndexList indexList = ui->deckTableWidget->selectionModel()->selectedIndexes();
    int row = 0;
    if (indexList.empty())
        return;
    foreach(QModelIndex index, indexList){
        row = index.row();
    }

    //If there are 2 we just change "2" to "1".
    if ("2" == ui->deckTableWidget->item(row, 0)->text()){
        ui->deckTableWidget->setItem(row, 0, new QTableWidgetItem("1"));
    }
    //If there is 1 we remove the row.
    else{
        ui->deckTableWidget->removeRow(row);
    }
}

void DeckEditorWindow::on_actionSave_deck_as_triggered(){
    //Get the filename.
    QString filename = QFileDialog::getSaveFileName(this, tr("CSV file"), qApp->applicationDirPath (),tr("CSV File (*.csv)"));
    exportTableToCsv(*ui->deckTableWidget, filename);
    this->setWindowTitle(DECKBUILDERWINDOWTITLE + filename);
    currentDeckFilename = filename;
}

void DeckEditorWindow::on_actionOpen_deck_triggered(){
    //Get the filename.
    QString filename = QFileDialog::getOpenFileName(this, tr("CSV file"), qApp->applicationDirPath (),tr("CSV File (*.csv)"));
    importCsvToTable(*ui->deckTableWidget, filename);
    this->setWindowTitle(DECKBUILDERWINDOWTITLE + filename);
    currentDeckFilename = filename;
}

void DeckEditorWindow::on_actionSave_deck_triggered(){
    if (currentDeckFilename.isEmpty()){
        QString filename = QFileDialog::getSaveFileName(this, tr("CSV file"), qApp->applicationDirPath (),tr("CSV File (*.csv)"));
        exportTableToCsv(*ui->deckTableWidget, filename);
        this->setWindowTitle(DECKBUILDERWINDOWTITLE + filename);
        currentDeckFilename = filename;
    }
    else
        exportTableToCsv(*ui->deckTableWidget, currentDeckFilename);
}
