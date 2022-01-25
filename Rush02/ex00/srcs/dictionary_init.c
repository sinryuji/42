/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:30:48 by jkong             #+#    #+#             */
/*   Updated: 2022/01/23 20:37:31 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	dict_init_load(t_dict_init *this, char *pathname)
{
	int		fd;
	char	buf[BUFFER_MAX];
	int		count;
	int		result;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (0);
	count = -2;
	result = 1;
	while (count != 0)
	{
		if (count == -1)
		{
			result = 0;
			break ;
		}
		if (count > 0)
			dict_init_insert_temp(this, buf, count);
		count = read(fd, buf, sizeof(buf));
	}
	if (result)
		dict_init_finalize_temp(this);
	close(fd);
	return (result);
}

void	dict_init_insert_temp(t_dict_init *this, char *buf, int count)
{
	t_str_chain	*chain;
	char		*str;

	chain = malloc(sizeof(t_str_chain));
	if (chain == NULL)
		return ;
	if (this->temp_tail)
		this->temp_tail->next = chain;
	else
		this->temp_head = chain;
	this->temp_tail = chain;
	str = malloc(count);
	if (str == NULL)
		return ;
	ft_memcpy(str, buf, count);
	chain->str = str;
	chain->offset = 0;
	chain->length = count;
	chain->next = NULL;
}

void	dict_init_finalize_temp(t_dict_init *this)
{
	t_str_chain		*chain;
	unsigned int	i;
	unsigned int	len;

	chain = this->temp_head;
	len = 0;
	while (chain)
	{
		i = 0;
		while (i < chain->length)
		{
			if (chain->str[i] == '\n')
			{
				dict_init_insert_final(this, len);
				len = 0;
			}
			else
				len++;
			i++;
		}
		chain = chain->next;
	}
	if (len > 0)
		dict_init_insert_final(this, len);
	dict_init_set_final(this);
}

void	dict_init_insert_final(t_dict_init *this, unsigned int length)
{
	t_str_chain	*chain;
	char		*str;

	chain = malloc(sizeof(t_str_chain));
	if (chain == NULL)
		return ;
	if (this->final_tail)
		this->final_tail->next = chain;
	else
		this->final_head = chain;
	this->final_tail = chain;
	str = malloc(sizeof(*chain->str) * (length + 1));
	if (str == NULL)
		return ;
	str[length] = '\0';
	chain->str = str;
	chain->offset = 0;
	chain->length = length + 1;
	chain->next = NULL;
}

void	dict_init_set_final(t_dict_init *this)
{
	t_str_chain		*chain_src;
	t_str_chain		*chain_dest;
	unsigned int	i;

	chain_src = this->temp_head;
	chain_dest = this->final_head;
	while (chain_src)
	{
		i = 0;
		while (i < chain_src->length)
		{
			if (chain_src->str[i] == '\n')
			{
				chain_dest = chain_dest->next;
			}
			else
			{
				chain_dest->str[chain_dest->offset] = chain_src->str[i];
				chain_dest->offset++;
			}
			i++;
		}
		chain_src = chain_src->next;
	}
}
