#ifndef VM_H
# define VM_H

# include <ncurses.h>
# include "libft/libft.h"
# include "../includes/corewar.h"
# include "../includes/op.h"

# define MAGIC_NUM_B 4
# define NULL_B 4
# define HALF_SIZE PROG_NAME_LENGTH + COMMENT_LENGTH + NULL_B * 2
# define FILE_SIZE HALF_SIZE + MAGIC_NUM_B + CHAMP_MAX_SIZE

# define LIVE		10
# define LD			5
# define ST			5
# define ADD		10
# define SUB		10
# define AND		6
# define OR			6
# define XOR		6
# define ZJMP		20
# define LDI		25
# define STI		25
# define FORK		800
# define LLD		10
# define LLDI		50
# define LFORK		1000
# define AFF		2

# define LIVE_OP	0
# define LD_OP		1
# define ST_OP		2
# define ADD_OP		3
# define SUB_OP		4
# define AND_OP		5
# define OR_OP		6
# define XOR_OP		7
# define ZJMP_OP	8
# define LDI_OP		9
# define STI_OP		10
# define FORK_OP	11
# define LLD_OP		12
# define LLDI_OP	13
# define LFORK_OP	14
# define AFF_OP		15

# define IS_T_REG(val, pos) (((val >> pos) & REG_CODE) == REG_CODE) ? 1 : 0
# define IS_T_DIR(val, pos) (((val >> pos) & DIR_CODE) == DIR_CODE) ? 1 : 0
# define IS_T_IND(val, pos) (((val >> pos) & IND_CODE) == IND_CODE) ? 1 : 0

# define FIRST_ARG	6
# define SECOND_ARG	4
# define THIRD_ARG	2

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
	unsigned char			commmand;
	size_t 					last_breath;//last raund with live
	size_t 					its_a_highnoon;//time to do com
	size_t 					index;
	int 					aim;//count of byts to jump next
	int						*regs;
	struct s_bogie			*next;
	//color defolt white
}							t_bogie;

t_bogie						*g_bogies;

typedef  struct 			s_com
{
	unsigned char			com;
	int						bogie;
	int						champ;
	char					color;
}							t_com;

typedef  struct 			s_coliseum // arena
{
	t_com					list[MEM_SIZE];
	size_t 					round;//global count
	size_t 					mortal_flip;//live count
	int 					doomsday_clock;//cycle_to_die count
	size_t					champ_num;
	int						last_stand;
	int						all_bogies;
}							t_coliseum;

t_coliseum					*g_arena;

t_champ						*parse_args(int c, char **a);
void						parse_bytecode(t_champ *champ, char *file);

int							add_champion(char *file, int index, t_champ **champs);
int							count_champs(t_champ *champs);
void						delete_champs(t_champ *head);

int							ft_errno(int x);
size_t						scip_null_border(size_t i);
int							ft_rstrcmp(const char *str1, const char *str2);

void						init_battlefield(t_champ *warriors, int num);
void						battlefield_print(void);

int							define_cycles_to_exec(unsigned char com);

void						add_bogies_on_arena(void);
t_bogie						*create_bogie(void);
void						copy_bogie(t_bogie *new, t_bogie *bogie);
void						delete_bogie(t_bogie *bogie);

void						fight(t_champ *champs);

int							get_tdir_big_size(int i);
short						get_tdir_small_size(int i);
int							get_treg(int scip_size);
int							get_tind(int size_flag, int scip_size);
void						move_caret(int steps);
void						skip_bytes(int op_code);

void						load(void);
void						long_load(void);
void						store(void);
void						addition(void);
void						subtraction(void);
void						bitwise_and(void);
void						bitwise_or(void);
void						bitwise_xor(void);
void						live(void);
void						zjump(void);
void						ft_fork(void);
void						long_fork(void);
void						aff(void);
void						ldi(void);
void						sti(void);
void						lldi(void);

void						visualisator(void);

#endif