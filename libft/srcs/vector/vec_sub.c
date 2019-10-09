/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:14:10 by anjansse          #+#    #+#             */
/*   Updated: 2019/10/05 11:43:34 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec			vec_sub(t_vec v1, t_vec v2)
{
	t_vec	vector;

	vector.x = v1.x - v2.x;
	vector.y = v1.y - v2.y;
	vector.z = v1.z - v2.z;
	return (vector);
}