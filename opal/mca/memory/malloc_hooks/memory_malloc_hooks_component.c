/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2005 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart, 
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * $COPYRIGHT$
 * 
 * Additional copyrights may follow
 * 
 * $HEADER$
 */

#include "ompi_config.h"

#include "opal/mca/memory/memory.h"
#include "opal/include/constants.h"

extern void opal_memory_malloc_hooks_init(void);
extern void opal_memory_malloc_hooks_finalize(void);

static int opal_memory_malloc_open(void);
static int opal_memory_malloc_close(void);

const opal_memory_base_component_1_0_0_t mca_memory_malloc_hooks_component = {
    /* First, the mca_component_t struct containing meta information
       about the component itself */
    {
        /* Indicate that we are a memory v1.0.0 component (which also
           implies a specific MCA version) */
        OPAL_MEMORY_BASE_VERSION_1_0_0,

        /* Component name and version */
        "malloc_hooks",
        OPAL_MAJOR_VERSION,
        OPAL_MINOR_VERSION,
        OPAL_RELEASE_VERSION,

        /* Component open and close functions */
        opal_memory_malloc_open,
        opal_memory_malloc_close
    },

    /* Next the MCA v1.0.0 component meta data */
    {
        /* Whether the component is checkpointable or not */
        true
    },
};


static int
opal_memory_malloc_open(void)
{
    opal_memory_malloc_hooks_init();
    return OPAL_SUCCESS;
}

static int
opal_memory_malloc_close(void)
{
    opal_memory_malloc_hooks_finalize();
    return OPAL_SUCCESS;
}
