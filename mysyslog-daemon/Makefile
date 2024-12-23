CC = gcc
CFLAGS = -Iinclude -I../libmysyslog/include -Wall -Wextra

SRC = src/mysyslog-daemon.c
OBJ = $(SRC:.c=.o)
TARGET = mysyslog-daemon

PACKAGE_DIR = deb-package
PACKAGE_NAME = mysyslog-daemon
PACKAGE_PATH = $(PACKAGE_NAME).deb

LIBS = -L../libmysyslog -lmysyslog

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
	rm -rf $(PACKAGE_DIR)

deb: clean $(TARGET)
	mkdir -p $(PACKAGE_DIR)/usr/sbin/
	mkdir -p $(PACKAGE_DIR)/etc/mysyslog/
	mkdir -p $(PACKAGE_DIR)/DEBIAN/
	echo "Package: $(PACKAGE_NAME)" > $(PACKAGE_DIR)/DEBIAN/control
	echo "Version: 1.0" >> $(PACKAGE_DIR)/DEBIAN/control
	echo "Architecture: amd64" >> $(PACKAGE_DIR)/DEBIAN/control
	echo "Maintainer: Vladislav Babanov>" >> $(PACKAGE_DIR)/DEBIAN/control
	echo "Description: Daemon for mysyslog" >> $(PACKAGE_DIR)/DEBIAN/control
	cp $(TARGET) $(PACKAGE_DIR)/usr/sbin/
	echo "path=/var/log/mysyslog.log\nformat=json\ndriver=1" > $(PACKAGE_DIR)/etc/mysyslog/mysyslog.cfg
	dpkg-deb --build $(PACKAGE_DIR) $(PACKAGE_PATH)
