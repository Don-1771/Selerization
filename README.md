# Data Serialization and Conversion (Qt C++)

## Описание проекта

Данный проект представляет собой учебное приложение на C++ с использованием Qt, демонстрирующее различные способы сериализации и десериализации данных.

Реализованы три подхода к сохранению и восстановлению объектов:
- бинарная сериализация через `QDataStream`
- сериализация в формат JSON
- сериализация в формат XML

---

## Цель проекта

Цель работы — изучение:
- механизмов сериализации данных в C++
- работы с файлами в Qt (QFile)
- форматов хранения данных (binary, JSON, XML)
- потоковой записи и чтения объектов

---

## Используемые технологии

- C++17
- Qt Core
  - QFile
  - QDataStream
  - QJsonDocument / QJsonObject
  - QXmlStreamReader / QXmlStreamWriter
- CMake (при наличии сборки через CMake)

---

## Описание компонентов

### Класс Test

Класс `Test` представляет собой модель данных:

- `QString m_name` — имя объекта
- `QMap<QString, QString> m_map` — набор ключ-значение

Поддерживает:
- заполнение тестовыми данными (`fill()`)
- сериализацию через `QDataStream` (`operator <<` и `operator >>`)

---

### Класс Converter

Класс `Converter` отвечает за:
- запись и чтение JSON
- запись и чтение XML

#### JSON:
- Используется `QJsonDocument`
- Конвертация через `QVariantMap`

#### XML:
- Используется `QXmlStreamWriter` и `QXmlStreamReader`
- Формат:
  ```xml
  <test name="...">
      <items>
          <item key="..." value="..."/>
      </items>
  </test>
