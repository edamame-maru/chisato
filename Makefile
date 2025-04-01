# chisato - CLI shogi program
# See LICENSE file for copyright and license details.

CC = cc
CFLAGS = -std=c17 -pedantic -Wall -Wextra

all: chisato

chisato: chisato.c
	${CC} chisato.c -o chisato ${CFLAGS}

clean:
	rm -f chisato
