#include "vm.h"

int errno(int x)
{
  if (x == 0)
    ft_printf("error: no argument\n");
  if (x == 1)
    ft_printf("error: wrong number after flag "-n"\n");
  if (x == 2)
      ft_printf("error: wrong argument\n");
  if (x == 5)
    ft_printf("error: too many argument\n");
  return (0);
}

int			ft_rstrcmp(const char *str1, const char *str2)
{
	size_t	index;
  size_t  len1;
  size_t  len2;

	index = 0;
  len1 = ft_strlen(str1);
  len2 = ft_strlen(str2);
	if (!str1 || !str2)
		return (0);
	while ((str1[len1 - index] || str2[len2 - index]))
	{
		if (str1[len1 - index] != str2[len2 - index])
		{
			return ((int)((unsigned char)str1[len1 - index] - \
			(unsigned char)str2[len2 - index]));
		}
		index++;
	}
	return (0);
}

t_champ *list_add(char *cor)
{

}

int main(int c, char **a)
{
  int i;
  int n;
  t_champ *c;
  if (c < 2)
    return (errno(0));
  if (c > MAX_PLAYERS)
    return (errno(5));
  i = 1;
  while (i < c)
  {
    if (ft_rstrcmp(a[i],".cor"))
      c = list_add(a[i]);
    else
      return(errno(2));
    if (ft_strcmp(a[i], "-n"))
    {
      n = ft_atoi(a[i + 1]
      if (n == 0 || n > MAX_PLAYERS)
        return (errno(1));
      else
    }
    i++
  }

}
