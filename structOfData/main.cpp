/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 23:47:59 by Rustam            #+#    #+#             */
/*   Updated: 2020/01/05 23:47:59 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClassBinaryTree.hpp"
# include <time.h>

int main(int argc, char **argv)
{
	BinaryTree	tree(100);

	srand(time(nullptr));

	for (int i = 0; i < 20; ++i)
		tree.push(rand() % 200, &tree.pHead);

	tree.print(0, &tree.pHead);
	return (0);
}