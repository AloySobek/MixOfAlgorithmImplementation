/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:05:01 by vrichese          #+#    #+#             */
/*   Updated: 2019/11/25 17:07:46 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	mergeSort(std::string *names)
{
	;
}

void	insertionSort(std::string *names, int amount)
{
	;
}

void	bubbleSort(std::string *names, int amount)
{
	for (int i = 0; i < amount; ++i)
	{
		for (int j = 0; j < amount - 1; ++j)
		{
			if (names[j][0] > names[j+1][0])
			{
				std::string tmp = names[j];
				names[j] = names[j+1];
				names[j+1] = tmp;
			}
		}
	}
}

void	selectionSort(std::string *names, int amount)
{
	std::string	tmp;
	int			lowest;
	int			i, j;

	for (i = 0; i < amount; ++i)
	{
		lowest = i;
		for (j = i; j < amount; ++j)
			if (names[j][0] < names[lowest][0])
				lowest = j;
		tmp = names[i];
		names[i] = names[lowest];
		names[lowest] = tmp;
	}
}

void	quickSort(std::string *names, int low, int high)
{
	char	pivot;
	int		center;
	int		middle;
	int		i;
	int		j;

	if (low < high)
	{
		i = low;
		j = high;
		center = (low + high) / 2;
		pivot = names[center][0];
		while (true)
		{
			while ((i <= high && names[i][0] < pivot) || (names[i][0] == pivot && i != center))
				++i;
			while ((j >= 0 && names[j][0] > pivot) || (names[j][0] == pivot && j != center))
				--j;
			if (i >= j)
			{
				middle = j;
				break;
			}
			std::string tmp = names[i];
			names[i] = names[j];
			names[j] = tmp;
		}
		quickSort(names, low, middle);
		quickSort(names, middle + 1, high);
	}
}

int main(int argc, char **argv)
{
	int names_amount = 0;

	if (argc > 1)
		return (-1);

	std::cout << "Welcome to sort of your names!\n";
	std::cout << "Please, take here number of your names >>> : ";
	while (true)
	{
		std::cin >> names_amount;
		if (std::cin.fail())
		{
			std::cout << "Wrong input, try again\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');
			break;
		}
	}
	std::string *names = new std::string[names_amount];
	std::cout << "Good, now you must to take every name of your names\n";
	for (int i = 0; i < names_amount;)
	{
		std::cin >> names[i];
		if (std::cin.fail())
		{
			std::cout << "Wrong input, try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}
		std::cin.ignore(32767, '\n');
		std::cout << "Your gave the next name: " << names[i] << std::endl;
		++i;
	}
	std::cout << "Good! Now we are sorting your names\n";
	quickSort(names, 0, names_amount - 1);
	//selectionSort(names, names_amount);
	//bubbleSort(names, names_amount);
	std::cout << "Good! Now your names is sort, here result:\n";
	for (int i = 0; i < names_amount; ++i)
		std::cout << names[i] << std::endl;
	return (0);
}