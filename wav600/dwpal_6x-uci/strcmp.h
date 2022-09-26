#ifndef __STRCMP_H__
#define __STRCMP_H__

/* Workaround for strcmp()/strncmp()
	These functions are not banned, but they can be implemented in C RTL as system macros
	that use "banned" functions internally.

	This header must be include BEFORE defintion of banned functions
*/

#ifdef strcmp

static inline int __strcmp__(char const *s1, char const *s2) {
	return strcmp(s1, s2);
}

#undef strcmp
#define strcmp(s1, s2)  __strcmp__((s1), (s2))
#endif // strcmp

/* --------------------------- */

#ifdef strncmp

static inline int __strncmp__(char const *s1, char const *s2, size_t num) {
    return strncmp(s1, s2, num);
}

#undef strncmp
#define strncmp(s1, s2, num)  __strncmp__((s1), (s2), (num))
#endif // strncmp

#endif // __STRCMP_H__
