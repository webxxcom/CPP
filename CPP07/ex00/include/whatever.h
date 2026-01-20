/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkravche <rkravche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:13:14 by rkravche          #+#    #+#             */
/*   Updated: 2026/01/20 16:17:19 by rkravche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template<typename T>
void swap(T &left, T &right)
{
    T tmp = left;
    left = right;
    right = tmp;
}

template<typename T>
T min(T left, T right)
{
    return left < right ? left : right;
}

template<typename T>
T max(T left, T right)
{
    return left > right ? left : right;
}
#endif