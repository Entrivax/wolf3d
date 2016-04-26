/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_reader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 12:26:25 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/15 12:36:42 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_READER_H
# define BINARY_READER_H

int			read_int(int fd, int *out);
int			read_short(int fd, short *out);
int			read_byte(int fd, unsigned char *out);

#endif
