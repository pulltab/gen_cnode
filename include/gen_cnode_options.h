#ifndef GEN_CNODE_OPTIONS_H
#define GEN_CNODE_OPTIONS_H

#include <glib.h>

typedef struct gen_cnode_opts_s {
    gchar* name;            //(Required) Name associated with cnode.
    gchar* host;            //(Required) Hostname associated with cnode. 
    guint16 port;           //(Required) Port on localhost on which to communicate.
    gint32 workers;         //(Optional) Number of worker threads (default unlimited).
    guint32 creation;       //(Optional) Numeric id of the node for short name mode.
    gchar* cookie;          //(Optional) Cookie used to decrypt/encrypt erlang messages.
} gen_cnode_opts_t;

extern gen_cnode_opts_t gen_cnode_opts;

/* CLA Specifications */
#define GEN_CNODE_PORT                                              \
    {                                                               \
        "port", 'p', 0, G_OPTION_ARG_INT, &(gen_cnode_opts.port),   \
        "Port to use for IPC", "<port>"                             \
    }                                                               \

#define GEN_CNODE_CREATION                                          \
    {                                                               \
        "creation", 'c', 0, G_OPTION_ARG_INT,                       \
        &(gen_cnode_opts.creation),                                 \
        "Creation number used for ei_connect_init.",                \
        "<creation>"                                                \
    }                                                               \

#define GEN_CNODE_WORKERS                                           \
    {                                                               \
        "workers", 'w', 0, G_OPTION_ARG_INT,                        \
        &(gen_cnode_opts.workers),                                  \
        "Number of worker threads for handling callbacks (default: unlimited)",          \
        "<#workers>"                                                \
    }     

#define GEN_CNODE_NAME                                              \
    {                                                               \
        "name", 'n', 0, G_OPTION_ARG_STRING,                        \
         &(gen_cnode_opts.name),                                    \
        "Node name used to identify the cnode",                     \
        "<node_name>"                                               \
    }                                                               \

#define GEN_CNODE_HOST                                              \
    {                                                               \
        "host", 'h', 0, G_OPTION_ARG_STRING,                        \
         &(gen_cnode_opts.host),                                    \
        "Host name used to identify the cnode",                     \
        "<host_name>"                                               \
    }   

#define GEN_CNODE_COOKIE                                            \
    {                                                               \
        "setcookie", 's', 0, G_OPTION_ARG_STRING,                   \
         &(gen_cnode_opts.cookie),                                  \
        "Secret used to encrypt/decrypt erlang messages",           \
        "<cookie>"                                                  \
    }                                                               \

extern gchar gen_cnode_opt_sname[];
extern gchar gen_cnode_opt_lname[];
extern gchar gen_cnode_opt_shows[];
extern GOptionEntry gen_cnode_opt_entries[];

#endif
