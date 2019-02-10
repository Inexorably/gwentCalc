#include "comboeditorwindow.h"
#include "ui_comboeditorwindow.h"

#include <QDebug>

ComboEditorWindow::ComboEditorWindow(std::vector<QString> deck, QString passedFilename, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ComboEditorWindow)
{
    ui->setupUi(this);

    //On startup, add the cards in the deck currently to the comboBox.
    for (size_t i = 0; i < deck.size(); ++i){
        ui->comboCardSelectionComboBox->addItem(deck[i]);
    }

    this->setWindowTitle(COMBOWINDOWTITLE + passedFilename);
    filename = passedFilename;
    filename.chop(4);   //Remove the extension from the filename.
    ui->valueTableWidget->setColumnCount(1);
    ui->valueTableWidget->setRowCount(1);

    //The user needs to be able to click the first cell to add a card.
    ui->comboTableWidget->setRowCount(1);
    ui->comboTableWidget->setColumnCount(1);

    //Set the card combo table widget to stretch.
    ui->comboTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //If the filetype (last 4 chars) of the passedFilename variable is .gwc, then we can load information based on that gwc file.
    if (passedFilename.right(4) == ".gwc"){
        QString data;
        QFile infile(passedFilename);
        QStringList fileList;

        if (infile.open(QFile::ReadOnly)){
            data = infile.readAll();
            fileList = data.split("\n");
            infile.close();
        }

        //Order (see save function) is combo, value, deck.
        importCsvToTable(*ui->comboTableWidget, fileList[0]);
        importCsvToTable(*ui->valueTableWidget, fileList[1]);
    }
}


ComboEditorWindow::ComboEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ComboEditorWindow)
{
    ui->setupUi(this);

}

ComboEditorWindow::~ComboEditorWindow(){
    delete ui;
}

void ComboEditorWindow::on_addComboButton_clicked(){
    //Get the current index of the selected cell.
    QModelIndexList indexList = ui->comboTableWidget->selectionModel()->selectedIndexes();
    int row = 0;
    int col = 0;
    if (indexList.empty())
        return;
    foreach(QModelIndex index, indexList){
        row = index.row();
        col = index.column();
        break;  //bigThonkers use of foreach and break right here.
    }

    //If the selected cell is of the bottom row, we add a row below it.
    if (row == ui->comboTableWidget->rowCount() - 1){
        ui->comboTableWidget->setRowCount(ui->comboTableWidget->rowCount() + 1);
    }

    //If the selected cell is the leftmost cell and there are preceeding empty cells, change col to the first empty col.
    for (int i = 0; i < ui->comboTableWidget->columnCount(); ++i){
        QTableWidgetItem* item = ui->comboTableWidget->item(row, i);
        if (!item || item->text().isEmpty()){
            col = i;
            break;
        }
    }


    //If the selected cell is the leftmost cell in its row, add a cell to the right of it.
    if (col == ui->comboTableWidget->columnCount() - 1){
        ui->comboTableWidget->setColumnCount(ui->comboTableWidget->columnCount() + 1);
    }

    //We now add the selected card (combo box) to the selected cell.
    ui->comboTableWidget->setItem(row, col, new QTableWidgetItem(ui->comboCardSelectionComboBox->currentText()));

    //Update number of rows in provision value.
    ui->valueTableWidget->setRowCount(ui->comboTableWidget->rowCount());
}

void ComboEditorWindow::on_removeComboButton_clicked(){
    //Get the current index of the selected cells.  We delete all selected cells, then we loop through and shift right and up all empty cells.
    QModelIndexList indexList = ui->comboTableWidget->selectionModel()->selectedIndexes();
    if (indexList.empty())
        return;
    foreach(QModelIndex index, indexList){
        ui->comboTableWidget->setItem(index.row(), index.column(), new QTableWidgetItem(""));
    }

    //Very lazy implementation coming.  Can improve by shifting and removing while adjusting indexList to account for shifts in the foreach loop above.
    //Loop through left to right and top to bottom.  When an empty cell is encountered, check if any more cells on the row are nonempty.
        //If there is a non empty cell to the right, copy the contents to the current empty cell and delete the right side cell.  Then, continue looping from the current location.
        //If there is only empty cells remaining, check if all cells in the current row are empty.  If so, delete the current row, and do not increment row var.  Reset col to 0 and continue looping.
    for (int row = 0; row < ui->comboTableWidget->rowCount(); ++row){
        //If this is still true after we have looped through the entire row (all columns), we need to delete the row.
        bool emptyRow = true;
        for (int col = 0; col < ui->comboTableWidget->columnCount(); ++col){
            //Get the current item, accounting for null or empty possibilities with pointer.
            QTableWidgetItem* item = ui->comboTableWidget->item(row, col);
            if (!item || item->text().isEmpty()){
                //We have encountered an empty cell.  Now check if cells to the right are nonempty.
                for (int tempCol = col + 1; tempCol < ui->comboTableWidget->columnCount(); ++tempCol){
                    QTableWidgetItem* tempItem = ui->comboTableWidget->item(row, tempCol);
                    //We can't check the text of the item member if it is null (segfault), so we need to skip null items.
                    if (tempItem && !tempItem->text().isEmpty()){
                        //There is a non-empty cell to the right of the current cell.
                        //Copy the contents to the cell at row, col, and then delete this cell at row, tempCol.  Then break.
                        ui->comboTableWidget->setItem(row, col, new QTableWidgetItem(tempItem->text()));
                        ui->comboTableWidget->setItem(row, tempCol, new QTableWidgetItem(""));
                        break;
                    }
                }
            }
            else {
                emptyRow = false;
            }
        }
        //If the row is empty, remove it and decrement row so that we can go through the row that replaced the deleted row at the same index.
        //There is an edge case where selecting column 0 items will cause the row to be deleted even with items in it.  This is countered by this item check.
        QTableWidgetItem* item = ui->comboTableWidget->item(row, 0);
        if (emptyRow && row + 1 != ui->comboTableWidget->rowCount() && (!item || item->text().isEmpty())){
            ui->comboTableWidget->removeRow(row);

            //We also remove the corresponding row in the value table.
            ui->valueTableWidget->removeRow(row);
            --row;
        }
    }

    //Check if there are leftover empty columns now.
    for (int col = 0; col < ui->comboTableWidget->columnCount(); ++col){
        bool emptyCol = true;
        for (int row = 0; row < ui->comboTableWidget->rowCount(); ++row){
            QTableWidgetItem* item = ui->comboTableWidget->item(row, col);
            if (!(!item || item->text().isEmpty())){
                emptyCol = false;
            }
        }
        if (emptyCol && col + 1 != ui->comboTableWidget->columnCount()){
            ui->comboTableWidget->removeColumn(col);
            --col;
        }
    }

    //Delete the bottom member of the combo values.
    ui->valueTableWidget->setItem(ui->valueTableWidget->rowCount()-1, 0, new QTableWidgetItem(""));
}

void ComboEditorWindow::on_doubleSpinBox_editingFinished(){
    //Set the selected cell in the value tab to the spinbox value.
    //Get the current index of the selected cell.
    QModelIndexList indexList = ui->valueTableWidget->selectionModel()->selectedIndexes();
    int row = 0;
    int col = 0;
    if (indexList.empty())
        return;
    foreach(QModelIndex index, indexList){
        row = index.row();
        col = index.column();
        break;  //bigThonkers use of foreach and break right here.
    }

    //The bottom row is empty.  If this is the bottom row, return.
    if (ui->valueTableWidget->rowCount() == row + 1){
        return;
    }

    ui->valueTableWidget->setItem(row, col, new QTableWidgetItem(QString::number(ui->doubleSpinBox->value())));


}

void ComboEditorWindow::on_actionSave_triggered(){
    //We need to save the combo table and the value table.
    //The current filename is stored in the member variable "filename".  This does not include the file extension.
    //Save the combo table first, then the value table.
    exportTableToCsv(*ui->comboTableWidget, filename+EXTENSIONCOMBO);
    exportTableToCsv(*ui->valueTableWidget, filename+EXTENSIONVALUE);

    QString textData = filename+EXTENSIONCOMBO + "\n" + filename+EXTENSIONVALUE + "\n" + filename+EXTENSIONDECK;

    //Write to the .gwc file which tracks all files.
    QFile outfile(filename+EXTENSIONSET);
    if(outfile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&outfile);
        out << textData;

        outfile.close();
    }

    //Update the working title to the .gwc.
    this->setWindowTitle(COMBOWINDOWTITLE + filename + EXTENSIONSET);
}

void ComboEditorWindow::on_actionSave_as_triggered(){
    //We choose a new name for the file set, and then do the same as the on_actionSave_triggered() function.
    //Do the file prompt for selecting a name.
    //Get the filename.
    QString saveasName = QFileDialog::getSaveFileName(this, tr("GWC file"), qApp->applicationDirPath (),tr("GWC File (*.gwc)"));
    //We chop the file extension of of filename now.
    saveasName.chop(4);
    //We need to save the deck (.csv) file with the new name.  Old name is currently in filename member, and new name is saveasName.
    QFile::copy(filename+EXTENSIONDECK, saveasName+EXTENSIONDECK);

    //Now we can just paste from the save function.
    filename = saveasName;
    //Copy the other files from the ui widgets.
    exportTableToCsv(*ui->comboTableWidget, filename+EXTENSIONCOMBO);
    exportTableToCsv(*ui->valueTableWidget, filename+EXTENSIONVALUE);

    QString textData = filename+EXTENSIONCOMBO + "\n" + filename+EXTENSIONVALUE + "\n" + filename+EXTENSIONDECK;

    //Write to the .gwc file which tracks all files.
    QFile outfile(filename+EXTENSIONSET);
    if(outfile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&outfile);
        out << textData;

        outfile.close();
    }

    //Update the working title to the .gwc.
    this->setWindowTitle(COMBOWINDOWTITLE + filename + EXTENSIONSET);
}

void ComboEditorWindow::on_actionOpen_triggered(){
    //We need to load the .gwc file, and then import the filenames from it to import the needed information.

    //Get the filename.
    QString openName = QFileDialog::getOpenFileName(this, tr("GWC file"), qApp->applicationDirPath (),tr("GWC File (*.gwc)"));

    QString data;
    QFile infile(openName);
    QStringList fileList;

    if (infile.open(QFile::ReadOnly)){
        data = infile.readAll();
        fileList = data.split("\n");
        infile.close();
    }

    //Order (see save function) is combo, value, deck.
    importCsvToTable(*ui->comboTableWidget, fileList[0]);
    importCsvToTable(*ui->valueTableWidget, fileList[1]);

}
