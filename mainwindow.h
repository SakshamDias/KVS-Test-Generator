#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>

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

private:
    Ui::MainWindow *ui;  // The Ui object that represents your UI
};

#endif // MAINWINDOW_H
