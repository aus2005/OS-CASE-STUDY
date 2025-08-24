#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  printf(1, "System Uptime: %d ticks\n\n", uptime());
  

  int count = procinfo(0, 0); 
  
  printf(1, "\nTotal Active Processes: %d\n", count);
  
  exit();
} 
