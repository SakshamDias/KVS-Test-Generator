#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <qmessagebox.h>
#include <QDebug>
#include <QTextStream>
#include <QRandomGenerator>
#include <QFile>
#include <QFileDialog>
#include <QDir> // Added this include
#include <QTextCodec> // Added this include

struct Question {
    QString subject;
    QString topic;
    int marks;
    QString questionText;
};


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
    connect(ui->generateTest, &QPushButton::clicked, this, &MainWindow:: generateTest);

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
        ui->topic->addItem("Algebra");
        ui->topic->addItem("Calculus");
        ui->topic->addItem("Probablity");
        ui->topic->addItem("Statistics");
        ui->topic->addItem("Geometry");
        ui->topic->addItem("Trigonometry");
        ui->topic->addItem("Linear Algebra");
        ui->topic->addItem("Number Theory");
    } else if (index == 1) { // Phy
        ui->topic->addItem("Newton's Laws");
        ui->topic->addItem("Electromagnetism");
        ui->topic->addItem("Optics");
        ui->topic->addItem("Thermodynamics");
        ui->topic->addItem("Quantum Mechanics");
        ui->topic->addItem("Kinematics");
        ui->topic->addItem("Waves");
        ui->topic->addItem("Mordern Physics");
    } else if (index == 2) { // Chem
        ui->topic->addItem("Periodic Table");
        ui->topic->addItem("Chemical Bonding");
        ui->topic->addItem("Organic Chemistry");
        ui->topic->addItem("Acids and Bases");
        ui->topic->addItem("Thermochemistry");
        ui->topic->addItem("Electrochemistry");
        ui->topic->addItem("Kinetics");
        ui->topic->addItem("Biochemistry");
    }
    else if (index == 3) { // Bio
        ui->topic->addItem("Cell Biology");
        ui->topic->addItem("Genetics");
        ui->topic->addItem("Evolution");
        ui->topic->addItem("Human Physiology");
        ui->topic->addItem("Ecology");
        ui->topic->addItem("Microbiology");
        ui->topic->addItem("Botany");
        ui->topic->addItem("Zoology");
    }
    else if (index == 4) { // English
        ui->topic->addItem("Grammar");
        ui->topic->addItem("Literature");
        ui->topic->addItem("Writing Skills");
        ui->topic->addItem("Poetry Analysis");
        ui->topic->addItem("Reading Comprehension");
        ui->topic->addItem("Vocabulary");
        ui->topic->addItem("Essay Writing");
        ui->topic->addItem("Drama Analysis");
    }
    else if (index == 5) { // IT
        ui->topic->addItem("Programming Basics");
        ui->topic->addItem("Networking");
        ui->topic->addItem("Cybersecurity");
        ui->topic->addItem("Database Management");
        ui->topic->addItem("Artificial Intelligence");
        ui->topic->addItem("Web Development");
        ui->topic->addItem("Data Structures");
        ui->topic->addItem("Software Engineering");
    }
    else if (index == 6) { // EVS
        ui->topic->addItem("Climate Change");
        ui->topic->addItem("Biodiversity");
        ui->topic->addItem("Sustainable Development");
        ui->topic->addItem("Pollution");
        ui->topic->addItem("Conservation");
        ui->topic->addItem("Renewable Energy");
        ui->topic->addItem("Waste Management");
        ui->topic->addItem("Ecosystems");
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
        } else if (index==3) {
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index==4) {
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
            ui->marks->addItem("6");

        }
        else if (index==5) {
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
            ui->marks->addItem("6");

        }
        else if (index==6) {
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
            ui->marks->addItem("6");

        }
        else if (index==7) {
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
            ui->marks->addItem("6");

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
        else if (index == 3) { // Biology
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 4) { // Biology
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 5) { // Biology
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 6) { // Biology
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 7) { // Biology
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
        else if (index == 3) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 4) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 5) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 6) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 7) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
    } else if (ui->subject->currentIndex()== 3){ // Biology
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
        else if (index == 3) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 4) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 5) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 6) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 7) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
    } else if (ui->subject->currentIndex()==4){
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
        else if (index == 3) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 4) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 5) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 6) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 7) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
    } else if(ui->subject->currentIndex()== 5) {
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
        else if (index == 3) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 4) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 5) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 6) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 7) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
    } else if (ui->subject->currentIndex()== 6) { //EVS
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
        else if (index == 3) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 4) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 5) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 6) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }
        else if (index == 7) { // Writing
            ui->marks->addItem("1");
            ui->marks->addItem("2");
            ui->marks->addItem("3");
            ui->marks->addItem("4");
            ui->marks->addItem("5");
        }

    }
}

void MainWindow::generateTest()
{
    QString subject = ui->subject->currentText();
    QString topic = ui->topic->currentText();
    int marksPerQuestion = ui->marks->currentText().toInt();
    int numQuestions = ui->questioncount->value();

    QList<Question> allQuestions = loadQuestionsFromCSV("questions_final.csv");
    QList<Question> filteredQuestions;

    // Filter questions based on user selection
    for (const Question &q : allQuestions) {
        if (q.subject == subject && q.topic == topic && q.marks == marksPerQuestion) {
            filteredQuestions.append(q);
        }
    }

    // Check if enough questions exist
    if (filteredQuestions.size() < numQuestions) {
        QMessageBox::warning(this, "Error", "Not enough questions available.");
        return;
    }

    // Randomly shuffle and select required questions
    QList<Question> selectedQuestions;
    for (int i = 0; i < numQuestions; ++i) {
        int index = QRandomGenerator::global()->bounded(filteredQuestions.size());
        selectedQuestions.append(filteredQuestions.takeAt(index));
    }

    // Generate and save DOC file
    saveToDocFile(selectedQuestions, subject, topic);
}

QList<Question> MainWindow::loadQuestionsFromCSV(const QString &filePath)
{
    QList<Question> questions;
    QFile file(filePath);

    qDebug() << "Current working directory: " << QDir::currentPath(); // Debug line 1

    if (!QFile::exists(filePath)) { // Debug line 2
        QMessageBox::warning(this, "Error", "CSV file not found: " + filePath);
        return questions;
    }

    qDebug() << "CSV file exists at path: " << filePath;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Failed to open the CSV file.");
        qDebug() << "Error opening file. Error code:" << file.error(); // Add this line
        return questions;
    }

    qDebug() << "CSV file opened successfully.";

    QTextStream in(&file);
    in.setCodec(QTextCodec::codecForName("UTF-8")); // Explicitly set UTF-8 encoding
    bool firstLine = true;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (firstLine) { // Skip header
            firstLine = false;
            continue;
        }

        QStringList parts = line.split(",");
        if (parts.size() < 4) {
            qDebug() << "Skipping line due to invalid format: " << line;
            continue; // Ensure valid data
        }

        Question q;
        q.subject = parts[0].trimmed();
        q.topic = parts[1].trimmed();
        q.marks = parts[2].trimmed().toInt();
        q.questionText = parts[3].trimmed();
        questions.append(q);
    }

    file.close();
    qDebug() << "CSV file closed.";
    return questions;
}

void MainWindow::saveToDocFile(const QList<Question> &questions, const QString &subject, const QString &topic)
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save Question Paper", "QuestionPaper.doc", "Word Document (*.doc)");

    if (filePath.isEmpty()) return; // If user cancels

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not save the file.");
        return;
    }

    QTextStream out(&file);
    out << "Subject: " << subject << "\n";
    out << "Topic: " << topic << "\n\n";
    out << "Generated Question Paper\n";
    out << "-------------------------\n\n";

    int count = 1;
    for (const Question &q : questions) {
        out << QString::number(count++) + ". " + q.questionText + " (" + QString::number(q.marks) + " Marks)\n\n";
    }

    file.close();

    QMessageBox::information(this, "Success", "Question paper saved as " + filePath);
}
