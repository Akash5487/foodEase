#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "KafkaProducer.h"
#include "KafkaConsumer.h"
#include "OrderManager.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    
    // Register C++ classes to QML
    OrderManager orderManager;
    KafkaProducer kafkaProducer("localhost:9092", "chat-topic");
    KafkaConsumer kafkaConsumer("localhost:9092", "chat-topic", "foodease-group");

    engine.rootContext()->setContextProperty("orderManager", &orderManager);
    engine.rootContext()->setContextProperty("kafkaProducer", &kafkaProducer);
    engine.rootContext()->setContextProperty("kafkaConsumer", &kafkaConsumer);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}