#include "vm.h"

int	all_three(unsigned char	arg_byte, int num)
{
	int arg;

	if (is_treg(arg_byte, num))
	{
		arg = g_bogies->regs[get_treg(g_bogies->aim)];
		g_bogies->aim++;
	}
	else if (is_tdir(arg_byte, num))
	{
		arg = get_tdir_small_size(g_bogies->index + g_bogies->aim);
		g_bogies->aim += 2;
	}
	else
	{
		arg = get_tind(0, g_bogies->index + g_bogies->aim);
		g_bogies->aim += 2;
	}
	return (arg);
}

int reg_dir(unsigned char arg_byte, int num)
{
	int arg;

	if (is_treg(arg_byte, num))
	{
		arg = g_bogies->regs[get_treg(g_bogies->aim)];
		g_bogies->aim++;
	}
	else
	{
		arg = get_tdir_small_size(g_bogies->index + g_bogies->aim);
		g_bogies->aim += 2;
	}
	return (arg);
}

void	print_4bytes(int a1, int a2, int a3, int flag_l)
{
	int c;

	if (flag_l)
		c =  a1 + a2;
	else
		c = (a1 + a2) % IDX_MOD;
//	if (g_arena->round > 930)
//	{
//		printf("c %d\n", c);
//		printf("reg %x regnum %d\n",  g_bogies->regs[a3], a3);
//	}
	a3 = g_bogies->regs[a3];
	c = (g_bogies->index + c) % MEM_SIZE;
//	if (g_arena->round > 930)
//		printf("index %d reg %x ind %d\n",g_bogies->index, a3 , c);
	g_arena->list[c].com = a3 >> 24;
	g_arena->list[c].color = g_bogies->color;
	g_arena->list[(1 + c) % MEM_SIZE].com = (a3 << 8) >> 24;
	g_arena->list[(1 + c) % MEM_SIZE].color = g_bogies->color;
	g_arena->list[(2 + c) % MEM_SIZE].com = (a3 << 16) >> 24;
	g_arena->list[(2 + c) % MEM_SIZE].color = g_bogies->color;
	g_arena->list[(3 + c) % MEM_SIZE].com = (a3 << 24) >> 24;
	g_arena->list[(3 + c) % MEM_SIZE].color = g_bogies->color;
}

void ldi(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;

	if (g_bogies->its_a_highnoon != g_arena->round)
		return ;
	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 2;
	if (is_tind(arg_byte, SECOND_ARG) || is_tind(arg_byte, THIRD_ARG) || is_tdir(arg_byte, THIRD_ARG))
	{
		skip_bytes(LDI_OP);
		return ;
	}
	arg_1 = all_three(arg_byte, FIRST_ARG);
	arg_2 = reg_dir(arg_byte, SECOND_ARG);
	arg_3 = get_treg(g_bogies->aim);
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | ldi %d %d r%d\n       | -> load from %d + %d = %d (with pc and mod %d)\n", g_bogies->num,
				arg_1, arg_2, arg_3 + 1, arg_1, arg_2, arg_1 + arg_2, g_bogies->index + ((arg_1 + arg_2) % IDX_MOD));
	g_bogies->regs[arg_3] = get_tdir_big_size(g_bogies->index + ((arg_1 + arg_2) % IDX_MOD));
	move_caret(g_bogies->aim);
	g_bogies->aim = 0;
}

void sti(void)
{
	int				arg_1 = 0;
	int				arg_2 = 0;
	int				arg_3 = 0;
	unsigned char	arg_byte = 0;

	if (is_tind(arg_byte, THIRD_ARG) || is_tind(arg_byte, FIRST_ARG) || is_tdir(arg_byte, FIRST_ARG))
	{
		skip_bytes(STI_OP);
		return ;
	}
	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	arg_1 = get_treg(2);
	g_bogies->aim = 3;
	arg_2 = all_three(arg_byte, SECOND_ARG);
	arg_3 = reg_dir(arg_byte, THIRD_ARG);
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | sti r%d %d %d\n       | -> store to %d + %d = %d (with pc and mod %d)\n", g_bogies->num, arg_1 + 1,
				arg_2, arg_3, arg_2, arg_3, arg_2 + arg_3, g_bogies->index + ((arg_2 + arg_3) % IDX_MOD));
	print_4bytes(arg_2, arg_3, arg_1, 0);
	move_caret(g_bogies->aim - 1);
}

void lldi(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;

	if (g_bogies->its_a_highnoon != g_arena->round)
		return ;
	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	arg_1 = 0;
	arg_2 = 0;
	g_bogies->aim = 2;
	if (is_tind(arg_byte, SECOND_ARG) || is_tind(arg_byte, THIRD_ARG) || is_tdir(arg_byte, THIRD_ARG))
	{
		skip_bytes(LLDI_OP);
		return ;
	}
	arg_1 = all_three(arg_byte, FIRST_ARG);
	arg_2 = reg_dir(arg_byte, SECOND_ARG);
	arg_3 = get_treg(g_bogies->aim);
	ft_printf("P %4d | lldi %d %d r%d\n       | -> load from %d + %d = %d (with pc and mod %d)\n", g_bogies->num,
			  arg_1, arg_2, arg_3 + 1, arg_1, arg_2, arg_1 + arg_2, g_bogies->index + ((arg_1 + arg_2) % IDX_MOD));
	g_bogies->regs[arg_3] = get_tdir_big_size(g_bogies->index + ((arg_1 + arg_2) % IDX_MOD));
	move_caret(g_bogies->aim);
	g_bogies->aim = 0;
}