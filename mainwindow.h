#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_gasdispenser_clicked();

    void on_hrclothdispenser_clicked();

    void on_kidispenser_clicked();

    void on_pbdispenser_clicked();

    void on_dtpadispenser_clicked();

    void on_neupogendispenser_clicked();

    void on_progressBar_4_valueChanged(int value);

    void on_progressBar_2_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_radioButton_toggled(bool checked);

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_5_sliderMoved(int position);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_dial_7_valueChanged(int value);

    void on_progressBar_3_valueChanged(int value);

    void on_dial_8_valueChanged(int value);

    void on_dial_9_sliderReleased();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_horizontalSlider_7_valueChanged(int value);

    void on_verticalSlider_2_valueChanged(int value);

    void on_verticalSlider_3_valueChanged(int value);

    void on_horizontalSlider_9_valueChanged(int value);

    void on_horizontalSlider_8_valueChanged(int value);

    void on_horizontalSlider_10_valueChanged(int value);

    void on_verticalSlider_4_valueChanged(int value);

    void on_verticalSlider_5_valueChanged(int value);

    void on_horizontalSlider_6_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
