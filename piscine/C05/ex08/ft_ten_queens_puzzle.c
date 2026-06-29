/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:49:25 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/18 21:35:14 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_queens(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

int	check_queens(int row, int *board, int val)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (val == board[i] 
				||ft_abs(val - board[i]) == ft_abs(row - i))
			return (0);
		i++;
	}
	return (1);
}

void	queens(int row, int *board, int *cnt)
{
	int	i;

	i = 0;
	if (row == 10)
	{
		print_queens(board);
		*cnt = *cnt + 1;
		return ;
	}
	while (i < 10)
	{
		if (check_queens(row, board, i))
		{
			board[row] = i;
			queens(row + 1, board, cnt);
			board[row] = 0;
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < 10)
	{
		board[i] = 0;
		i++;
	}
	queens(0, board, &cnt);
	return (cnt);
}

int	main(void)
{
	printf("%d\n", ft_ten_queens_puzzle());

}
