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

    //**************Overall Average Score Label******************************************************
    ui->scoreLabel->setText(QString::number(r.score()));

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

    QChart *chartScoresVsTurns = new QChart();
    chartScoresVsTurns->addSeries(seriesroundOneScoresVsTurns);
    chartScoresVsTurns->addSeries(seriesroundTwoScoresVsTurns);
    chartScoresVsTurns->addSeries(seriesroundThreeScoresVsTurns);

    QValueAxis *axisYScoresVsTurns = new QValueAxis();
    axisYScoresVsTurns->setTitleText("Average Score");
    axisYScoresVsTurns->setLabelFormat("%i");
    axisYScoresVsTurns->setTickCount(10);
    axisYScoresVsTurns->setMinorTickCount(-1);
    chartScoresVsTurns->addAxis(axisYScoresVsTurns, Qt::AlignLeft);
    seriesroundOneScoresVsTurns->attachAxis(axisYScoresVsTurns);

    QValueAxis *axisXScoresVsTurns = new QValueAxis();
    axisXScoresVsTurns->setTitleText("Number of Turns");
    axisXScoresVsTurns->setLabelFormat("%g");
    axisXScoresVsTurns->setMinorTickCount(-1);
    chartScoresVsTurns->addAxis(axisXScoresVsTurns, Qt::AlignBottom);
    axisXScoresVsTurns->setMin(0);
    axisXScoresVsTurns->setMax(10);
    seriesroundOneScoresVsTurns->attachAxis(axisXScoresVsTurns);

    // Same formatting
    chartScoresVsTurns->setBackgroundVisible(false);
    chartScoresVsTurns->setMargins(QMargins(0,0,0,0));
    chartScoresVsTurns->layout()->setContentsMargins(0,0,0,0);
    chartScoresVsTurns->setPlotAreaBackgroundBrush(QBrush(Qt::white));
    chartScoresVsTurns->setPlotAreaBackgroundVisible(true);
    chartScoresVsTurns->setTitle("Score vs Round Length");
    chartViewScoresVsTurns = new QChartView(chartScoresVsTurns);
    chartViewScoresVsTurns->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout->addWidget(chartViewScoresVsTurns);

    //**************Average score per card vs num turns for each round****************************************
    QLineSeries *seriesroundOneScoresPerCardVsTurns = new QLineSeries();
    seriesroundOneScoresPerCardVsTurns->append(r.roundOneScoresPerCardVsTurns);
    seriesroundOneScoresPerCardVsTurns->setName("Round One");
    QLineSeries *seriesroundTwoScoresPerCardVsTurns = new QLineSeries();
    seriesroundTwoScoresPerCardVsTurns->append(r.roundTwoScoresPerCardVsTurns);
    seriesroundTwoScoresPerCardVsTurns->setName("Round Two");
    QLineSeries *seriesroundThreeScoresPerCardVsTurns = new QLineSeries();
    seriesroundThreeScoresPerCardVsTurns->append(r.roundThreeScoresPerCardVsTurns);
    seriesroundThreeScoresPerCardVsTurns->setName("Round Three");

    QChart *chartScoresPerCardVsTurns = new QChart();
    chartScoresPerCardVsTurns->addSeries(seriesroundOneScoresPerCardVsTurns);
    chartScoresPerCardVsTurns->addSeries(seriesroundTwoScoresPerCardVsTurns);
    chartScoresPerCardVsTurns->addSeries(seriesroundThreeScoresPerCardVsTurns);

    QValueAxis *axisYScoresPerCardVsTurns = new QValueAxis();
    axisYScoresPerCardVsTurns->setTitleText("Average Score per Card");
    axisYScoresPerCardVsTurns->setLabelFormat("%i");
    axisYScoresPerCardVsTurns->setTickCount(10);
    axisYScoresPerCardVsTurns->setMinorTickCount(-1);
    chartScoresPerCardVsTurns->addAxis(axisYScoresPerCardVsTurns, Qt::AlignLeft);
    seriesroundOneScoresPerCardVsTurns->attachAxis(axisYScoresPerCardVsTurns);

    QValueAxis *axisXScoresPerCardVsTurns = new QValueAxis();
    axisXScoresPerCardVsTurns->setTitleText("Number of Turns");
    axisXScoresPerCardVsTurns->setLabelFormat("%g");
    axisXScoresPerCardVsTurns->setMinorTickCount(-1);
    chartScoresPerCardVsTurns->addAxis(axisXScoresPerCardVsTurns, Qt::AlignBottom);
    seriesroundOneScoresPerCardVsTurns->attachAxis(axisXScoresPerCardVsTurns);

    // Same formatting
    chartScoresPerCardVsTurns->setBackgroundVisible(false);
    chartScoresPerCardVsTurns->setMargins(QMargins(0,0,0,0));
    chartScoresPerCardVsTurns->layout()->setContentsMargins(0,0,0,0);
    chartScoresPerCardVsTurns->setPlotAreaBackgroundBrush(QBrush(Qt::white));
    chartScoresPerCardVsTurns->setPlotAreaBackgroundVisible(true);
    chartScoresPerCardVsTurns->setTitle("Average Card Value vs Round Length");
    chartViewScoresPerCardVsTurns = new QChartView(chartScoresPerCardVsTurns);
    chartViewScoresPerCardVsTurns->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout->addWidget(chartViewScoresPerCardVsTurns);

    //***********************************Bar Chart - Times each combo was played*************************************
    QBarSet *setCombosTimesPlayed = new QBarSet("Combos");
    for (size_t i = 0; i < r.combos.size(); ++i){
        if (r.combos[i].cards.size() > 1)
            *setCombosTimesPlayed << r.combos[i].occurences;
    }
    QBarSeries *seriesCombosTimesPlayed = new QBarSeries();
    seriesCombosTimesPlayed->append(setCombosTimesPlayed);
    QChart *chartCombosTimesPlayed = new QChart();
    chartCombosTimesPlayed->addSeries(seriesCombosTimesPlayed);
    chartCombosTimesPlayed->setTitle("Combo Occurences (Times Played)");
    chartCombosTimesPlayed->setAnimationOptions(QChart::SeriesAnimations);
    chartCombosTimesPlayed->legend()->setVisible(false);
    QStringList categoriesCombosTimesPlayed;

    //Set the category names.
    for (size_t i = 0; i < r.combos.size(); ++i){
        if (r.combos[i].cards.size() > 1){
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
    }
    //qDebug() << seriesCombosTimesPlayed->count();
    QBarCategoryAxis *axisXCombosTimesPlayed = new QBarCategoryAxis();
    axisXCombosTimesPlayed->setTitleText("Cards in Combo");
    axisXCombosTimesPlayed->append(categoriesCombosTimesPlayed);
    chartCombosTimesPlayed->addAxis(axisXCombosTimesPlayed, Qt::AlignBottom);
    seriesCombosTimesPlayed->attachAxis(axisXCombosTimesPlayed);

    QValueAxis *axisYCombosTimesPlayed = new QValueAxis();
    axisYCombosTimesPlayed->setTitleText("Times Played");
    //axisYCombosTimesPlayed->setRange(0,15);
    chartCombosTimesPlayed->addAxis(axisYCombosTimesPlayed, Qt::AlignLeft);
    seriesCombosTimesPlayed->attachAxis(axisYCombosTimesPlayed);

    chartViewCombosTimesPlayed = new QChartView(chartCombosTimesPlayed);
    chartViewCombosTimesPlayed->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout->addWidget(chartViewCombosTimesPlayed);

    //***********************************Bar Chart - Average value of each combo***************************
    //Combo occurences / number of iterations * combo value.
    QBarSet *setCombosAverageValue = new QBarSet("Combos");
    for (size_t i = 0; i < r.combos.size(); ++i){
        if (r.combos[i].cards.size() > 1)
            *setCombosAverageValue << static_cast<double>(r.combos[i].occurences)*r.combos[i].unconditionalPoints/static_cast<double>(r.roundOneScores.count());
    }
    QBarSeries *seriesCombosAverageValue = new QBarSeries();
    seriesCombosAverageValue->append(setCombosAverageValue);
    QChart *chartCombosAverageValue = new QChart();
    chartCombosAverageValue->addSeries(seriesCombosAverageValue);
    chartCombosAverageValue->setTitle("Combo Relative Value");
    chartCombosAverageValue->setAnimationOptions(QChart::SeriesAnimations);
    chartCombosAverageValue->legend()->setVisible(false);
    QStringList categoriesCombosAverageValue;

    //Set the category names.
    for (size_t i = 0; i < r.combos.size(); ++i){
        if (r.combos[i].cards.size() > 1){
            //Loop through the cards in the combo, and create a QString containing the combo name.
            QString tempComboName;
            for (size_t j = 0; j < r.combos[i].cards.size(); ++j){
                tempComboName += r.combos[i].cards[j].name;
                if (j != r.combos[i].cards.size() - 1){
                    tempComboName += ", ";
                }
            }
            categoriesCombosAverageValue << tempComboName;
        }
    }
    //qDebug() << seriesCombosAverageValue->count();
    QBarCategoryAxis *axisXCombosAverageValue = new QBarCategoryAxis();
    axisXCombosAverageValue->setTitleText("Cards in Combo");
    axisXCombosAverageValue->append(categoriesCombosAverageValue);
    chartCombosAverageValue->addAxis(axisXCombosAverageValue, Qt::AlignBottom);
    seriesCombosAverageValue->attachAxis(axisXCombosAverageValue);

    QValueAxis *axisYCombosAverageValue = new QValueAxis();
    axisYCombosAverageValue->setTitleText("Times Played / # Simulations * Score");
    //axisYCombosAverageValue->setRange(0,15);
    chartCombosAverageValue->addAxis(axisYCombosAverageValue, Qt::AlignLeft);
    seriesCombosAverageValue->attachAxis(axisYCombosAverageValue);

    chartViewCombosAverageValue = new QChartView(chartCombosAverageValue);
    chartViewCombosAverageValue->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout->addWidget(chartViewCombosAverageValue);

}

AnalysisWindow::~AnalysisWindow()
{
    delete ui;
}

void AnalysisWindow::on_actionScore_vs_Round_Length_changed(){
    if (ui->actionScore_vs_Round_Length->isChecked())
        chartViewScoresVsTurns->show();
    else
        chartViewScoresVsTurns->hide();
}

void AnalysisWindow::on_actionScore_per_Card_vs_Round_Length_changed(){
    if (ui->actionScore_per_Card_vs_Round_Length->isChecked())
        chartViewScoresPerCardVsTurns->show();
    else
        chartViewScoresPerCardVsTurns->hide();
}

void AnalysisWindow::on_combosTimesPlayed_changed(){
    if (ui->combosTimesPlayed->isChecked())
        chartViewCombosTimesPlayed->show();
    else
        chartViewCombosTimesPlayed->hide();
}

void AnalysisWindow::on_actionAverage_Combo_Value_changed(){
    if (ui->actionAverage_Combo_Value->isChecked())
        chartViewCombosAverageValue->show();
    else
        chartViewCombosAverageValue->hide();
}
