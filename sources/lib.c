/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** get_nbr
*/

int my_getnbr(char const *str)
{
	int sign;
	int res;
	sign = 1;
	res = 0;

	while (*str == '-' || *str == '+') {
		if (*str == '-') {
			sign = sign * -1;
			str = str + 1;
		}
		while (*str >= '0' && *str <= '9') {
			res = (res * 10) + (*str - '0');
			str = str + 1;
		}
		res = res * sign;
		return (res);
	}
        return 0;
}

int 	my_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void 	reverse_str(char *str)
{
     	int i = 0;
     	int j = 0;
     	char c;
 
     	for (i = 0, j = my_strlen(str)-1; i<j; i++, j--) {
        	c = str[i];
         	str[i] = str[j];
         	str[j] = c;
	}
}

void 	my_getcharstar(int nb, char *str)
{
	int i = 0;
	int sign = nb;
	if (sign < 0)
		nb = -nb;
	do {
		str[i++] = nb % 10 + '0';
	} while ((nb /= 10) > 0);
	
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
	reverse_str(str);
}