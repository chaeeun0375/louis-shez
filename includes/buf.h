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

#ifndef __H_BUF_H
#define __H_BUF_H

#define KORE_BUF_INITIAL	128
#define KORE_BUF_INCREMENT	KORE_BUF_INITIAL

struct kore_buf {
	u_int8_t		*data;
	u_int32_t		length;
	u_int32_t		offset;
};

struct kore_buf	*kore_buf_create(u_int32_t);
void		kore_buf_append(struct kore_buf *, u_int8_t *, u_int32_t);
u_int8_t	*kore_buf_release(struct kore_buf *, u_int32_t *);

#endif /* !__H_BUF_H */
