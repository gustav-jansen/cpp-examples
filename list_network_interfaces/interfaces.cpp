#include "interfaces.hpp"

#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

std::vector<interface> get_network_interfaces(void) {
  std::vector<interface> interfaces;
  char          buf[1024];
  struct ifconf ifc;
  struct ifreq *ifr;
  int           sck;
  int           nInterfaces;
  int           i;

  /* Get a socket handle. */
  sck = socket(AF_INET, SOCK_DGRAM, 0);
  if(sck < 0) {
    perror("socket");
    return interfaces;
  }

  /* Query available interfaces. */
  ifc.ifc_len = sizeof(buf);
  ifc.ifc_buf = buf;
  if(ioctl(sck, SIOCGIFCONF, &ifc) < 0) {
    perror("ioctl(SIOCGIFCONF)");
    return interfaces;
  }

  /* Iterate through the list of interfaces. */
  ifr         = ifc.ifc_req;
  nInterfaces = ifc.ifc_len / sizeof(struct ifreq);
  for(i = 0; i < nInterfaces; i++) {
    struct ifreq *item = &ifr[i];
    interfaces.push_back(interface(item->ifr_name, inet_ntoa(((struct sockaddr_in *)&item->ifr_addr)->sin_addr)));
  }

  return interfaces;
}
