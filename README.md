# `mysyslog` Практическая работа № 2 на лекции по `Операционным системам` 

Этот репозиторий содержит проект `mysyslog` для ведения журналов в различных форматах.

## Подмодули проекта
- `libmysyslog`: Основная библиотека для логирования.
- `libmysyslog-text`: Плагин для логирования в текстовом формате.
- `libmysyslog-json`: Плагин для логирования в формате JSON.
- `mysyslog-client`: Тестовое клиентское приложение.
- `mysyslog-daemon`: Демон для ведения журнала.

## Сборка проекта
1. Клонируем репозиторий: `https://github.com/TheToxicFox/mysyslog.git`
2. Переходим в каталог mysyslog: cd mysyslog
3. Cобирайте программу с помощью:
- `make all`: собирает все цели.
- `make clean`: удаляет все временные файлы.
- `make deb`: собирает deb-пакет.

## Использование проекта
- `mysyslog client`: Запуск клиента: ./mysyslog-client
- `mysyslog daemon`: Файл конфигурации '/etc/mysyslog/mysyslog.cfg'
1. sudo systemctl start mysyslog-daemon
2. sudo systemctl enable mysyslog-daemon 
