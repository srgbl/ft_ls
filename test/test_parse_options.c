/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:53:53 by gloras-t          #+#    #+#             */
/*   Updated: 2020/12/20 21:37:47 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <assert.h>

int main() 
{
	uint8_t	options;
	
	options = 0;
	assert(parse_options("a", &options) == 0);
	assert(options == OPT_LOWER_A);

	options = 0;
	assert(parse_options("la", &options) == 0);
	assert(options == (OPT_LOWER_A + OPT_LOWER_L));
	
	options = 0;
	assert(parse_options("rla", &options) == 0);
	assert(options == (OPT_LOWER_A + OPT_LOWER_L + OPT_LOWER_R));

	options = 0;
	assert(parse_options("trla", &options) == 0);
	assert(options == (OPT_LOWER_A + OPT_LOWER_L + OPT_LOWER_R + OPT_LOWER_T));

	options = 0;
	assert(parse_options("Rtrla", &options) == 0);
	assert(options == (OPT_LOWER_A + OPT_LOWER_L + OPT_LOWER_R + OPT_LOWER_T + OPT_UPPER_R));

	options = 0;
	assert(parse_options("lal", &options) == 0);
	assert(options == (OPT_LOWER_A + OPT_LOWER_L));

	options = 0;
	assert(parse_options("alala", &options) == 0);
	assert(options == (OPT_LOWER_A + OPT_LOWER_L));

	options = 0;
	assert(parse_options("alarla", &options) == 0);
	assert(options == (OPT_LOWER_A + OPT_LOWER_L + OPT_LOWER_R));

	options = 0;
	assert(parse_options("albala", &options) == -1);
	assert(options == (OPT_LOWER_A + OPT_LOWER_L));

	options = 0;
	assert(parse_options("abl", &options) == -1);
	assert(options == (OPT_LOWER_A));
	
	ft_printf("All tests completed\n");
	return (0);
}
