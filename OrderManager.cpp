#include "OrderManager.h"

OrderManager::OrderManager(QObject *parent) : QObject(parent) {
    menu = {"Pizza", "Burger", "Salad", "Pasta"};
}

QStringList OrderManager::getMenu() const {
    return menu;
}

void OrderManager::placeOrder(const QString &item) {
    orders.append(item);
    emit orderPlaced(item + " ordered!");
}