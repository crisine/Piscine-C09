# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misung <misung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 21:22:34 by misung            #+#    #+#              #
#    Updated: 2021/09/27 22:17:59 by misung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rm -f libft.a
find . -name "*.c" -type f -maxdepth 1 -exec gcc -Wall -Wextra -Werror -c {} \;
ar -rcus libft.a *.o
find . -name "*.o" -type f -maxdepth 1 -delete
