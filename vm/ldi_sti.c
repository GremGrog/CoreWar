#include "vm.h"

// int	all_three(unsigned char	arg_byte, int num, int *s)
// {
// 	int arg;

// 	if (is_treg(arg_byte, num))
// 	{
// 		if (get_treg(g_bogies->aim) >= 16)
// 			*s = 1;
// 		arg = g_bogies->regs[get_treg(g_bogies->aim)];
// 		g_bogies->aim++;
// 	}
// 	else if (is_tdir(arg_byte, num))
// 	{
// 		arg = get_tdir_small_size(g_bogies->index + g_bogies->aim);
// 		g_bogies->aim += 2;
// 	}
// 	else
// 	{
// 		arg = get_tind(1, g_bogies->aim);
// 		g_bogies->aim += 2;
// 	}
// 	return (arg);
// }

// int reg_dir(unsigned char arg_byte, int num, int *s)
// {
// 	int arg;
// 	int	reg;

// 	if (is_treg(arg_byte, num))
// 	{
// 		reg = get_treg(g_bogies->aim);
// 		if (reg >= 16)
// 			*s = 1;
// 		arg = g_bogies->regs[reg];
// 		g_bogies->aim++;
// 	}
// 	else
// 	{
// 		arg = get_tdir_small_size(g_bogies->index + g_bogies->aim);
// 		g_bogies->aim += 2;
// 	}
// 	return (arg);
// }

void	print_4bytes(int a1, int a2, int a3, int flag_l)
{
	int c;

	if (flag_l)
		c =  a1 + a2;
	else
		c = (a1 + a2) % IDX_MOD;
	a3 = g_bogies->regs[a3];
	c = (g_bogies->index + c) % MEM_SIZE;
	g_arena->list[c].com = a3 >> 24;
	g_arena->list[c].color = g_bogies->color;
	g_arena->list[c].champ = g_bogies->num * (-1);
	g_arena->list[(1 + c) % MEM_SIZE].com = (a3 << 8) >> 24;
	g_arena->list[(1 + c) % MEM_SIZE].color = g_bogies->color;
	g_arena->list[(1 + c) % MEM_SIZE].champ = g_bogies->num * (-1);
	g_arena->list[(2 + c) % MEM_SIZE].com = (a3 << 16) >> 24;
	g_arena->list[(2 + c) % MEM_SIZE].color = g_bogies->color;
	g_arena->list[(2 + c) % MEM_SIZE].champ = g_bogies->num * (-1);
	g_arena->list[(3 + c) % MEM_SIZE].com = (a3 << 24) >> 24;
	g_arena->list[(3 + c) % MEM_SIZE].color = g_bogies->color;
	g_arena->list[(3 + c) % MEM_SIZE].champ = g_bogies->num * (-1);
}

int reg_or_dir(int *arg, unsigned char arg_byte, int num)
{
	int	reg;

	if (is_treg(arg_byte, num))
	{
		if ((reg = get_treg(g_bogies->aim)) < 16)
		{
			g_bogies->aim++;
			*arg = g_bogies->regs[reg];
			return (1);
		}
	}
	else if (is_tdir(arg_byte, num))
	{
		*arg = get_tdir_small_size(g_bogies->index + g_bogies->aim);
		g_bogies->aim += 2;
		return (1);
	}
	return (-1);
}

int	get_small_arg(int *arg, int position, unsigned char arg_byte)
{
	int	reg;

	if (is_treg(arg_byte, position))
	{
		reg = 0;
		if ((reg = get_treg(g_bogies->aim)) < 16)
		{
			*arg = g_bogies->regs[reg];
			g_bogies->aim++;
			return (1);
		}
		else
			return (-1);
	}
	else if (is_tdir(arg_byte, position))
	{
		*arg = get_tdir_small_size(g_bogies->index + g_bogies->aim);
		g_bogies->aim += 2;
		return (1);
	}
	else if (is_tind(arg_byte, position))
	{
		*arg = get_tind(1, g_bogies->aim);
		g_bogies->aim += 2;
		return (1);
	}
	return (-1);
}

void ldi(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;
	int				res;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 2;
	arg_1 = 0;
	arg_2 = 0;
	arg_3 = 0;
	res = 0;
	if ((get_small_arg(&arg_1, FIRST_ARG, arg_byte)) == -1 || (reg_or_dir(&arg_2, arg_byte, SECOND_ARG) == -1) || 
		((!(is_treg(arg_byte, THIRD_ARG))) || (arg_3 = get_treg(g_bogies->aim)) >= 16))
		{
			skip_bytes(LDI_OP);
			return ;
		}
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | ldi %d %d r%d\n       | -> load from %d + %d = %d (with pc and mod %d)\n", g_bogies->num,
				arg_1, arg_2, arg_3 + 1, arg_1, arg_2, arg_1 + arg_2, g_bogies->index + ((arg_1 + arg_2) % IDX_MOD));
	res = (arg_1 + arg_2) % IDX_MOD;
	g_bogies->regs[arg_3] = get_tdir_big_size((g_bogies->index + res) % MEM_SIZE);
	move_caret(g_bogies->aim + 1);
}

void lldi(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 2;
	arg_1 = 0;
	arg_2 = 0;
	arg_3 = 0;
	if ((get_small_arg(&arg_1, FIRST_ARG, arg_byte)) == -1 || (reg_or_dir(&arg_2, arg_byte, SECOND_ARG) == -1) || 
		((!(is_treg(arg_byte, THIRD_ARG))) || (arg_3 = get_treg(g_bogies->aim)) >= 16))
		{
			skip_bytes(LLDI_OP);
			return ;
		}
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | lldi %d %d r%d\n       | -> load from %d + %d = %d (with pc %d)\n", g_bogies->num,
			  arg_1, arg_2, arg_3 + 1, arg_1, arg_2, arg_1 + arg_2, g_bogies->index + (arg_1 + arg_2));
	g_bogies->regs[arg_3] = get_tdir_big_size(g_bogies->index + (arg_1 + arg_2));
	if (!(is_treg(arg_1, FIRST_ARG)))
		g_bogies->carry = ((arg_1 == 0) ? 1 : 0);
	move_caret(g_bogies->aim + 1);
}

void sti(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;

	arg_1 = 0;
	arg_2 = 0;
	arg_3 = 0;
	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 2;
	if ((!(is_treg(arg_byte, FIRST_ARG))) || (arg_1 = get_treg(g_bogies->aim++)) >= 16 || 
	((get_small_arg(&arg_2, SECOND_ARG, arg_byte)) == -1 || (reg_or_dir(&arg_3, arg_byte, THIRD_ARG) == -1)))
	{
		skip_bytes(STI_OP);
		return ;
	}
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | sti r%d %d %d\n       | -> store to %d + %d = %d (with pc and mod %d)\n", g_bogies->num, arg_1 + 1,
				arg_2, arg_3, arg_2, arg_3, arg_2 + arg_3, g_bogies->index + ((arg_2 + arg_3) % IDX_MOD));
	print_4bytes(arg_2, arg_3, arg_1, 0);
	move_caret(g_bogies->aim);
}

// void ldi(void)
// {
// 	int				arg_1;
// 	int				arg_2;
// 	int				arg_3;
// 	int 			*s;
// 	unsigned char	arg_byte;

// 	s = 0;
// 	if (g_bogies->its_a_highnoon != g_arena->round)
// 		return ;
// 	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
// 	g_bogies->aim = 2;
// 	if (is_tind(arg_byte, SECOND_ARG) || is_tind(arg_byte, THIRD_ARG) || is_tdir(arg_byte, THIRD_ARG))
// 	{
// 		skip_bytes(arg_byte);
// 		return ;
// 	}
// 	arg_1 = all_three(arg_byte, FIRST_ARG, s);
// 	arg_2 = reg_dir(arg_byte, SECOND_ARG, s);
// 	arg_3 = get_treg(g_bogies->aim);
// 	if (arg_3 >= 16)
// 		*s = 1;
// 	if (g_flags->v == 1 || g_flags->v == 30)
// 		ft_printf("P %4d | ldi %d %d r%d\n       | -> load from %d + %d = %d (with pc and mod %d)\n", g_bogies->num,
// 				arg_1, arg_2, arg_3 + 1, arg_1, arg_2, arg_1 + arg_2, g_bogies->index + ((arg_1 + arg_2) % IDX_MOD));
// 	g_bogies->regs[arg_3] = get_tdir_big_size(g_bogies->index + ((arg_1 + arg_2) % IDX_MOD));
// 	if (s)
// 		skip_bytes(LDI_OP);
// 	move_caret(g_bogies->aim + 1);
// }

// void sti(void)
// {
// 	int				arg_1 = 0;
// 	int				arg_2 = 0;
// 	int				arg_3 = 0;
// 	int 			*s;
// 	unsigned char	arg_byte = 0;

// 	s = 0;
// 	if (is_tind(arg_byte, THIRD_ARG) || is_tind(arg_byte, FIRST_ARG) || is_tdir(arg_byte, FIRST_ARG))
// 	{
// 		skip_bytes(STI_OP);
// 		return ;
// 	}
// 	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
// 	arg_1 = get_treg(2);
// 	if (arg_1 >= 16)
// 		*s = 1;
// 	g_bogies->aim = 3;
// 	arg_2 = all_three(arg_byte, SECOND_ARG, s);
// 	arg_3 = reg_dir(arg_byte, THIRD_ARG, s);
// 	if (g_flags->v == 1 || g_flags->v == 30)
// 		ft_printf("P %4d | sti r%d %d %d\n       | -> store to %d + %d = %d (with pc and mod %d)\n", g_bogies->num, arg_1 + 1,
// 				arg_2, arg_3, arg_2, arg_3, arg_2 + arg_3, g_bogies->index + ((arg_2 + arg_3) % IDX_MOD));
// 	print_4bytes(arg_2, arg_3, arg_1, 0);
// 	if (s)
// 		skip_bytes(LDI_OP);
// 	move_caret(g_bogies->aim);
// }

// void lldi(void)
// {
// 	int				arg_1;
// 	int				arg_2;
// 	int				arg_3;
// 	int 			*s;
// 	unsigned char	arg_byte;

// 	s = 0;
// 	if (g_bogies->its_a_highnoon != g_arena->round)
// 		return ;
// 	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
// 	arg_1 = 0;
// 	arg_2 = 0;
// 	g_bogies->aim = 2;
// 	if (is_tind(arg_byte, SECOND_ARG) || is_tind(arg_byte, THIRD_ARG) || is_tdir(arg_byte, THIRD_ARG))
// 	{
// 		skip_bytes(arg_byte);
// 		return ;
// 	}
// 	arg_1 = all_three(arg_byte, FIRST_ARG, s);
// 	arg_2 = reg_dir(arg_byte, SECOND_ARG, s);
// 	arg_3 = get_treg(g_bogies->aim);
// 	if (!(is_treg(arg_1, FIRST_ARG)))
// 		g_bogies->carry = ((arg_1 == 0) ? 1 : 0);
// 	if (arg_3 >= 16)
// 		*s = 1;
// 	if (g_flags->v == 1 || g_flags->v == 30)
// 		ft_printf("P %4d | lldi %d %d r%d\n       | -> load from %d + %d = %d (with pc %d)\n", g_bogies->num,
// 			  arg_1, arg_2, arg_3 + 1, arg_1, arg_2, arg_1 + arg_2, g_bogies->index + ((arg_1 + arg_2) % IDX_MOD));
// 	g_bogies->regs[arg_3] = get_tdir_big_size(g_bogies->index + ((arg_1 + arg_2)));
// 	if (s)
// 		skip_bytes(LDI_OP);
// 	move_caret(g_bogies->aim + 1);
// }