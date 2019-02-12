#include "progressdialog.h"
#include "ui_progressdialog.h"

ProgressDialog::ProgressDialog(const QString &f, const std::vector<GwentCard> &deckTemp, const std::vector<GwentCardCombo> &combosTemp, QWidget *parent) :
    QDialog(parent), filename(f),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("Running simulation: " + filename);
    ui->label->hide();
    ui->label->setAlignment(Qt::AlignCenter);

    deck = deckTemp;
    combos = combosTemp;

    GwentScenario pkg(deck, combos);

    //Begin worker thread for simulations.  Initalize, and then call start which calls run().
    sim = new SimThread(pkg);

    //Connect the signal for updating the progress bar to the signals emited by the thread.
    connect(sim, SIGNAL(percentChanged(int)), ui->progressBar, SLOT(setValue(int)));
    connect(sim, SIGNAL(pIterationsChanged(QString)), ui->label, SLOT(setText(QString)));

    //Connect other relevant signals.
    connect(sim, SIGNAL(hideProgressBar()), ui->progressBar, SLOT(hide()));
    connect(sim, SIGNAL(showLabel()), ui->label, SLOT(show()));



    //Call start() which calls run().
    sim->start();

    //Close on completion of sim.
    connect(sim, SIGNAL(simulationComplete()), this, SLOT(close()));
}

ProgressDialog::~ProgressDialog()
{
    delete ui;
}

void ProgressDialog::on_pushButton_clicked(){
    sim->stop();
    close();
}
