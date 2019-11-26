#ifndef VM_H
# define VM_H

# include <ncurses.h>
# include "libft/libft.h"
# include "../includes/corewar.h"
# include "../includes/op.h"

# define MAGIC_NUM_B 4
# define NULL_B 4
# define HALF_SIZE PROG_NAME_LENGTH + COMMENT_LENGTH + NULL_B * 2
# define FILE_SIZE HALF_SIZE + MAGIC_NUM_B + CHAMP_MAX_SIZE + MAGIC_NUM_B

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

# define FIRST_ARG	1
# define SECOND_ARG	2
# define THIRD_ARG	3

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
	t_champ					*champ;
	unsigned char			commmand;
	size_t 					last_breath;//last raund with live
	size_t 					its_a_highnoon;//time to do com
	size_t 					index;
	size_t					live_op;
	int 					aim;//count of byts to jump next
	unsigned int			*regs;
	char					color;
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
	size_t 					death_gaze;
	int 					doomsday_clock;//cycle_to_die count
	size_t					champ_num;
	int						cycle_to_die;
	int						last_stand;
	int						all_bogies;
	int						max_bogie_num;
	t_bogie					*bogie_head;
	t_champ					*champs;
}							t_coliseum;

t_coliseum					*g_arena;

typedef struct				s_windows
{
	WINDOW					*main_win;
	WINDOW					*arena;
	WINDOW					*infowin;
	long long				delay;
}							t_windows;

typedef struct				s_flags
{
	int 					i;
	int						dump;
	int						n;
	int						v;
	int						a;
}							t_flags;

t_flags						*g_flags;

t_champ						*parse_args(int c, char **a);
int							parse_bytecode(t_champ *champ, char *file);

int							add_champion(char *file, int index, t_champ **champs);
int							count_champs(t_champ *champs);
void						delete_champs(t_champ *head);
void						introduce_champs(void);
void						introduce_winner(void);

int							ft_errno(int x);
size_t						scip_null_border(size_t i);
int							ft_rstrcmp(const char *str1, const char *str2);

void						init_battlefield(t_champ *warriors, int num);
void						battlefield_print(void);

int							define_cycles_to_exec(unsigned char com);

void						add_bogies_on_arena(void);
t_bogie						*create_bogie(size_t c);
void						copy_bogie(t_bogie *new, t_bogie *bogie);
t_bogie						*delete_bogie(t_bogie *bogie);

void						fight(void);
void						lives_check(void);

size_t						count_bogies(void);

int							is_treg(unsigned char arg_byte, int position);
int							is_tdir(unsigned char arg_byte, int position);
int							is_tind(unsigned char arg_byte, int position);
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
void						print_4bytes(int a1, int a2, int a3, int flag_l);
void						get_data_for_bogie(int current);

t_windows					*init_w(void);
void						print_wins(t_windows *wins);
void						delete_windows(t_windows *wins);
void						control_input(t_windows *wins);
int							search_live_in_bogie(int champ_index);
int							search_last_breath(int champ_index);

void						delete_arena(void);
#endif