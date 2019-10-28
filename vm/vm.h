#ifndef VM_H
# define VM_H

# include "ft_printf/include/head.h"
# define MAX_PLAYERS 4
# define MEM_SIZE (4 * 1024)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

# define LIVE 10
# define LD 5
# define ST 5
# define ADD 10
# define SUB 10
# define AND 6
# define OR 6
# define XOR 6
# define ZJMP 20
# define LDI 25
# define STI 25
# define FORK 800
# define LLD 10
# define LLDI 50
# define LFORK 1000
# define AFF 2

typedef struct s_champ
{
  char    *name;
  char    *comm;
  char    *code;
  t_champ *next;
}              t_champ;
