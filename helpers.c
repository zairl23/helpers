/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_helpers.h"

/* If you declare any globals in php_helpers.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(helpers)
*/

/* True global resources - no need for thread safety here */
static int le_helpers;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("helpers.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_helpers_globals, helpers_globals)
    STD_PHP_INI_ENTRY("helpers.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_helpers_globals, helpers_globals)
PHP_INI_END()
*/
/* }}} */
PHP_FUNCTION(array_add)
{
	zval *arr;
	char *key;
	size_t key_len;
	char *val;
	size_t val_len;
	zend_string *return_str;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ass", &arr, &key, &key_len, &val, &val_len) == FAILURE) {
				return;
  }

	add_assoc_string(arr, key, val);
	RETURN_ZVAL(arr, 0, 1);
}

PHP_FUNCTION(say)
{
	zend_string *strg;
  strg = strpprintf(0, "say hello");
  RETURN_STR(strg);
}

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_helpers_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_helpers_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "helpers", arg);

	RETURN_STR(strg);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_helpers_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_helpers_init_globals(zend_helpers_globals *helpers_globals)
{
	helpers_globals->global_value = 0;
	helpers_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(helpers)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(helpers)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(helpers)
{
#if defined(COMPILE_DL_HELPERS) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(helpers)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(helpers)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "helpers support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ helpers_functions[]
 *
 * Every user visible function must have an entry in helpers_functions[].
 */
const zend_function_entry helpers_functions[] = {
	PHP_FE(array_add, NULL)
	PHP_FE(say, NULL)
	PHP_FE(confirm_helpers_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in helpers_functions[] */
};
/* }}} */

/* {{{ helpers_module_entry
 */
zend_module_entry helpers_module_entry = {
	STANDARD_MODULE_HEADER,
	"helpers",
	helpers_functions,
	PHP_MINIT(helpers),
	PHP_MSHUTDOWN(helpers),
	PHP_RINIT(helpers),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(helpers),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(helpers),
	PHP_HELPERS_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_HELPERS
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(helpers)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
