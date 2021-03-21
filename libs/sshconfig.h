#ifndef _SSHCONFIG_H
#define _SSHCONFIG_H

#include "syslibs.h"

typedef struct _SSH_Config {
  char config_name[45];
  char host_addr[256];
  char user_id[256];
  char key[128];
} Config;

#endif
