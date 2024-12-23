CC = gcc
CFLAGS = -Iinclude -I../libmysyslog/include -Wall -Wextra

SRC = src/mysyslog-client.c
OBJ = $(SRC:.c=.o)
TARGET = mysyslog-client

PACKAGE_DIR = deb-package
PACKAGE_NAME = mysyslog-client
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
	mkdir -p $(PACKAGE_DIR)/usr/bin/
	mkdir -p $(PACKAGE_DIR)/DEBIAN/
	echo "Package: $(PACKAGE_NAME)" > $(PACKAGE_DIR)/DEBIAN/control
	echo "Version: 1.0" >> $(PACKAGE_DIR)/DEBIAN/control
	echo "Architecture: amd64" >> $(PACKAGE_DIR)/DEBIAN/control
	echo "Maintainer: Vladislav Babanov" >> $(PACKAGE_DIR)/DEBIAN/control
	echo "Description: Command-line client for mysyslog" >> $(PACKAGE_DIR)/DEBIAN/control
	cp $(TARGET) $(PACKAGE_DIR)/usr/bin/
	dpkg-deb --build $(PACKAGE_DIR) $(PACKAGE_PATH)
