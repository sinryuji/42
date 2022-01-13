#include <unistd.h>  

void ft_putchar(char c) 
{  
	write(1, &c, 1); 
}  

void ft_frontcomma(int tab[], int n, int m) 
{  
	int i;   
	
	if (m == 1)  
	{   
		ft_putchar(',');   
		ft_putchar(' ');  
	}  
	i = 0;  
	while (i < n)  
	{   
		ft_putchar(tab[i] + '0');   
		i++;  
	} 
}  

void ft_digits(int tab[], int n) 
{  
	int i;  
	int max;   
	i = n - 1;  
	max = 9;  
	while (tab[i] == max)  
	{   
		i -= 1;   
		max -= 1;  
	}  
	tab[i] += 1;  
	while (i < n)  
	{   
		tab[i + 1] = tab[i] + 1;   
		i += 1;  
	} 
}  

void ft_print_combn(int n) 
{  
	int tab[10];  
	int i;   
	
	i = 0;  
	while (i < n) 
       	{   
		tab[i] = i;   
		i++;  
	}  
	ft_frontcomma(tab, n, 0);  
	while (tab[0] != 10 - n || tab[n - 1] != 9)  
	{   
		if (tab[n - 1] != 9)   
		{    
			tab[n - 1] += 1;   
		}   
		else   
		{    
			ft_digits(tab, n);   
		}   
		ft_frontcomma(tab, n, 1);  
	} 
}
