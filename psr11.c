#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php_psr11.h"
#include <Zend/zend_inheritance.h>
#include <ext/standard/info.h>

zend_class_entry* ce_Psr_Container_ContainerInterface;
zend_class_entry* ce_Psr_Container_ContainerExceptionInterface;
zend_class_entry* ce_Psr_Container_NotFoundExceptionInterface;

ZEND_BEGIN_ARG_INFO_EX(arginfo_has_get, 0, 0, 1)
    ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

static const zend_function_entry fe_psr_container_containerinterface[] = {
    PHP_ABSTRACT_ME(Psr_Container_ContainerInterface, has, arginfo_has_get)
    PHP_ABSTRACT_ME(Psr_Container_ContainerInterface, get, arginfo_has_get)
    PHP_FE_END
};

static PHP_MINIT_FUNCTION(psr11)
{
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "Psr\\Container\\ContainerInterface", fe_psr_container_containerinterface);
    ce_Psr_Container_ContainerInterface = zend_register_internal_interface(&ce);
    if (UNEXPECTED(!ce_Psr_Container_ContainerInterface)) {
        return FAILURE;
    }

    INIT_CLASS_ENTRY(ce, "Psr\\Container\\ContainerExceptionInterface", NULL);
    ce_Psr_Container_ContainerExceptionInterface = zend_register_internal_interface(&ce);
    if (UNEXPECTED(!ce_Psr_Container_ContainerInterface)) {
        return FAILURE;
    }

    INIT_CLASS_ENTRY(ce, "Psr\\Container\\NotFoundExceptionInterface", NULL);
    ce_Psr_Container_NotFoundExceptionInterface = zend_register_internal_interface(&ce);
    if (UNEXPECTED(!ce_Psr_Container_ContainerInterface)) {
        return FAILURE;
    }

    zend_do_inheritance(ce_Psr_Container_NotFoundExceptionInterface, ce_Psr_Container_ContainerExceptionInterface);

    return SUCCESS;
}

static PHP_MINFO_FUNCTION(psr11)
{
    php_info_print_table_start();
    php_info_print_table_row(2, "PSR-11 Extension", "enabled");
    php_info_print_table_row(2, "Version", PHP_PSR11_EXTVER);
    php_info_print_table_end();
}

zend_module_entry psr11_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_PSR11_EXTNAME,
    NULL,
    PHP_MINIT(psr11),
    NULL,
    NULL,
    NULL,
    PHP_MINFO(psr11),
    PHP_PSR11_EXTVER,
    NO_MODULE_GLOBALS,
    NULL,
    STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PSR11
ZEND_GET_MODULE(psr11)
#endif
