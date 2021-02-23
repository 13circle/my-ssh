#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_BUF 128

typedef struct _Script_Name {
  char *name;
  struct _Script_Name *next;
} Script;

Script* get_scripts_list(const char *base_dir) {
  struct dirent *dir;
  DIR *d;
  int i, cnt;
  Script *tmp, *scripts = NULL;

  d = opendir(base_dir);

  if (d) {
    i = 1;

    while ((dir = readdir(d))) {
      if (dir->d_type != DT_DIR) {
        tmp = (Script *)malloc(sizeof(Script));
        tmp->name = (char *)malloc(sizeof(char) * (strlen(dir->d_name) + 1));
        tmp->next = NULL;
        strcpy(tmp->name, dir->d_name);

        if (scripts) scripts->next = tmp;
        else scripts = tmp;

        printf("[%d] %s \n", i++, tmp->name);
      }
    }

    closedir(d);
  } else { // !d
    printf("%s: cannot open directory \n", base_dir);
  }

  return scripts;
}

char* select_script(Script *scripts, int menu_num) {
  Script *tmp;
  int i;
  char *selected = NULL;

  for (tmp = scripts, i = 1; tmp; tmp = tmp->next, i++) {
    if (i == menu_num) break;
  }

  if (tmp) selected = tmp->name;

  return selected;
}

void close_script_list(Script *scripts) {
  Script *tmp;
  
  while (scripts) {
    tmp = scripts;
    scripts = scripts->next;
    free(tmp->name);
    free(tmp);
  }
}

int main(int ac, char *av[]) {
  char base_dir[MAX_BUF];
  int menu_num = 0;
  Script *scripts;
  char *selected, *full_path;

  strcpy(base_dir, getenv("HOME"));
  strcat(base_dir, "/.myssh/sshconnect");

  printf("\nSSH Client Shell Scripts \n");
  printf("-------- \n");
  scripts = get_scripts_list(base_dir);
  printf("-------- \n\n");

  printf("[Enter # (exit:0)]: ");
  if (scanf("%d", &menu_num) == 1) {
    if (menu_num == 0) {
      printf("Exit process \n");
      return 0;
    }

    selected = select_script(scripts, menu_num);

    full_path = (char *)malloc(sizeof(char) * (strlen(base_dir) + strlen(selected) + 3));
    strcpy(full_path, base_dir);
    strcat(full_path, "/");
    strcat(full_path, selected);

    close_script_list(scripts);

    system(full_path);
    
    free(full_path);
  }

  printf("Enter \"myssh\" again to restart \n");
  return 0;
}

