#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "propmodel.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PropModel *myModel = new PropModel(this);
    ui->tableView->setModel(myModel);
    ui->tableView->show();
    ui->tableView->update();

}

MainWindow::~MainWindow()
{
    delete ui;
}
