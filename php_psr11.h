#ifndef PHP_PSR11_H
#define PHP_PSR11_H

#include <main/php.h>

#define PHP_PSR11_EXTNAME  "psr11"
#define PHP_PSR11_EXTVER   "1.0"

#if defined(__GNUC__) && __GNUC__ >= 4
#   define PSR11_VISIBILITY_HIDDEN __attribute__((visibility("hidden")))
#else
#   define PSR11_VISIBILITY_HIDDEN
#endif

#ifdef COMPILE_DL_PSR11
PSR11_VISIBILITY_HIDDEN
#endif
extern zend_module_entry psr11_module_entry;

extern zend_class_entry* ce_Psr_Container_ContainerInterface;
extern zend_class_entry* ce_Psr_Container_ContainerExceptionInterface;
extern zend_class_entry* ce_Psr_Container_NotFoundExceptionInterface;

#endif /* PHP_PSR11_H */
