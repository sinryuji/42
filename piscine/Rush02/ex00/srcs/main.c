/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 03:55:27 by jkong             #+#    #+#             */
/*   Updated: 2022/01/23 21:35:41 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdlib.h>

#define EXIT_ERROR 2
#define EXIT_DICT_ERROR 3

int	end(int exit_code, t_resolve *res, t_dict_init *init, t_dictionary *dict)
{
	t_str_chain	*chain;

	if (exit_code == EXIT_SUCCESS)
	{
		chain = res->head;
		while (chain)
		{
			if (chain != res->head)
				ft_write_string(" ");
			ft_write_string(chain->str);
			chain = chain->next;
		}
		ft_write_string("\n");
	}
	if (exit_code == EXIT_ERROR)
		ft_write_string("Error\n");
	if (exit_code == EXIT_DICT_ERROR)
		ft_write_string("Dict Error\n");
	resolve_destruct(res);
	dict_init_destruct(init);
	dictionary_destruct(dict);
	return (exit_code);
}

int	contains_keys(t_dictionary *dict, int key)
{
	t_dict_elem		*elem;

	elem = dict->head;
	while (elem)
	{
		if (elem->key == key)
			return (1);
		elem = elem->next;
	}
	return (0);
}

int	check_initial_keys(t_dictionary *dict)
{
	t_dict_init		*ref_init;
	t_dictionary	*ref_dict;
	t_dict_elem		*ref_elem;

	ref_init = NULL;
	ref_dict = NULL;
	ref_init = dict_init_construct();
	if (ref_init == NULL)
		return (end(-1, NULL, ref_init, ref_dict));
	if (!dict_init_load(ref_init, DEFAULT_PATH))
		return (end(-1, NULL, ref_init, ref_dict));
	ref_dict = dictionary_construct();
	if (ref_dict == NULL)
		return (end(-1, NULL, ref_init, ref_dict));
	if (!dictionary_apply_init(ref_dict, ref_init))
		return (end(-1, NULL, ref_init, ref_dict));
	ref_elem = ref_dict->head;
	while (ref_elem)
	{
		if (!contains_keys(dict, ref_elem->key))
			return (end(-1, NULL, ref_init, ref_dict));
		ref_elem = ref_elem->next;
	}
	return (end(-2, NULL, ref_init, ref_dict));
}

int	main(int argc, char **argv)
{
	t_resolve		*res;
	t_dict_init		*init;
	t_dictionary	*dict;

	res = NULL;
	init = NULL;
	dict = NULL;
	res = resolve_construct();
	if (res == NULL)
		return (end(EXIT_FAILURE, res, init, dict));
	if (!resolve_init(res, argc, argv))
		return (end(EXIT_ERROR, res, init, dict));
	init = dict_init_construct();
	if (init == NULL)
		return (end(EXIT_FAILURE, res, init, dict));
	if (!dict_init_load(init, res->reference_path))
		return (end(EXIT_DICT_ERROR, res, init, dict));
	dict = dictionary_construct();
	if (dict == NULL)
		return (end(EXIT_FAILURE, res, init, dict));
	if (!dictionary_apply_init(dict, init) || check_initial_keys(dict) == -1)
		return (end(EXIT_DICT_ERROR, res, init, dict));
	if (!resolve_try_doing(res, dict))
		return (end(EXIT_DICT_ERROR, res, init, dict));
	return (end(EXIT_SUCCESS, res, init, dict));
}
