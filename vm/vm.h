#ifndef VM_H
# define VM_H

# include "ft_printf/include/head.h"
# include "op.h"

# define MAGIC_NUM_B 4
# define NULL_B 4
# define HALF_SIZE PROG_NAME_LENGTH + COMMENT_LENGTH + NULL_B * 2
# define FILE_SIZE HALF_SIZE + MAGIC_NUM_B + CHAMP_MAX_SIZE

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

typedef struct				s_champ
{
	size_t 						index;
	char						*name;
	char						*comment;
	unsigned char				*code;
	size_t						code_size;
	struct s_champ				*next;
}							t_champ;

typedef	struct				s_bogie
{
	int 					num;
	int 					carry;
	short					com;
	size_t 					last_breath;//last raund with live
	size_t 					its_a_highnoon;//time to do com
	size_t 					index;
	int 					aim;//count of byts to jump next
	short					reg;
	//color defolt white
}							t_bogie;

typedef  struct 			s_com
{
	unsigned char com;
	//colors
}							t_com;

typedef  struct 			s_coliseum // arena
{
	t_bogie					*jumper;
	t_com					list[MEM_SIZE];
	size_t 					raund;//global count
	size_t 					mortal_flip;//live count
	int 					doomsday_clock;//cycle_to_die count
}							t_coliseum;

typedef struct	s_globals
{
	t_champ*		last_stand;


}				t_globals;

void		parse_bytecode(t_champ *champ, char *file);
int			ft_errno(int x);
size_t		scip_null_border(size_t i);
int			ft_rstrcmp(const char *str1, const char *str2);
void		battlefield(t_champ *warriors, int num);

#endif