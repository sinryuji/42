/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:55:45 by min-cho           #+#    #+#             */
/*   Updated: 2022/01/16 13:09:45 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

int		check_col_up(int tab[4][4], int arr[16], int pos);
int		check_row_right(int tab[4][4], int arr[16], int pos);
int		check_col_down(int tab[4][4], int arr[16], int pos);
int		check_row_left(int tab[4][4], int arr[16], int pos);
int		check_double(int tab[4][4], int num, int pos);
int		check_case(int tab[4][4], int arr[16], int pos);

char	ft_putnbr(int nb);
char	ft_putstr(char *str);
char	ft_putchar(char c);
int		*ft_av_atoi(char *arr);
int		numcheck(char *arr);
int		ft_check(int arr[], char str[]);

#endif
