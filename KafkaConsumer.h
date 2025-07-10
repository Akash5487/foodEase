#ifndef KAFKACONSUMER_H
#define KAFKACONSUMER_H

#include <QObject>
#include <librdkafka/rdkafkacpp.h>

class KafkaConsumer : public QObject {
    Q_OBJECT
public:
    explicit KafkaConsumer(const QString &broker, const QString &topic, const QString &groupId, QObject *parent = nullptr);
    ~KafkaConsumer();
    Q_INVOKABLE void start();

signals:
    void messageReceived(const QString &message);

private:
    RdKafka::KafkaConsumer *consumer;
    std::string topic;
};

#endif // KAFKACONSUMER_H