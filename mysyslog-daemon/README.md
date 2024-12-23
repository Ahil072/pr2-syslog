# mysyslog-daemon - это демон для вывода данных в журнал с различными уровнями журналирования. Демон автоматически запускается во время старта компьютера и постоянно выводит данные в журнал с учетом настроек из конфигурационного файла.

1.  Создаем конфигурационный файл:
   *  `sudo mkdir -p /etc/mysyslog`
   *  `sudo touch /etc/mysyslog/mysyslog.cfg`
2. Создаеи systemd-сервис для mysyslog-daemon: `sudo cp mysyslog-daemon.service /etc/systemd/system/`

3. Запускаем daemon и добавляем его в автозагрузку:
   * `sudo systemctl daemon-reload`
   * `sudo systemctl start mysyslog-daemon`
   * `sudo systemctl enable mysyslog-daemon`

## Использование

После установки и настройки mysyslog-daemon автоматически будет выводить данные в журнал в соответствии с настройками из конфигурационного файла.

* Для остановки демона:
 `sudo systemctl stop mysyslog-daemon`
* Для перезапуска демона:
 `sudo systemctl restart mysyslog-daemon`
