#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QGraphicsScene>

#include "Cell.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_scene = new QGraphicsScene();

    ui->setupUi(this);
    ui->graphicsView->setScene(m_scene);

    for (int j=0; j<3; j++) {
        for(int i=0; i<3; i++) {
            m_cells[i+3*j] = new Cell();
            m_scene->addItem(m_cells[i+3*j]);
            m_cells[i+3*j]->setPos(i*50,j*50);
            connect(m_cells[i+3*j], SIGNAL(clicked(Cell*)), this, SLOT(onCellClicked(Cell*)));
        }
    }
    m_scene->update();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCellClicked(Cell *cell)
{
    if (qrand() % 2) {
        cell->setState(Cell::State0);
    } else {
        cell->setState(Cell::StateX);
    }
}
