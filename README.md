**FoodEase**
A cross-platform restaurant management application with real-time chat, built using Qt/QML and Apache Kafka.

**Features**
* Browse and order from a food menu
* Real-time chat for customers and staff
* Cross-platform support (Windows, macOS, Linux)
* Powered by Qt/QML for the UI and Kafka for messaging

**Prerequisites**
* Qt 6.x (with Qt Creator)
* Apache Kafka
* librdkafka (C/C++ library)
* CMake

**Kafka Setup**
1. Start Zookeeper: bin/zookeeper-server-start.sh config/zookeeper.properties
2. Start Kafka: bin/kafka-server-start.sh config/server.properties
3. Create a topic: bin/kafka-topics.sh --create --topic chat-topic --bootstrap-server localhost:9092 --partitions 1 --replication-factor 1

**Usage**
* Menu Tab: View the menu and place orders.
* Chat Tab: Send and receive real-time messages.

**Contributing**
Contributions are welcome! Please submit issues or pull requests.
