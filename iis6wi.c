/**
 * IIS 6 Website Information v0.2
 * Last updated: 24/10/2011
 *
 * Copyright (C) 2011 Quetzy Garcia <quetzyg@altek.org>
 */

#include "iis6wi.h"

#ifdef LIBXML_READER_ENABLED

/**
 * Dump IIsWebVirtualDir element information
 *
 * @params  xmlTextReaderPtrtext reader pointer
 * @return  int error code
 */
int xml_element_dump(xmlTextReaderPtr rp)
{
    const xmlChar *name = NULL;
    xmlChar *domain = NULL;
    xmlChar *pool = NULL;
    xmlChar *smaps = NULL;
    xmlChar *asp = NULL;
    int i;

    name = xmlTextReaderConstName(rp);

    if (name != NULL)
    {
        /* we only care about the start "IIsWebVirtualDir" elements */
        if (xmlStrEqual(name, ELEM_NAME) && xmlTextReaderNodeType(rp) == XML_READER_TYPE_ELEMENT)
        {
            domain = xmlTextReaderGetAttribute(rp, ELEM_ATTR_DOMAIN);

            if (domain == NULL)
            {
                return DUMP_ERROR_DOMAIN;
            }

            pool = xmlTextReaderGetAttribute(rp, ELEM_ATTR_POOL);

            if (pool == NULL)
            {
                free(domain);

                return DUMP_ERROR_POOL;
            }

            smaps = xmlTextReaderGetAttribute(rp, ELEM_ATTR_SMAPS);

            if (smaps == NULL)
            {
                free(domain);
                free(pool);

                return DUMP_ERROR_SMAPS;
            }

            /* find out the ASP.NET version from the script maps */
            for (i = 1; i < ASP_VER_MAX; ++i)
            {
                if (xmlStrstr(smaps, BAD_CAST asp_ver_str[i]) != NULL)
                {
                    asp = xmlStrdup(BAD_CAST asp_ver_str[i]);

                    break;
                }
            }

            if (asp == NULL)
            {
                /* assume default */
                asp = xmlStrdup(BAD_CAST asp_ver_str[0]);
            }

            printf("%s | %-32s | %s\n", asp, pool, domain);

            free(domain);
            free(pool);
            free(smaps);
            free(asp);
        }
    }

    return DUMP_ERROR_OK;
}

/**
 * Parse XML file
 *
 * @params  filename: the file name to parse
 * @return  void
 */
void xml_parse(const char *fp)
{
    xmlTextReaderPtr rp = NULL;
    int rc;

    rp = xmlReaderForFile(fp, NULL, 0);

    if (rp != NULL)
    {
        while (1)
        {
            rc = xmlTextReaderRead(rp);

            if (rc != 1)
            {
                break;
            }

            xml_element_dump(rp);
        }

        xmlFreeTextReader(rp);

        if (rc != 0)
        {
            fprintf(stderr, "Failed to parse: %s\n", fp);
        }
    }
    else
    {
        fprintf(stderr, "Unable to open: %s\n", fp);
    }

    return;
}
#endif
