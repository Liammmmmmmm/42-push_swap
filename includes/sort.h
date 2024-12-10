/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:42:08 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/10 16:50:00 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

int		min(int *stack, int len);
int		max(int *stack, int len);

void	sort(int *stack_a, int *stack_b, int *stack_sorted);
void	mysort(int *stack_a, int *stack_b, int *stack_sorted);
void	mysort_little(int *stack_a, int *stack_b, int *stack_sorted);
void	radix_sort_base(int *stack_a, int *stack_b, int *stack_sorted, int b);
void	bbeg_sort(int *stack_a, int *stack_b, int *stack_sorted);
void	bubble_sort(int	*stack_a);

int		first_sort(int **stack_sorted, int *stack_a, int *stack_b, int len);
int		find_quickest_b(int *stack_b, int actual_index, int number);
int		find_quickest_inferior_a(int *stack_a, int number);
int		find_quickest_supperior_b(int *stack_b, int number);

int		rotate_to_shortest_inferior_a(int *stack_a, int limit);
int		rotate_to_shortest_supperior_b(int *stack_b, int limit);

void	sort_two_a(int *stack_a);
void	sort_three_a(int *stack_a);
void	sort_four_a(int *stack_a);

void	sort_two_b(int *stack_b);
void	sort_three_b(int *stack_b);
void	sort_four_b(int *stack_b);

int		is_sorted(int *stack_a);

/* ******************************** MYSORT ********************************* */

void	i_to_b_first(int *stack_a, int *stack_b, int *stack_sorted, int parts);
void	i_to_b(int *stack_a, int *stack_b, int *stack_sorted, int parts);
void	i_to_a(int *stack_a, int *stack_b, int *stack_sorted, int parts);
void	move_to_b(int *stack_a, int *stack_b, int limit);
void	move_to_b_bounded(int *stack_a, int *stack_b, int min, int max);
void	full_insert_sort(int *stack_a, int *stack_b);
void	rotate_and_push(int *i, int *stack_a, int *stack_b, void (*rota)(int));

/* ********************************* BBEG ********************************** */

/**
 * This struct contains "stacks" of numbers with the followings informations
 * 
 * @param stack a or b, just the name of the stack of this stack
 * @param min the lowest number of the stack
 * @param size the size of this stack
 */
typedef struct s_bbeg
{
	int		size;
	int		min;
	char	stack;
}			t_bbeg;

/**
 * Execute 2 bubble sort on the stack a and b, for up to `limit` numbers.
 * Usualy, limit should not be above 5, you better have to split it and
 * execute to double bubble on stacks of 3.
 * 
 * It can be optimized by stopping the bubble if everything is sorted.
 * 
 * It take adventage of the double rotation and the double swap.
 */
void	parallel_bubble_limit(int *stack_a, int *stack_b, int limit);

/**
 * Execute 2 bubble sort on the stack a and b, for up to `limit` numbers
 * for a stack and `limit + 1` for stack b.
 * Usualy, limit should not be above 4 (so a total of 9 numbers)
 * 
 * It can be optimized by stopping the bubble if everything is sorted.
 * 
 * It take adventage of the double rotation and the double swap.
 */
void	parallel_bubble_limit_odd(int *stack_a, int *stack_b, int limit);

/**
 * In the case of a malloc error, free everything and restart the sort with my
 * algo that don't use any malloc. If this function is called, the amount of
 * actions required would be terrifying.
 */
void	cancel_everything(t_list **first, int *st_a, int *st_b, int *st_s);

/**
 * Create a new element of the chained list, creating at the same time a struct
 * containing the informations `stack`, `size` and `min`.
 */
int		add_node(t_list **first, char stack, int size, int min);

/**
 * Search in the list an element with the parameter `stack` = 'a'
 * 
 * @return The element found or NULL if nothing have been found.
 */
t_list	*search_for_a(t_list **first);

/**
 * Verify if there is only one stack in b
 */
int		is_alone_in_b(t_list **first);

/**
 * Call this function only if you have 5 or less number to sort in stack b.
 * It will automatically chose an algorithm to sort 2, 3, 4 or 5 numbers.
 * 
 * It work even if there is other numbers in the stack, but it only sort the
 * specified amount of numbers.
 * 
 * @param to_sort The amount of number to sort in b
 */
void	select_good_sort_b(int *stack_a, int *stack_b, int to_sort);

/**
 * Call this function only if you have 5 or less number to sort in stack a.
 * It will automatically chose an algorithm to sort 2, 3, 4 or 5 numbers.
 * 
 * It work even if there is other numbers in the stack, but it only sort the
 * specified amount of numbers.
 * 
 * @param to_sort The amount of number to sort in a
 */
void	select_good_sort_a(int *stack_a, int to_sort);

/**
 * This function will select the best between sorting imediatly the numbers,
 * or splitting it in stack a to apply a double bubble sort before putting
 * everything in stack a.
 * 
 * Call it only if you have 10 or less numbers to sort
 */
void	sort_from_b(t_list **first, t_list *elem, int *stack_a, int *stack_b);

/**
 * This function will select the best between sorting imediatly the numbers,
 * or splitting it in stack b to apply a double bubble sort before putting
 * everything back in stack a.
 * 
 * Call it only if you have 10 or less numbers to sort
 */
void	sort_from_a(t_list **first, t_list *elem, int *stack_a, int *stack_b);

/**
 * If the stack is 10 numbers or less long, it call sort_from_a, else it split
 * it in two different stacks. Bigger stack go in stack_a, smalest in stack_b.
 * After that, the function call back itself to split or sort the new stack.
 */
void	split_from_a(t_list **first, int *stack_a, int *stack_b, int *stack_s);

/**
 * If the stack is 10 numbers or less long, it call sort_from_b, else it split
 * it in two different stacks. Bigger stack go in stack_a, smalest in stack_b.
 * After that, the function call split_from_a to split or sort the new stack.
 */
void	split_from_b(t_list **first, int *stack_a, int *stack_b, int *stack_s);

/**
 * In order to gain some operations, the split altern ra and rra before pushing
 * numbers in b, but if sort from b is called we have to put the stack a in
 * a normal form, and thats the goal of this function.
 */
void	go_back_if(int *direction, int rotations);

/**
 * Push numbers of stack_a in the stack_b.
 */
void	push_to_b(int direction, t_bbeg *content, int *stack_a, int *stack_b);

/**
 * Push numbers of stack_b in the stack_a.
 */
void	push_to_a(t_bbeg *content, int *stack_a, int *stack_b, int alone);

#endif