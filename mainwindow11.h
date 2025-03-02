#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTopics(int index);
    void updateMarks(int index);
    void on_pushButton_clicked();

private:
    void loadAndShuffleCSV(const QString &filePath, const QString &subject, const QString &topic);
    Ui::MainWindow *ui;  // The Ui object that represents your UI
};

#endif // MAINWINDOW_H
