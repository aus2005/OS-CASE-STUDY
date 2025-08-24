#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid;
  uint start_time, end_time, start_cpu, end_cpu;
  
  if(argc < 2) {
    printf(1, "Usage: time command [args...]\n");
    exit();
  }
  
  start_time = uptime();
  start_cpu = systime(0);  // Current process CPU time
  
  pid = fork();
  if(pid < 0) {
    printf(1, "fork failed\n");
    exit();
  }
  
  if(pid == 0) {
   
    exec(argv[1], argv + 1);
    printf(1, "exec %s failed\n", argv[1]);
    exit();
  } else {
    wait();
    
    end_time = uptime();
    end_cpu = systime(0);
    
    printf(1, "\n=== Timing Results ===\n");
    printf(1, "Real time: %d ticks\n", end_time - start_time);
    printf(1, "CPU time:  %d ticks\n", end_cpu - start_cpu);
    
    if((end_time - start_time) > 0) {
      int cpu_percent = ((end_cpu - start_cpu) * 100) / (end_time - start_time);
      printf(1, "CPU usage: %d%%\n", cpu_percent);
    }
  }
  
  exit();
}
 