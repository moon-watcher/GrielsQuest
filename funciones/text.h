#ifndef TEXT_H
#define TEXT_H

#include <genesis.h>

typedef void *__gnuc_va_list;
typedef __gnuc_va_list va_list;

#define __va_rounded_size(TYPE)  \
  (((sizeof (TYPE) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))

#define va_start(AP, LASTARG) 						\
 (AP = ((__gnuc_va_list) __builtin_next_arg (LASTARG)))

#define va_end(AP)	((void)0)

#define va_arg(AP, TYPE)						\
 (AP = (__gnuc_va_list) ((char *) (AP) + __va_rounded_size (TYPE)),	\
  *((TYPE *) (void *) ((char *) (AP)					\
		       - ((sizeof (TYPE) < __va_rounded_size (char)	\
			   ? sizeof (TYPE) : __va_rounded_size (TYPE))))))

#define isdigit(c)	((c) >= '0' && (c) <= '9')

/**
 * @brief TEXT_printf prints a string to the specified position using vsprintf
 * @param x text x start position in tiles
 * @param y text y position in tiles
 * @param fmt string to print
 */
void TEXT_printf(u16 x, u16 y, const char *fmt, ...);

#endif // TEXT_H
