SUBDIRS = libmysyslog libmysyslog-text libmysyslog-json mysyslog-client mysyslog-daemon

all:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

deb:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir deb; \
	done