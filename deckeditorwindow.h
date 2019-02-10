#ifndef DECKEDITORWINDOW_H
#define DECKEDITORWINDOW_H

#include <QMainWindow>
#include <QString>

#include "comboeditorwindow.h"
#include "utilities.h"
#include "globals.h"

#include <vector>

namespace Ui {
class DeckEditorWindow;
}

class DeckEditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeckEditorWindow(QWidget *parent = nullptr);
    ~DeckEditorWindow();

    //Get the contents of deck in QString.
    std::vector<QString> getDeck() const;

private slots:
    void on_spawnComboWindowButton_clicked();

    void on_cardSelectionLineEdit_editingFinished();

    void on_addPushButton_clicked();

    void on_removePushButton_clicked();

    void on_actionSave_deck_as_triggered();

    void on_actionOpen_deck_triggered();

    void on_actionSave_deck_triggered();

    void on_actionNew_deck_triggered();

private:
    Ui::DeckEditorWindow *ui;
};

#endif // DECKEDITORWINDOW_H
