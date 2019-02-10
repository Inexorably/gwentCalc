#include "comboeditorwindow.h"
#include "ui_comboeditorwindow.h"

#include <QDebug>

ComboEditorWindow::ComboEditorWindow(std::vector<QString> deck, QString filename, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComboEditorWindow)
{
    ui->setupUi(this);

    //On startup, add the cards in the deck currently to the comboBox.
    for (size_t i = 0; i < deck.size(); ++i){
        ui->comboCardSelectionComboBox->addItem(deck[i]);
    }

    this->setWindowTitle(COMBOWINDOWTITLE + filename);
}


ComboEditorWindow::ComboEditorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComboEditorWindow)
{
    ui->setupUi(this);

}

ComboEditorWindow::~ComboEditorWindow()
{
    delete ui;
}
