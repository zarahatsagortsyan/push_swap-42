/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:01:45 by zhatsago          #+#    #+#             */
/*   Updated: 2022/04/05 19:01:50 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	help_finding_place(t_stacks *s, t_stack *b, int *action, int *buff)
{
	while (s->a)
	{
		*buff = s->a->data;
		if (b->data > s->a->data)
		{
			*action += 1;
			if (b->data < s->a->next->data)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
	if (smaller_element_detection(s->a, *buff, b->data) == 1)
	{
		while (s->a)
		{
			if (s->a->data < *buff && s->a->data > b->data)
				break ;
			*action += 1;
			s->a = s->a->next;
		}
	}
}

int	finding_place(t_stacks *s, t_stack *b, t_steps *steps, int min)
{
	int	action;
	int	res;
	int	buff;

	action = 0;
	buff = 0;
	help_finding_place(s, b, &action, &buff);
	if (s->a->rotate == -1)
		action = s->count_a - action;
	if (min == -1 || (action + b->step) < min)
	{
		steps->dest_a = s->a->rotate;
		steps->dest_b = b->rotate;
		steps->count_a = action;
		steps->count_b = b->step;
		res = action + b->step;
	}
	else
		res = min;
	return (res);
}

int	smaller_element_detection(t_stack *a, int buff, int src)
{
	t_stack	*save;
	int		ret;

	save = a;
	ret = 0;
	while (save && ret == 0)
	{
		if (save->data < buff && save->data > src)
			ret = 1;
		save = save->next;
	}
	return (ret);
}

int	count_to_min(t_stack *a, int min)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->data == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}
