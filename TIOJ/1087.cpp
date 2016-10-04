#include "lib1087.h"
using namespace std;

int main() {
  Initialize();
  int com_pile, com_num;
  int one = 10, two = 15, three = 20;
  Take_Stone(1, 1, &com_pile, &com_num);
  while (true) {
    if (com_pile == 1 && one > 1) {
      one -= com_num;
      Take_Stone(1, one - 1, &com_pile, &com_num);
    } else if (com_pile == 2 && two > 1) {
      two -= com_num;
      Take_Stone(2, two - 1, &com_pile, &com_num);
    } else if (com_pile == 3 && three > 1) {
      three -= com_num;
      Take_Stone(3, three - 1, &com_pile, &com_num);
    } else if (com_pile == 1 && one - com_num == 0) {
      if (two > 1) Take_Stone(2, two - 1, &com_pile, &com_num);
      else Take_Stone(3, three - 1, &com_pile, &com_num);
    } else if (com_pile == 2 && two - com_num == 0) {
      if (one > 1) Take_Stone(1, one - 1, &com_pile, &com_num);
      else Take_Stone(3, three - 1, &com_pile, &com_num);
    } else {
      if (two > 1) Take_Stone(2, two - 1, &com_pile, &com_num);
      else Take_Stone(1, one - 1, &com_pile, &com_num);
    }
  }
}
