/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection_sphere.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:40:05 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/11/23 12:14:08 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

/*
** ----------------------------------------------------------------------------
** The functions below allow to determine the coefs of the quadratic equation
** to solve in order to find the intersection points between the object and
** the ray at hand.
** ----------------------------------------------------------------------------
*/

void			find_quadratic_equa_coefs_sphere(t_ray *ray, t_object *obj, double *coefs)
{
	coefs[0] = vec_dot_product(RAY_D, RAY_D);
	coefs[1] = 2 * vec_dot_product(RAY_D, vec_sub(RAY_O, SPHERE->center));
	coefs[2] = vec_dot_product(vec_sub(RAY_O, SPHERE->center), \
								vec_sub(RAY_O, SPHERE->center))\
				- SPHERE->radius * SPHERE->radius;
}

bool			find_intersection_sphere(t_ray *ray, t_object *obj, double *object_dist)
{
	double		coefs[3];
	double		sols[2];


	*object_dist = INFINITY;
	find_quadratic_equa_coefs_sphere(ray, obj, coefs); // pas changer un truc pourri
	if (TRUE == solve_quadratic_equa(coefs[0], coefs[1], coefs[2], sols))
	{
		if (sols[0] > EPSILON && sols[0] < *object_dist)
			*object_dist = sols[0];
		if (sols[1] > EPSILON && sols[1] < *object_dist)
			*object_dist = sols[1];
	}
	if (*object_dist != INFINITY)
		return (TRUE);
	return (FALSE);
}