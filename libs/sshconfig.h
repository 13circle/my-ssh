#ifndef _SSHCONFIG_H
#define _SSHCONFIG_H

#include "syslibs.h"

typedef struct _SSH_Config {
  char config_name[45];
  char host_addr[256];
  char user_id[256];
  char key[128];
} Config;

Config* create_config(const char *config_name, const char *host_addr, const char *user_id, const char *key) {
  Config *new_node;
  new_node = (Config *)malloc(sizeof(Config));
  
  new_node->config_name = (char *)malloc(sizeof(char) * (strlen(config_name) + 1);
  strcpy(new_node->config_name, config_name);

  new_node->host_addr = (char *)malloc(sizeof(char) * (strlen(host_addr) + 1));
  strcpy(new_node->host_addr, host_addr);

  new_node->user_id = (char *)malloc(sizeof(char) * (strlen(user_id) + 1));
  strcpy(new_node->user_id, user_id);

  new_node->key = (char *)malloc(sizeof(char) * (strlen(key) + 1));
  strcpy(new_node->key, key);

  return new_node;
}

#endif
