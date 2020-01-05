/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBinaryTree.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:41:06 by Rustam            #+#    #+#             */
/*   Updated: 2020/01/05 22:41:06 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_BINARY_TREE_HPP
# define CLASS_BINARY_TREE_HPP

# include <cstdint>
# include <string>
# include <iostream>

typedef struct	body_s
{
	int				data;
	struct body_s	*pRight;
	struct body_s	*pLeft;
}				body_t;

class BinaryTree
{
	public:
		body_t pHead;

		BinaryTree(int data) : pHead{data, nullptr, nullptr} { }

		void push(int data, struct body_s *pStart)
		{
			if (data > pStart->data)
			{
				if (pStart->pRight)
					push(data, pStart->pRight);
				else
				{
					pStart->pRight = new struct body_s;
					pStart->pRight->pRight = nullptr;
					pStart->pRight->pLeft = nullptr;
					pStart->pRight->data = data;
				}
			}
			else
			{
				if (pStart->pLeft)
					push(data, pStart->pLeft);
				else
				{
					pStart->pLeft = new struct body_s;
					pStart->pLeft->pRight = nullptr;
					pStart->pLeft->pLeft = nullptr;
					pStart->pLeft->data = data;
				}
			}
		}

		void print(uint32_t level, struct body_s *pStart)
		{
			if (pStart)
			{
				print(level + 1, pStart->pRight);
				for (int i = 0; i < level; ++i)
					std::cout << "   ";
				std::cout << pStart->data << "\n";
				print(level + 1, pStart->pLeft);
			}
		}
};

#endif