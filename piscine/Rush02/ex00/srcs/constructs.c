/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:42:08 by jkong             #+#    #+#             */
/*   Updated: 2022/01/23 04:45:37 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdlib.h>

t_resolve	*resolve_construct(void)
{
	t_resolve	*this;

	this = malloc(sizeof(t_resolve));
	if (this)
	{
		this->reference_path = NULL;
		this->convert_input = NULL;
		this->tab = NULL;
		this->tab_size = 0;
		this->head = NULL;
		this->tail = NULL;
	}
	return (this);
}

t_dictionary	*dictionary_construct(void)
{
	t_dictionary	*this;

	this = malloc(sizeof(t_dictionary));
	if (this)
	{
		this->head = NULL;
		this->tail = NULL;
	}
	return (this);
}

t_dict_init	*dict_init_construct(void)
{
	t_dict_init	*this;

	this = malloc(sizeof(t_dict_init));
	if (this)
	{
		this->temp_head = NULL;
		this->temp_tail = NULL;
		this->final_head = NULL;
		this->final_tail = NULL;
	}
	return (this);
}
