#include "KafkaConsumer.h"
#include <QDebug>
#include <QTimer>

KafkaConsumer::KafkaConsumer(const QString &broker, const QString &topic, const QString &groupId, QObject *parent)
    : QObject(parent), topic(topic.toStdString()) {
    std::string errstr;
    RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    conf->set("bootstrap.servers", broker.toStdString(), errstr);
    conf->set("group.id", groupId.toStdString(), errstr);
    consumer = RdKafka::KafkaConsumer::create(conf, errstr);
    if (!consumer) {
        qDebug() << "Failed to create consumer:" << errstr.c_str();
    }
    consumer->subscribe({topic});
    delete conf;
}

KafkaConsumer::~KafkaConsumer() {
    consumer->close();
    delete consumer;
}

void KafkaConsumer::start() {
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        RdKafka::Message *msg = consumer->consume(1000);
        if (msg->err() == RdKafka::ERR_NO_ERROR) {
            QString message = QString::fromStdString(std::string(
                static_cast<const char *>(msg->payload()), msg->len()));
            emit messageReceived(message);
        }
        delete msg;
        consumer->poll(0);
    });
    timer->start(100);
}