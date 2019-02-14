#include "analysiswindow.h"
#include "ui_analysiswindow.h"

AnalysisWindow::AnalysisWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalysisWindow)
{
    ui->setupUi(this);
    qDebug() << "AnalysisWindow::AnalysisWindow(QWidget *parent): Constructor called without GwentSimResults argument.";

}

AnalysisWindow::AnalysisWindow(const QString &f, const GwentSimResults &r, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalysisWindow)
{
    ui->setupUi(this);
    filename = f;
    this->setWindowTitle("Results: " + filename);

    //***********************************************************************************
    //**************Post Processing / Plotting Section***********************************
    //***********************************************************************************
    //qDebug() << "AnalysisWindow::AnalysisWindow(const GwentSimResults &r, QWidget *parent): Entering Post Processing";

    //**************Average score vs num turns for each round****************************************
    QLineSeries *seriesroundOneScoresVsTurns = new QLineSeries();
    seriesroundOneScoresVsTurns->append(r.roundOneScoresVsTurns);
    seriesroundOneScoresVsTurns->setName("Round One");
    QLineSeries *seriesroundTwoScoresVsTurns = new QLineSeries();
    seriesroundTwoScoresVsTurns->append(r.roundTwoScoresVsTurns);
    seriesroundTwoScoresVsTurns->setName("Round Two");
    QLineSeries *seriesroundThreeScoresVsTurns = new QLineSeries();
    seriesroundThreeScoresVsTurns->append(r.roundThreeScoresVsTurns);
    seriesroundThreeScoresVsTurns->setName("Round Three");

    QChart *chart = new QChart();
    chart->addSeries(seriesroundOneScoresVsTurns);
    chart->addSeries(seriesroundTwoScoresVsTurns);
    chart->addSeries(seriesroundThreeScoresVsTurns);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Average Score");
    axisY->setLabelFormat("%i");
    axisY->setTickCount(10);
    axisY->setMinorTickCount(-1);
    chart->addAxis(axisY, Qt::AlignLeft);
    seriesroundOneScoresVsTurns->attachAxis(axisY);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Number of Turns");
    axisX->setLabelFormat("%g");
    axisX->setMinorTickCount(-1);
    chart->addAxis(axisX, Qt::AlignBottom);
    seriesroundOneScoresVsTurns->attachAxis(axisX);

    // Same formatting
    chart->setBackgroundVisible(false);
    chart->setMargins(QMargins(0,0,0,0));
    chart->layout()->setContentsMargins(0,0,0,0);
    chart->setPlotAreaBackgroundBrush(QBrush(Qt::white));
    chart->setPlotAreaBackgroundVisible(true);
    chart->setTitle("Score vs Round Length");
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout->addWidget(chartView);

    //***********************************Bar Chart - Times each combo was played*************************************
    QBarSet *setCombosTimesPlayed = new QBarSet("Combos");
    for (size_t i = 0; i < r.combos.size(); ++i){
        *setCombosTimesPlayed << r.combos[i].occurences;
    }
    QBarSeries *seriesCombosTimesPlayed = new QBarSeries();
    seriesCombosTimesPlayed->append(setCombosTimesPlayed);
    QChart *chartCombosTimesPlayed = new QChart();
    chartCombosTimesPlayed->addSeries(seriesCombosTimesPlayed);
    chartCombosTimesPlayed->setTitle("Combo Occurences (Times Played)");
    chartCombosTimesPlayed->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categoriesCombosTimesPlayed;

    //Set the category names.
    for (size_t i = 0; i < r.combos.size(); ++i){
        //Loop through the cards in the combo, and create a QString containing the combo name.
        QString tempComboName;
        for (size_t j = 0; j < r.combos[i].cards.size(); ++j){
            tempComboName += r.combos[i].cards[j].name;
            if (j != r.combos[i].cards.size() - 1){
                tempComboName += ", ";
            }
        }
        categoriesCombosTimesPlayed << tempComboName;
    }
    qDebug() << seriesCombosTimesPlayed->count();
    QBarCategoryAxis *axisXCombosTimesPlayed = new QBarCategoryAxis();
    axisXCombosTimesPlayed->append(categoriesCombosTimesPlayed);
    chartCombosTimesPlayed->addAxis(axisXCombosTimesPlayed, Qt::AlignBottom);
    seriesCombosTimesPlayed->attachAxis(axisXCombosTimesPlayed);

    QValueAxis *axisYCombosTimesPlayed = new QValueAxis();
    //axisYCombosTimesPlayed->setRange(0,15);
    chartCombosTimesPlayed->addAxis(axisYCombosTimesPlayed, Qt::AlignLeft);
    seriesCombosTimesPlayed->attachAxis(axisYCombosTimesPlayed);

    QChartView *chartViewCombosTimesPlayed = new QChartView(chartCombosTimesPlayed);
    chartViewCombosTimesPlayed->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout->addWidget(chartViewCombosTimesPlayed);

}

AnalysisWindow::~AnalysisWindow()
{
    delete ui;
}
