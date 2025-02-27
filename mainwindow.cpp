#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);  // This initializes the UI from the .ui file

    // Connect signals to slots
    connect(ui->subject, SIGNAL(currentIndexChanged(int)),
            this, SLOT(updateTopics(int)));
    connect(ui->topic, SIGNAL(currentIndexChanged(int)),
            this, SLOT(updateMarks(int)));

    // Initial setup
    updateTopics(ui->subject->currentIndex());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTopics(int index)
{
    ui->topic->clear();  // Clear the current topics

    // Populate topic combo box based on the selected subject
    if (index == 0) { // Mathematics
        ui->topic->addItem("Matrices");
        ui->topic->addItem("Linear Equation in one variable");
        ui->topic->addItem("Probablity");
        ui->topic->addItem("Statistics");
    } else if (index == 1) { // Science
        ui->topic->addItem("Human Eye");
        ui->topic->addItem("Light");
        ui->topic->addItem("Sound");
        ui->topic->addItem("Reproduction in Animals");
        ui->topic->addItem("Chemical Effects of Electric Current");
        ui->topic->addItem("Magnetism");
        ui->topic->addItem("Semiconductor");
        ui->topic->addItem("Electric Charge");
    } else if (index == 2) { // English
        ui->topic->addItem("Noun");
        ui->topic->addItem("Pronoun");
        ui->topic->addItem("Adjective");
        ui->topic->addItem("The Kakas of New Zeland");
        ui->topic->addItem("Amins' Eggs");
        ui->topic->addItem("Dirty Money");
        ui->topic->addItem("Finishing Schools");
        ui->topic->addItem("Ashesh that made the trees bloom");
    }

    // Update marks for the selected topic
    updateMarks(ui->topic->currentIndex());
}

void MainWindow::updateMarks(int index)
{
    ui->marks->clear();  // Clear the current marks

    // Populate marks combo box based on the selected topic
    if (ui->subject->currentIndex() == 0) { // Mathematics
        if (index == 0) { // Algebra
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        } else if (index == 1) { // Geometry
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        } else if (index == 2) { // Calculus
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
    } else if (ui->subject->currentIndex() == 1) { // Science
        if (index == 0) { // Physics
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        } else if (index == 1) { // Chemistry
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        } else if (index == 2) { // Biology
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
    } else if (ui->subject->currentIndex() == 2) { // English
        if (index == 0) { // Grammar
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        } else if (index == 1) { // Literature
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        } else if (index == 2) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
    }
}
