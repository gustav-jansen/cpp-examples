#include <iostream>
#include <string>
#include <unistd.h>
#include <getopt.h>


int main(int argc, char *argv[]) {
  std::string  configfile;

  static struct option options[] = {
    {"conf", required_argument, 0, 'c'},
    {0, 0, 0, 0}
  };
  int c;
  while (1) {
    int idx = 0;
    c = getopt_long(argc, argv, "c:", options, &idx);

    if ( c == -1 ) break;
    switch (c) {
      case 'c':
        configfile = optarg;
        break;
      default:
        abort();
    }
  }

  std::cout << "Configfile: " << configfile << std::endl;

  return 0;
}

