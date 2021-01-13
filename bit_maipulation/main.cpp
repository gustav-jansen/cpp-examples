#include <bitset>
#include <cstdint>
#include <iostream>

int main() {
  uint16_t i = 1, j;
  uint8_t d[2];
  d[0] = (uint8_t) i<<0;
  d[1] = (uint8_t) i<<8;
  j = (d[0]<<0) | (d[1]<<8); 
  /* The bit representation of a variable is always defined mathematically
   * as the least significant bit last and the most significant bit first,
   * independent of how the variable is stored in memory." */

  /* Consequences:
   * (unint8_t) i<<0 returns the 8 least significant bits in i. if i==1,
   * (unint8_t) i<<0 gives 00000001, while (unint8_t) i<<8 gives 00000000.
   * However, (unit16_t) (i<<8) gives 0000000100000000. */

  std::cout << "          1111111111222222222233" << std::endl;
  std::cout << "01234567890123456789012345678901" << std::endl;
  std::cout << std::bitset<sizeof(i) * 8>(i) << std::endl;
  std::cout << std::bitset<sizeof(uint8_t) * 8>(d[0]) << std::bitset<sizeof(uint8_t) * 8>(d[1]) << std::endl;
  std::cout << std::bitset<sizeof(j) * 8>(j) << std::endl;
  std::cout << std::bitset<32>(d[0]<<0) << std::endl;
  std::cout << std::bitset<32>(d[0]<<8) << std::endl;
  std::cout << std::bitset<32>(d[0]<<16) << std::endl;
  std::cout << std::bitset<32>(d[0]<<24) << std::endl;
  std::cout << std::bitset<16>((uint16_t)(d[0]<<8)) << std::endl;
  return 0;  
}
