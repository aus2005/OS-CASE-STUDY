typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;

struct procstat {
  int pid;
  int ppid;
  char name[16];
  char state[10];
  uint start_ticks;
  uint cpu_ticks;
  uint sz;
};
