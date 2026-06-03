#include <QCoreApplication>
#include <QFile>
#include <QList>
#include <QDataStream>
#include <QDebug>
#include "test.h"
#include "converter.h"

//---------------------------------------------------------------------------------------
bool saveFile(Test *t, QString path){
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) return false;
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_6);

    stream << *t;

    file.close();
    return true;
}
//---------------------------------------------------------------------------------------
bool readFile(QString path){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) return false;

    QDataStream stream(&file);
    if(stream.version() != QDataStream::Qt_6_6){
        qCritical() << "Version do not match";
        file.close();
        return false;
    }

    Test t;

    stream >> t;

    qInfo() << "name:" << t.name();

    foreach (QString key, t.map().keys()) {
        qInfo() << key << " : " << t.map().value(key);
    }

    file.close();
    return true;
}
//---------------------------------------------------------------------------------------
void WriteJson(QString path){
    Test t;
    t.fill();
    Converter::WriteJson(&t, path);
}
//---------------------------------------------------------------------------------------
void ReadJson(QString path){
    Test* t;
    t = Converter::ReadJson(path);
    if(!t){
        qInfo() << "Object not loaded";
        return;
    }

    qInfo() << "Name: " << t->name();
    foreach (QString key, t->map().keys()) {
        qInfo() << key << " : " << t->map().value(key);
    }
    t->deleteLater();
}
//---------------------------------------------------------------------------------------
void test(){

    QString filename = "test.txt";
    Test t;
    t.fill();

    if(saveFile(&t, filename))
    {
        qInfo() << "File saved";
        readFile(filename);
    }
}
//---------------------------------------------------------------------------------------
void WriteXml(QString path){
    Test t;
    t.fill();
    Converter::WriteXml(&t, path);
}
//---------------------------------------------------------------------------------------
void ReadXml(QString path){
    Test* t;
    t = Converter::ReadXml(path);
    if(!t){
        qInfo() << "Object not loaded";
        return;
    }

    qInfo() << "Name: " << t->name();
    foreach (QString key, t->map().keys()) {
        qInfo() << key << " : " << t->map().value(key);
    }
    t->deleteLater();
}
//---------------------------------------------------------------------------------------
void save(QList<int> list, QString path){
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly))
        qCritical() << file.error();

    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_6);

    stream << list;
}
//---------------------------------------------------------------------------------------
QList<int> load(QString path){

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        qCritical() << file.error();

    QDataStream stream(&file);
    if(stream.version() != QDataStream::Qt_6_6){
        qCritical() << "Version do not match";
        file.close();
    }

    QList<int> list;
    stream >> list;

    return list;
}
//---------------------------------------------------------------------------------------
void fill(QList<int>* list){
    for(int i=0; i<10; ++i)
        list->append(i);
}
//---------------------------------------------------------------------------------------
void printList(QList<int>& list){
    foreach (int i, list) {
        qInfo() << i;
    }
}
//---------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "list.txt";
    //WriteJson(filename);
    //ReadJson(filename);

    //WriteXml(filename);
    //ReadXml(filename);

    QList<int> list;
    QList<int> data;
    fill(&list);
    save(list, filename);
    data = load(filename);
    printList(data);

    return a.exec();
}
