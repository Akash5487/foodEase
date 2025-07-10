#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <QObject>
#include <QStringList>

class OrderManager : public QObject {
    Q_OBJECT
public:
    explicit OrderManager(QObject *parent = nullptr);
    Q_INVOKABLE QStringList getMenu() const;
    Q_INVOKABLE void placeOrder(const QString &item);

signals:
    void orderPlaced(const QString &order);

private:
    QStringList menu;
    QStringList orders;
};

#endif // ORDERMANAGER_H