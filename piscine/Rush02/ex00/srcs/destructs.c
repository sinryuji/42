/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:42:11 by jkong             #+#    #+#             */
/*   Updated: 2022/01/23 21:58:15 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdlib.h>

void	set_chain_null(t_str_chain **p1, t_str_chain **p2)
{
	if (p1)
		*p1 = NULL;
	if (p2)
		*p2 = NULL;
}

void	resolve_destruct(t_resolve *this)
{
	t_str_chain	*elem;
	t_str_chain	*next;

	if (this == NULL)
		return ;
	this->reference_path = NULL;
	this->convert_input = NULL;
	free(this->tab);
	this->tab = NULL;
	this->tab_size = 0;
	elem = this->head;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
	set_chain_null(&this->head, &this->tail);
	free(this);
}

void	dictionary_destruct(t_dictionary *this)
{
	t_dict_elem	*elem;
	t_dict_elem	*next;

	if (this == NULL)
		return ;
	elem = this->head;
	while (elem)
	{
		next = elem->next;
		free(elem->value);
		free(elem);
		elem = next;
	}
	this->head = NULL;
	this->tail = NULL;
	free(this);
}

void	dict_init_destruct(t_dict_init *this)
{
	t_str_chain	*elem;
	t_str_chain	*next;

	if (this == NULL)
		return ;
	elem = this->temp_head;
	while (elem)
	{
		free(elem->str);
		next = elem->next;
		free(elem);
		elem = next;
	}
	set_chain_null(&this->temp_head, &this->temp_tail);
	elem = this->final_head;
	while (elem)
	{
		free(elem->str);
		next = elem->next;
		free(elem);
		elem = next;
	}
	set_chain_null(&this->final_head, &this->final_tail);
	free(this);
}
