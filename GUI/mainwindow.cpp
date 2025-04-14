#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

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

void MainWindow::on_jeden_clicked()
{
    ui->wyswietlacz->insert("1");
}
void MainWindow::on_dwa_clicked()
{
    ui->wyswietlacz->insert("2");
}
void MainWindow::on_trzy_clicked()
{
    ui->wyswietlacz->insert("3");
}
void MainWindow::on_cztery_clicked()
{
    ui->wyswietlacz->insert("4");
}
void MainWindow::on_piec_clicked()
{
    ui->wyswietlacz->insert("5");
}
void MainWindow::on_szesc_clicked()
{
    ui->wyswietlacz->insert("6");
}
void MainWindow::on_siedem_clicked()
{
    ui->wyswietlacz->insert("7");
}
void MainWindow::on_osiem_clicked()
{
    ui->wyswietlacz->insert("8");
}
void MainWindow::on_dziewiec_clicked()
{
    ui->wyswietlacz->insert("9");
}
void MainWindow::on_zero_clicked()
{
    ui->wyswietlacz->insert("0");
}
void MainWindow::on_kropka_clicked()
{
    ui->wyswietlacz->insert(".");
}
void MainWindow::on_dziel_clicked()
{
    ui->wyswietlacz->insert("/");
}
void MainWindow::on_mnoz_clicked()
{
    ui->wyswietlacz->insert("*");
}
void MainWindow::on_odejmij_clicked()
{
    ui->wyswietlacz->insert("-");
}
void MainWindow::on_dodaj_clicked()
{
    ui->wyswietlacz->insert("+");
}


void MainWindow::on_rowne_clicked()
{
    QString text = ui->wyswietlacz->text();

    
    int opPos = -1;
    char op = '\0';

    for (int i = 0; i < text.length(); ++i) {
        QChar c = text[i];
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
            opPos = i;
            op = c.toLatin1();
            break;
        }
    }

    if (opPos == -1) {
        QMessageBox::warning(this, "Błąd", "Nie znaleziono operatora!");
        return;
    }

    try {
        double a = text.left(opPos).toDouble();
        double b = text.mid(opPos + 1).toDouble();

        double result = kalkulator.oblicz(a, b, op);
        ui->wyswietlacz->setText(QString::number(result));
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Błąd", e.what());
        ui->wyswietlacz->clear();
    }

}


void MainWindow::on_czysc_clicked()
{
    ui->wyswietlacz->clear();
    kalkulator.wyczysc();
}

