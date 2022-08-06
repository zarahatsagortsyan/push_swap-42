/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:02:10 by zhatsago          #+#    #+#             */
/*   Updated: 2022/04/05 19:02:15 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stacks *stacks)
{
	if (stacks->count_a <= 3)
		sort_3_element(stacks);
	else if (stacks->count_a <= 5)
		sort_5_element(stacks);
	else
		global_sort(stacks);
}

void	start(int argc, char **argv, t_data *new, t_stacks *stacks)
{
	array_separation(argc, argv, new);
	duplicate_check(new, stacks);
	if (is_sorted(new))
	{
		init_stack(new, stacks);
		sort(stacks);
		free_stack(stacks);
	}
}

int	main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		exit(1);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		exit(1);
	null(stacks, new);
	if (validation(argc, argv))
		start(argc, argv, new, stacks);
	free(new);
	free(stacks);
	return (0);
}
