#ifndef COMBOEDITORWINDOW_H
#define COMBOEDITORWINDOW_H

#include "globals.h"
#include "utilities.h"

#include <QDialog>
#include <QMainWindow>
#include <QToolBar>



//#include "deckeditorwindow.h"
//This is included in the source cpp file to prevent cross reference problems with the include guards.

namespace Ui {
class ComboEditorWindow;
}

class ComboEditorWindow : public QMainWindow
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

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionOpen_triggered();

private:
    Ui::ComboEditorWindow *ui;

    QString filename;
};

#endif // COMBOEDITORWINDOW_H
