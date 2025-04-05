# chisato - CLI shogi program
# See LICENSE file for copyright and license details.

CC = cc
CFLAGS = -std=c17 -pedantic -Wall -Wextra -static
INSTALL_DIR = /usr/local/bin

chisato: chisato.c
	$(CC) chisato.c -o chisato $(CFLAGS)

clean:
	$(RM) chisato

install: chisato
	mkdir -p $(INSTALL_DIR)
	cp chisato $(INSTALL_DIR)/
	chmod 755 $(INSTALL_DIR)/chisato

uninstall:
	$(RM) $(INSTALL_DIR)/chisato
