#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>
#include <QtCharts>

#include <vector>

#include "gwentcard.h"
#include "gwentcardcombo.h"
#include "simthread.h"
#include "gwentscenario.h"

//Note: This class will run simulations based on gwentcalc.set and passed decks / combos upon initalization in a worker thread.

namespace Ui {
class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgressDialog(const QString &f, const std::vector<GwentCard> &deckTemp, const std::vector<GwentCardCombo> &combosTemp, QWidget *parent = nullptr);
    ~ProgressDialog();

    std::vector<GwentCard> deck;
    std::vector<GwentCardCombo> combos;
    const QString filename;

private slots:
    void on_pushButton_clicked();

private:
    Ui::ProgressDialog *ui;
    SimThread *sim;

};

#endif // PROGRESSDIALOG_H
