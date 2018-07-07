/**
 * IIS 6 Website Information v0.2
 * Last updated: 24/10/2011
 *
 * Copyright (C) 2011 Quetzy Garcia <quetzyg@altek.org>
 */

#include <stdio.h>
#include <libxml/xmlreader.h>

/**
 * application info
 */
#define APP_NAME  "IIS 6 Website Information"
#define APP_VERSION "0.2"

/**
 * element name/attributes
 */
#define ELEM_NAME BAD_CAST "IIsWebVirtualDir"
#define ELEM_ATTR_DOMAIN BAD_CAST "AppFriendlyName"
#define ELEM_ATTR_POOL BAD_CAST "AppPoolId"
#define ELEM_ATTR_SMAPS BAD_CAST "ScriptMaps"

#define ASP_VER_MAX 4

static const char *asp_ver_str[ASP_VER_MAX] = { "def", "1.1", "2.0", "4.0" };

enum dump_errors
{
    DUMP_ERROR_OK = 0,
    DUMP_ERROR_DOMAIN = 1,
    DUMP_ERROR_POOL = 2,
    DUMP_ERROR_SMAPS = 3
};

/**
 * Dump IIsWebVirtualDir element information
 *
 * @params  xmlTextReaderPtrtext reader pointer
 * @return  int error code
 */
extern int xml_element_dump(xmlTextReaderPtr);

/**
 * Parse XML file
 *
 * @params  filename: the file name to parse
 * @return  void
 */
extern void xml_parse(const char *);
