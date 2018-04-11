/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_Lomuto.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 12:39:58 by aroi              #+#    #+#             */
/*   Updated: 2018/04/10 18:30:43 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

void	swap(int *arr, int n1, int n2)
{
	int tmp;

	printf("n1: %i n2: %i\n", arr[n1], arr[n2]);
	tmp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2] = tmp;
	printf("n1: %i n2: %i\n", arr[n1], arr[n2]);
}

void	display(int *arr)
{
	int i;

	i = 0;
	printf("[");
	while (i < 7)
	{
		if (i != 6)
			printf("%i ", arr[i++]);
		else
			printf("%i", arr[i++]);
	}
	printf("]\n");
}

int		partition(int *arr, int left, int right)
{
	int pivot;
	int left_index;
	int right_index;

	pivot = arr[right];
	left_index = left;
	right_index = left - 1;
	while (++right_index < right)
	{
		if (arr[right_index] <= pivot)
			swap(arr, left_index++, right_index);
	}
	swap(arr, left_index, right);
	display(arr);
	return (left_index);
}

void	quicksort(int *arr, int left, int right)
{
	int index;

	if (left >= right)
		return ;
	index = partition(arr, left, right);
	quicksort(arr, left, index - 1);
	quicksort(arr, index + 1, right);
}

int		main(void)
{
	int	*arr;
	int len;
	int i;

	len = 7;
	arr = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		arr[i] = len - i;
		i++;
	}
	display(arr);
	quicksort(arr, 0, len - 1);
	display(arr);
	return (0);
}
