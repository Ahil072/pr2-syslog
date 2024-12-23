CC = gcc
CFLAGS = -Iinclude -fPIC -Wall -Wextra
LDFLAGS = -shared

SRC = src/libmysyslog.c
OBJ = $(SRC:.c=.o)
TARGET = libmysyslog.so

PACKAGE_DIR = deb-package
PACKAGE_NAME = libmysyslog
PACKAGE_PATH = $(PACKAGE_NAME).deb

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
	rm -rf $(PACKAGE_DIR)

deb: clean $(TARGET)
	mkdir -p $(PACKAGE_DIR)/usr/lib/
	mkdir -p $(PACKAGE_DIR)/DEBIAN/
	echo "Package: $(PACKAGE_NAME)" > $(PACKAGE_DIR)/DEBIAN/control
	echo "Version: 1.0" >> $(PACKAGE_DIR)/DEBIAN/control
	echo "Architecture: amd64" >> $(PACKAGE_DIR)/DEBIAN/control
	echo "Maintainer: Vladislav Babanov" >> $(PACKAGE_DIR)/DEBIAN/control
	echo "Description: Logging library for mysyslog" >> $(PACKAGE_DIR)/DEBIAN/control
	cp $(TARGET) $(PACKAGE_DIR)/usr/lib/
	dpkg-deb --build $(PACKAGE_DIR) $(PACKAGE_PATH)
