/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:17:47 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/08 18:53:46 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	do_instrs(t_stack **stack_a, t_stack **stack_b, char *instr)
{
	if (ft_strncmp(instr, "sa\n", 5) == 0)
		ft_sa_checker(stack_a);
	else if (ft_strncmp(instr, "sb\n", 5) == 0)
		ft_sb_checker(stack_b);
	else if (ft_strncmp(instr, "ss\n", 5) == 0)
		ft_ss_checker(stack_a, stack_b);
	else if (ft_strncmp(instr, "pa\n", 5) == 0)
		ft_pa_checker(stack_a, stack_b);
	else if (ft_strncmp(instr, "pb\n", 5) == 0)
		ft_pb_checker(stack_a, stack_b);
	else if (ft_strncmp(instr, "ra\n", 5) == 0)
		ft_ra_checker(stack_a);
	else if (ft_strncmp(instr, "rb\n", 5) == 0)
		ft_rb_checker(stack_b);
	else if (ft_strncmp(instr, "rr\n", 5) == 0)
		ft_rr_checker(stack_a, stack_b);
	else if (ft_strncmp(instr, "rra\n", 5) == 0)
		ft_rra_checker(stack_a);
	else if (ft_strncmp(instr, "rrb\n", 5) == 0)
		ft_rrb_checker(stack_b);
	else if (ft_strncmp(instr, "rrr\n", 5) == 0)
		ft_rrr_checker(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	check_sort(t_stack **stack_a)
{
	t_stack	*next_elem;

	next_elem = *stack_a;
	while ((next_elem)->next != NULL)
	{
		if ((next_elem)->nbr < ((next_elem)->next)->nbr)
		{
			next_elem = (next_elem)->next;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}

void	console_sorting(t_stack **stack_a, t_stack **stack_b)
{
	char	*instr;

	while (1)
	{
		instr = get_next_line(0);
		if (instr == NULL)
		{
			if (check_sort(stack_a) && !ft_listsize(*stack_b))
				ft_putstr_fd("OK\n", 1);
			else
				ft_putstr_fd("KO\n", 1);
			break ;
		}
		if (!do_instrs(stack_a, stack_b, instr))
		{
			ft_putstr_fd("Error\ninstruction doesn’t exist\n", 1);
			free(instr);
			return ;
		}
		free(instr);
	}
}

int	is_valid(char **argv)
{
	if (!ft_checkarg(argv))
	{
		ft_putstr_fd("Error\nsome arguments aren’t integers\n", 1);
		return (0);
	}
	if (!ft_check_maxint(argv))
	{
		ft_putstr_fd("Error\nsome arguments are bigger/smaller than an int\n", 1);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc >= 2)
	{
		if (!is_valid(argv))
			return (0);
		stack_a = fill_stack_a(&stack_a);
		console_sorting(&stack_a, &stack_b);
		free(stack_a);
		free(stack_b);
	}
	else
		ft_putstr_fd("There're not any args\n", 1);
	return (0);
}
