NAME = mkfileinit

TARGET = $(OUTDIR)/$(NAME)

CC = gcc
CFLAGS = -Wall -MMD -O2


OBJDIR = obj
SRCDIR = src

OUTDIR = out

SOURCES := $(shell find . -name '*.c')
OBJECTS := $(subst .c,.o, $(subst ./src,./$(OBJDIR),$(SOURCES)))
DEPS := $(shell find . -name '*.d')

.PHONY: default
default:
	$(MAKE) $(TARGET)
# 	$(MAKE) run



$(TARGET): $(OBJECTS) | $(OUTDIR)
	$(CC) -o $(TARGET) $^ $(CFLAGS) 


$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -c $< -o $@ $(CFLAGS)


include $(DEPS)

$(OUTDIR):
	mkdir -p $@

$(OBJDIR):
	mkdir -p $@
	$(shell rsync -a --include='*/' --exclude='*' $(SRCDIR)/ $(OBJDIR)/)


.PHONY: clean deepclean run install uninstall

run: $(TARGET)
	./$(TARGET)

clean: uninstall
	rm -rf $(OUTDIR)

deepclean: clean
	rm -rf $(OBJDIR)

install: $(TARGET) uninstall
	cp $(TARGET) /usr/local/bin/
	mkdir /usr/local/etc/MakefileInit
	cp -r ./templates /usr/local/etc/MakefileInit/templates

uninstall: 
	rm -f /usr/local/bin/$(NAME)
	rm -rf /usr/local/etc/MakefileInit