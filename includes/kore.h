/*
 * Copyright (c) 2013 Joris Vink <joris@coders.se>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __H_KORE_H
#define __H_KORE_H

#define KORE_RESULT_ERROR	0
#define KORE_RESULT_OK		1

#define errno_s			strerror(errno)
#define kore_log(fmt, ...)	\
	kore_log_internal(__FILE__, __LINE__, fmt, ##__VA_ARGS__)

struct netbuf {
	u_int8_t		*data;
	u_int32_t		offset;
	u_int32_t		length;
	void			*owner;
	int			(*cb)(struct netbuf *);

	TAILQ_ENTRY(netbuf)	list;
};

struct listener {
	int			fd;
	struct sockaddr_in	sin;
};

struct connection {
	int			fd;
	struct sockaddr_in	sin;
	void			*owner;

	TAILQ_HEAD(, netbuf)	send_queue;
	TAILQ_HEAD(, netbuf)	recv_queue;
};

void		*kore_malloc(size_t);
void		*kore_calloc(size_t, size_t);
void		*kore_realloc(void *, size_t);
char		*kore_strdup(const char *);

void		fatal(const char *, ...);
void		kore_log_internal(char *, int, const char *, ...);

#endif /* !__H_KORE_H */
