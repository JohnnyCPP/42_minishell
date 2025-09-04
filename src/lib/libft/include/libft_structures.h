/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_STRUCTURES_H
# define LIBFT_STRUCTURES_H

/**
 * @brief Structure representing a node in a linked list.
 *
 * The node contains a pointer to data of any type, 
 * and a pointer to the next node in the list.
 */
typedef struct s_list
{
	void			*data;
	struct s_list	*next_node;
}	t_list;

#endif