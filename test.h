#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDataStream>
#include <QMap>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
private:
    QString m_name;
    QMap<QString, QString> m_map;

public:
    explicit Test(QObject *parent = nullptr);
    QString name();
    QMap<QString, QString> map();
    void fill();
    void setName(QString name);
    void setMap(QMap<QString, QString> newMap);

    friend QDataStream& operator <<(QDataStream &stream, const Test &t){
        qInfo() << "operator <<";
        stream << t.m_name;
        stream << t.m_map;
        return stream;
    }

    friend QDataStream& operator >>(QDataStream &stream, Test &t){
        qInfo() << "operator >>";
        stream >> t.m_name;
        stream >> t.m_map;
        return stream;
    }
signals:
};

#endif // TEST_H
