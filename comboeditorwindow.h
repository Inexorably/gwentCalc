#ifndef COMBOEDITORWINDOW_H
#define COMBOEDITORWINDOW_H

#include "globals.h"

#include <QDialog>
#include <QMainWindow>
#include <QToolBar>



//#include "deckeditorwindow.h"
//This is included in the source cpp file to prevent cross reference problems with the include guards.

namespace Ui {
class ComboEditorWindow;
}

class ComboEditorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ComboEditorWindow(QWidget *parent = nullptr);
    ComboEditorWindow(std::vector<QString> deck, QString filename, QWidget *parent = nullptr);
    ~ComboEditorWindow();

private slots:

    void on_addComboButton_clicked();

    void on_removeComboButton_clicked();

    void on_doubleSpinBox_editingFinished();

private:
    Ui::ComboEditorWindow *ui;
};

#endif // COMBOEDITORWINDOW_H
