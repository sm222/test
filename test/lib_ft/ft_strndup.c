/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:25:57 by anboisve          #+#    #+#             */
/*   Updated: 2023/09/07 17:37:56 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t len)
{
	size_t	s_len;
	char	*new;
	size_t	i;

	i = 0;
	new = NULL;
	if (len == 0 || !str)
		return (NULL);
	s_len = ft_strlen(str);
	if (s_len < len)
		len = s_len;
	new = ft_calloc(len + 1 , sizeof(char));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}
