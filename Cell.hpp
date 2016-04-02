#ifndef CELL_HPP
#define CELL_HPP
#include <QGraphicsObject>


class Cell:public QGraphicsObject
{
    Q_OBJECT
public:
    Cell();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QString m_text;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CELL_HPP
