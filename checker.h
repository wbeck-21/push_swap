/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:17:11 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/08 18:47:28 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

char	*get_next_line(int fd);
char	*ft_strjoin_checker(char *str1, char *str2);
int		ft_strchr_checker(char *str);
size_t	ft_strlen_checker(const char *str);

void	ft_pa_checker(t_stack **stack_a, t_stack **stack_b);
void	ft_pb_checker(t_stack **stack_a, t_stack **stack_b);

void	ft_sa_checker(t_stack **stack_a);
void	ft_sb_checker(t_stack **stack_b);
void	ft_ss_checker(t_stack **stack_a, t_stack **stack_b);

void	ft_ra_checker(t_stack **stack_a);
void	ft_rb_checker(t_stack **stack_b);
void	ft_rr_checker(t_stack **stack_a, t_stack **stack_b);

void	ft_rra_checker(t_stack **stack_a);
void	ft_rrb_checker(t_stack **stack_b);
void	ft_rrr_checker(t_stack **stack_a, t_stack **stack_b);

#endif