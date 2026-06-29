/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:52:22 by jkong             #+#    #+#             */
/*   Updated: 2022/01/23 21:19:23 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# define CIPHER_UNIT 3
# define TRADITION_MAX 20
# define DEFAULT_PATH "./resources/numbers.dict"
# define BUFFER_MAX 512

typedef struct s_str_chain	t_str_chain;

struct s_str_chain
{
	char			*str;
	unsigned int	offset;
	unsigned int	length;
	t_str_chain		*next;
};

typedef struct s_resolve
{
	char		*reference_path;
	char		*convert_input;
	int			*tab;
	int			tab_size;
	t_str_chain	*head;
	t_str_chain	*tail;
}	t_resolve;

typedef struct s_dict_elem	t_dict_elem;

typedef struct s_dictionary
{
	t_dict_elem	*head;
	t_dict_elem	*tail;
}	t_dictionary;

struct s_dict_elem
{
	int			key;
	char		*value;
	t_dict_elem	*next;
};

typedef struct s_dict_init
{
	t_str_chain	*temp_head;
	t_str_chain	*temp_tail;
	t_str_chain	*final_head;
	t_str_chain	*final_tail;
}	t_dict_init;

typedef struct s_int_range
{
	int	begin;
	int	end;
}	t_int_range;

/*
** Forty-Two standard util (ft_standard.c)
*/
int				ft_isspace(char c);
int				ft_isdigit(char c);
int				ft_atoi(char *str);
void			*ft_memcpy(void *dest, void *src, int n);
void			ft_write_string(char *str);

/*
** Forty-Two string util (ft_string.c)
*/
int				ft_strlen(char *str);
char			*ft_strcpy(char *dest, char *src);

/*
** Dictionary util (dict_util.c)
*/
int				table_element(int *i, char *str, int len);
char			*substring(char *str, int begin, int end);
int				parse_pair(char *str, char **key, char **value);
int				calc_key(char *key);
int				append(t_resolve *res, t_dictionary *dict, int key);

/*
** Class constructors (constructs.c)
*/
t_resolve		*resolve_construct(void);
t_dictionary	*dictionary_construct(void);
t_dict_init		*dict_init_construct(void);

/*
** Class destructors (destructs.c)
*/
void			resolve_destruct(t_resolve *this);
void			dictionary_destruct(t_dictionary *this);
void			dict_init_destruct(t_dict_init *this);

/*
** Resolver class (resolve.c)
*/
int				resolve_init(t_resolve *this, int argc, char **argv);
int				resolve_make_table(t_resolve *this, char *str);
int				resolve_try_doing(t_resolve *this, t_dictionary	*dict);
int				resolve_try_sub(t_resolve *this, t_dictionary	*dict, int n);

/*
** Dictionary class (dictionary.c)
*/
t_dict_elem		*dictionary_get_elem(t_dictionary *this, int key);
t_dict_elem		*dictionary_put_elem(t_dictionary *this, int key, char *value);
char			*dictionary_get_value(t_dictionary *this, int key);
char			*dictionary_put_value(t_dictionary *this, int key, char *value);
int				dictionary_apply_init(t_dictionary *this, t_dict_init *init);

/*
** Dictionary initializer class (dictionary_init.c)
*/
int				dict_init_load(t_dict_init *this, char *pathname);
void			dict_init_insert_temp(t_dict_init *this, char *buf, int count);
void			dict_init_finalize_temp(t_dict_init *this);
void			dict_init_insert_final(t_dict_init *this, unsigned int length);
void			dict_init_set_final(t_dict_init *this);

#endif
