#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_gasdispenser_clicked()
{
    ui->status->setText("Dispensed Gas Masks");
    delay(5000);
    ui->status->setText("Nothing Much");
}


void MainWindow::on_hrclothdispenser_clicked()
{
    ui->status->setText("Dispensed HR Cloth");
    delay(5000);
    ui->status->setText("Nothing Much");
}


void MainWindow::on_kidispenser_clicked()
{
    ui->status->setText("Releasing KI");
    int rad= ui->label_2->text().toInt();
    int tox= ui->label_6->text().toInt();
    ui->label_29->setText(QString::number(ui->label_29->text().toInt()+3));
    for(int i=0;i<10;i++){
        int j=i/2;
        delay(500);
        ui->label_2->setText(QString::number(rad));
        if(ui->label_6->text().toInt()<100)
        ui->label_6->setText(QString::number(tox+j));
        if(rad>1)
            rad--;
    }
    ui->progressBar_4->setValue(ui->progressBar_4->value()-2);
    ui->label_29->setText(QString::number(ui->label_29->text().toInt()-3));
    delay(1000);
    ui->status->setText("Nothing Much");
}


void MainWindow::on_pbdispenser_clicked()
{
    ui->status->setText("Dispensed PB");
    delay(5000);
    ui->status->setText("Nothing Much");
}


void MainWindow::on_dtpadispenser_clicked()
{
    ui->status->setText("Releasing DTPA");
    int rad= ui->label_2->text().toInt();
    int tox= ui->label_6->text().toInt();
    int safety=ui->progressBar_4->value();
    ui->label_29->setText(QString::number(ui->label_29->text().toInt()+3));
    for(int i=0;i<20;i=i+2){
        int j=i/2;
        int k=i/3;
        delay(500);
        if(ui->label_2->text().toInt()>1)
            ui->label_2->setText(QString::number(rad-i));
        if(ui->label_6->text().toInt()<100)
            ui->label_6->setText(QString::number(tox+j));
        if(ui->progressBar_4->value()<100)
            ui->progressBar_4->setValue(safety+k);
    }
    ui->label_29->setText(QString::number(ui->label_29->text().toInt()-3));
    delay(1000);
    ui->status->setText("Nothing Much");
}


void MainWindow::on_neupogendispenser_clicked()
{
    ui->status->setText("Releasing Neupogen");
    int rad= ui->label_2->text().toInt();
    int tox= ui->label_6->text().toInt();
    int safety=ui->progressBar_4->value();
    ui->label_29->setText(QString::number(ui->label_29->text().toInt()+3));
    for(int i=0;i<15;i++){
        int j=i/4;
        int k=i/3;
        delay(100);
        if(ui->label_2->text().toInt()>1)
            ui->label_2->setText(QString::number(rad-i));
        if(ui->label_6->text().toInt()<100)
            ui->label_6->setText(QString::number(tox+j));
        if(ui->progressBar_4->value()<100)
            ui->progressBar_4->setValue(safety+k);
    }
    ui->label_29->setText(QString::number(ui->label_29->text().toInt()-3));
    delay(1000);
    ui->status->setText("Nothing Much");
}


void MainWindow::on_progressBar_4_valueChanged(int value)
{
    if(value<25){
        ui->label_4->setText("DEADLY");
    }
    else if(value<50){
        ui->label_4->setText("DANGEROUS");
    }
    else if(value<75){
        ui->label_4->setText("WARNING");
    }
    else if(value<100){
        ui->label_4->setText("SAFE");
    }
}


void MainWindow::on_progressBar_2_valueChanged(int value)
{

    if(value<25){
        ui->label_22->setText("FREEZING");
    }
    else if(value<50){
        ui->label_22->setText("NORMAL");
    }
    else if(value<75){
        ui->label_22->setText("WARM");
    }
    else if(value<100){
        ui->label_22->setText("DANGER HOT");
    }
}

void MainWindow::on_dial_valueChanged(int value)
{
    ui->progressBar_2->setValue(value);
    ui->label_29->setText(QString::number(100-value));
}


void MainWindow::on_radioButton_toggled(bool checked)
{

    int mw = ui->label_29->text().toInt();
    ui->label_29->setText("MEDIUM");
    if(checked){
        ui->progressBar_3->setValue(ui->dial_7->value()+ui->horizontalSlider->value()/2);
        ui->label_29->setText(QString::number(mw+20));
    }
    else{
        ui->progressBar_3->setValue(ui->progressBar_3->value()-20);
        ui->label_29->setText(QString::number(mw-20));
    }
}


void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    if(ui->radioButton->isChecked())
        ui->progressBar_3->setValue(ui->dial_7->value()+ui->horizontalSlider->value()/2);
}

void MainWindow::on_horizontalSlider_5_sliderMoved(int position)
{
    ui->progressBar->setValue(100-position);
}


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    ui->progressBar_3->setValue(50-value/3);
    ui->progressBar_2->setValue(70-value/2);
}


void MainWindow::on_dial_7_valueChanged(int value)
{
    if(ui->radioButton->isChecked()){
        ui->progressBar_3->setValue(value/2+ui->horizontalSlider->value()/2);
        ui->label_29->setText(QString::number(value/3+50));
    }
    else{
        ui->progressBar_3->setValue(value/2);
        ui->label_29->setText(QString::number(value/3+50));
    }
}


void MainWindow::on_progressBar_3_valueChanged(int value)
{

    if(value<25){
        ui->label_10->setText("DANGER");
    }
    else if(value<50){
        ui->label_10->setText("DIRTY");
    }
    else if(value<75){
        ui->label_10->setText("IMPURE");
    }
    else if(value<100){
        ui->label_10->setText("PURE");
    }
}


void MainWindow::on_dial_8_valueChanged(int value)
{
    ui->label_6->setText(QString::number(-value+ui->verticalSlider_2->value()/3+ui->verticalSlider_3->value()/3+ui->horizontalSlider_7->value()/3));
    if(ui->label_6->text().toInt()>100)
        ui->label_6->setText(QString::number(100));
    else if (ui->label_6->text().toInt()<0)
        ui->label_6->setText(QString::number(0));
    ui->label_29->setText(QString::number(value/3+50));
    if(value<25){
        ui->label_10->setText("DANGER");
    }
    else if(value<50){
        ui->label_10->setText("WARNING");
    }
    else if(value<75){
        ui->label_10->setText("IMPURE");
    }
    else if(value<100){
        ui->label_10->setText("PURE");
    }
}


void MainWindow::on_dial_9_sliderReleased()
{
    ui->label_2->setText(QString::number(100-ui->dial_9->value()));
    ui->label_29->setText(QString::number(ui->dial_9->value()));
    ui->label_6->setText(QString::number(ui->dial_9->value()*3/4));
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label_2->setText(QString::number(150));
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->label_6->setText(QString::number(70));
}


void MainWindow::on_pushButton_clicked()
{
    ui->progressBar_3->setValue(20);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->label_29->setText("150");
}


void MainWindow::on_horizontalSlider_7_valueChanged(int value)
{
    ui->label_6->setText(QString::number(-ui->dial_8->value()+ui->verticalSlider_2->value()/3+ui->verticalSlider_3->value()/3+ui->horizontalSlider_7->value()/3));
    if(ui->label_6->text().toInt()>100)
        ui->label_6->setText(QString::number(100));
    else if (ui->label_6->text().toInt()<0)
        ui->label_6->setText(QString::number(0));
}


void MainWindow::on_verticalSlider_2_valueChanged(int value)
{
    ui->label_6->setText(QString::number(-ui->dial_8->value()+ui->verticalSlider_2->value()/3+ui->verticalSlider_3->value()/3+ui->horizontalSlider_7->value()/3));
    if(ui->label_6->text().toInt()>100)
        ui->label_6->setText(QString::number(100));
    else if (ui->label_6->text().toInt()<0)
        ui->label_6->setText(QString::number(0));

}


void MainWindow::on_verticalSlider_3_valueChanged(int value)
{

    ui->label_6->setText(QString::number(-ui->dial_8->value()+ui->verticalSlider_2->value()/3+ui->verticalSlider_3->value()/3+ui->horizontalSlider_7->value()/3));
    if(ui->label_6->text().toInt()>100)
        ui->label_6->setText(QString::number(100));
    else if (ui->label_6->text().toInt()<0)
        ui->label_6->setText(QString::number(0));
}


void MainWindow::on_horizontalSlider_9_valueChanged(int value)
{
    ui->progressBar_3->setValue(100-value);

}


void MainWindow::on_horizontalSlider_8_valueChanged(int value)
{

    if(value<25){
        ui->label_12->setText("QUIET");
    }
    else if(value<50){
        ui->label_12->setText("NORMAL");
    }
    else if(value<75){
        ui->label_12->setText("LOUD");
    }
    else if(value<100){
        ui->label_12->setText("DANGER");
    }

}


void MainWindow::on_horizontalSlider_10_valueChanged(int value)
{
    ui->label_6->setText(QString::number(value));
}


void MainWindow::on_verticalSlider_4_valueChanged(int value)
{
    ui->label_29->setText(QString::number(ui->verticalSlider_4->value()+ui->verticalSlider_3->value()/2-ui->horizontalSlider_6->value()/10+ui->horizontalSlider_3->value()/20));
    if(ui->label_29->text().toInt()>100)
        ui->label_29->setText(QString::number(100));
    else if (ui->label_29->text().toInt()<0)
        ui->label_29->setText(QString::number(0));
}


void MainWindow::on_verticalSlider_5_valueChanged(int value)
{
    ui->label_29->setText(QString::number(ui->verticalSlider_4->value()+ui->verticalSlider_3->value()/2-ui->horizontalSlider_6->value()/10+ui->horizontalSlider_3->value()/20));
    if(ui->label_29->text().toInt()>100)
        ui->label_29->setText(QString::number(100));
    else if (ui->label_29->text().toInt()<0)
        ui->label_29->setText(QString::number(0));
}


void MainWindow::on_horizontalSlider_6_valueChanged(int value)
{

    ui->label_29->setText(QString::number(ui->verticalSlider_4->value()+ui->verticalSlider_3->value()/2-ui->horizontalSlider_6->value()/10+ui->horizontalSlider_3->value()/20));
    if(ui->label_29->text().toInt()>100)
        ui->label_29->setText(QString::number(100));
    else if (ui->label_29->text().toInt()<0)
        ui->label_29->setText(QString::number(0));
}


void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{

    ui->label_29->setText(QString::number(ui->verticalSlider_4->value()+ui->verticalSlider_3->value()/2-ui->horizontalSlider_6->value()/10+ui->horizontalSlider_3->value()/20));
    if(ui->label_29->text().toInt()>100)
        ui->label_29->setText(QString::number(100));
    else if (ui->label_29->text().toInt()<0)
        ui->label_29->setText(QString::number(0));
}

