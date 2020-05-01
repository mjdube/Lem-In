#include "../libft/libft.h"

int         ft_checking_ants(char *s)
{
    int     i;
    
    i = 0;
    if (s == NULL)
        return (0);
    if (ft_strlen(s) > 1)
    {
        while (s[i])
        {
            if (ft_isdigit(s[i]))
                i++;
            else 
                return (0);
        }
    }
    else if (ft_strlen(s) == 1) 
    {
        if (ft_isdigit(s[i]))
            return (1);
        else 
            return (0);
    }
    return (1);
}