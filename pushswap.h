/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:58:26 by solee2            #+#    #+#             */
/*   Updated: 2023/05/16 16:39:24 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>

# define SA		"sa"
# define SB		"sb"
# define SS		"ss"
# define PA		"pa"
# define PB		"pb"
# define RA		"ra"
# define RB		"rb"
# define RR		"rr"
# define RRA	"rra"
# define RRB	"rrb"
# define RRR	"rrr"

typedef struct s_list
{
	long long		number;
	int				index;
	struct s_list	*next;
}				t_list;

//pushswap
void		index_stack(t_list **stack);
//static void	set_stack(t_list **stack, int argc, char **argv);
int			sort_check_stack(t_list **stack);
void		sort_stack(t_list **one, t_list **two);

//few_sort
void		sort_three(t_list **input);
int			minimum_location(t_list **input);
void		sort_four(t_list **one, t_list **two);
void		sort_five(t_list **one, t_list **two);
void		few_sort(t_list **one, t_list **two);

//many_sort
int			get_bit_size(t_list **input);
void		many_sort(t_list **one, t_list **two);
void		sort_process(t_list **one, t_list **two, int j);

//operations_push
int			push_operation(t_list **origin, t_list **destination);
int			push_pa_pb(t_list **one, t_list **two, char *operation);

//operations_reverse_rotate
int			reverse_rotate_operation(t_list **input);
int			reverse_rotate_rra_rrb(t_list **input, char *operation);
int			reverse_rotate_rrr(t_list **one, t_list **two);

//operations_rotate
int			rotate_operation(t_list **input);
int			rotate_ra_rb(t_list **input, char *operation);
int			rotate_rr(t_list **one, t_list **two);

//operations_swap
void		swap_operation(t_list **input);
void		swap_sa_sb(t_list **input, char *operation);
void		swap_ss(t_list **one, t_list **two);

//argument
int			ignore_space(char *str);
long long	atoi_long_long(char *str);
int			multiple_exist(long long input, char **numbers, int index);
void		arg_check(int argc, char **argv);

//basic_utils
char		**ft_split(const char *str, char set);
int			ft_atoi(const char *str);
void		ft_putendl_fd(char *s, int fd);
int			ft_streq(char *one, char *two);

//index_utils
//static int	get_start_index(char *str, char set, int number);
//static int	get_end_index(char *str, char set, int start);

//lst_utils
t_list		*ft_lstnew(long long input);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);

//related_utils
void		fd_message(char *str);
void		ft_free(char **str);
t_list		*next_minimum(t_list **stack);
void		free_stack(t_list **stack);

//word_number_utils
//static int	count_words(char *str, char value);
int			get_length(char *str);
//static char	*get_word(char *str, char set, int number);
char		*add_word(char *src);
int			not_in_range(long long input);
int			is_number(char *number);

#endif