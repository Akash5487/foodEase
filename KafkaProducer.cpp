#include "KafkaProducer.h"
#include <QDebug>

KafkaProducer::KafkaProducer(const QString &broker, const QString &topic, QObject *parent)
    : QObject(parent), topic(topic.toStdString()) {
    std::string errstr;
    RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    conf->set("bootstrap.servers", broker.toStdString(), errstr);
    producer = RdKafka::Producer::create(conf, errstr);
    if (!producer) {
        qDebug() << "Failed to create producer:" << errstr.c_str();
    }
    delete conf;
}

KafkaProducer::~KafkaProducer() {
    producer->flush(10000);
    delete producer;
}

void KafkaProducer::sendMessage(const QString &message) {
    std::string msg = message.toStdString();
    RdKafka::ErrorCode err = producer->produce(
        topic, RdKafka::Topic::PARTITION_UA, RdKafka::Producer::RK_MSG_COPY,
        const_cast<char *>(msg.c_str()), msg.size(),
        nullptr, 0, 0, nullptr, nullptr
    );
    if (err != RdKafka::ERR_NO_ERROR) {
        qDebug() << "Failed to send message:" << RdKafka::err2str(err).c_str();
    }
    producer->poll(0);
}