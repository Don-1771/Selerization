#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMap>
#include <QVariant>
#include <QVariantMap>
#include <QDebug>
#include <QFile>
#include <QDir>
#include<QXmlStreamReader>
#include <QXmlStreamWriter>
#include "test.h"

class Converter : public QObject
{
    Q_OBJECT
public:
    explicit Converter(QObject *parent = nullptr);
    static Test* ReadJson(QString path);
    static void WriteJson(Test* obj, QString path);
    static Test* ReadXml(QString path);
    static void WriteXml(Test* obj, QString path);
signals:
};

#endif // CONVERTER_H
