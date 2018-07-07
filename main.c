/**
 * IIS 6 Website Information v0.2
 * Last updated: 24/10/2011
 *
 * Copyright (C) 2011 Quetzy Garcia <quetzyg@altek.org>
 */

#include "iis6wi.h"

#ifdef LIBXML_READER_ENABLED

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("%s v%s\n\nUsage: %s <MetaBase.xml>\n", APP_NAME, APP_VERSION, argv[0]);

        return EXIT_SUCCESS;
    }

    /*
     * this initializes the library and checks potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION

    xml_parse(argv[1]);

    /*
     * cleanup function for the XML library.
     */
    xmlCleanupParser();

    return EXIT_SUCCESS;
}

#else

int main(void)
{
    fprintf(stderr, "XInclude support not compiled in\n");

    return EXIT_FAILURE;
}

#endif
