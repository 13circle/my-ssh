#include "./syslibs.h"
#include "./sshconfig.h"

int main(int ac, char *av[]) {
  
  // myssh -u USER_NAME [-r,--register|-o,--open] [CONFIG_NAME]
  if (ac >= 3) {
    fprintf(stderr, "Error: Wrong Arguments \n");
    fprintf(stderr, "%s -u USER_NAME [-r,--register|-o,--open] [CONFIG_NAME] \n", av[0]);
    return EXIT_FAILURE;
  }

  if (strcmp(av[1], "-u")) {
    fprintf(stderr, "Username not specified. \n");
    fprintf(stderr, "%s -u USER_NAME [-r,--register|-o,--open] [CONFIG_NAME] \n", av[0]);
    return EXIT_FAILURE;
  }

  // ...

  return 0;
}
