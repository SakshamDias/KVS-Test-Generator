#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QList>


struct Question;
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
    void generateTest();
    QList<Question> loadQuestionsFromCSV(const QString &filePath);
    void saveToDocFile(const QList<Question> &questions, const QString &subject, const QString &topic);
};

#endif // MAINWINDOW_H
