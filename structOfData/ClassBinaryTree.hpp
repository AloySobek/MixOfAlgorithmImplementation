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
# include <iostream>
# include <thread>

template <class T1, typename T2>
class BinaryTree
{
	public:
		BinaryTree() : BinaryTree(0) { }
		BinaryTree(T1 data) : head{ data, nullptr, nullptr, nullptr }, size(0) { }

		uint32_t	getSize() { return size; }

		void push(T1 data, BinaryTree *pStart = nullptr)
		{
			if (pStart)
				__push(data, &pStart->__getHead());
			else
				__push(data, &head);
		}

		void map(void (*pfnFunction)(T1 *, T2), T2 metadata = 0, BinaryTree *pStart = nullptr)
		{
			if (pStart)
				__map(pfnFunction, metadata, &pStart->__getHead());
			else
				__map(pfnFunction, metadata, &head);
		}

		friend std::ostream &operator<< (std::ostream &out, BinaryTree<T1, T2> &tree);

	protected:
		struct				body_s
		{
			T1				data;
			struct body_s	*pRight;
			struct body_s	*pLeft;
			struct body_s	*pUp;
		};

		struct body_s		head;

		uint32_t			size;

		struct body_s		&__getHead(){ return (head); }

		void __push(T1 data, struct body_s *pStart)
		{
			if (pStart)
			{
				if (data > pStart->data)
				{
					if (pStart->pRight)
						__push(data, pStart->pRight);
					else
					{
						pStart->pRight = new struct body_s;
						pStart->pRight->data	= data;
						pStart->pRight->pUp		= pStart;
						pStart->pRight->pLeft	= nullptr;
						pStart->pRight->pRight	= nullptr;
						++size;
					}
				}
				else
				{
					if (pStart->pLeft)
						__push(data, pStart->pLeft);
					else
					{
						pStart->pLeft = new struct body_s;
						pStart->pLeft->data		= data;
						pStart->pLeft->pUp		= pStart;
						pStart->pLeft->pLeft	= nullptr;
						pStart->pLeft->pRight	= nullptr;
						++size;
					}
				}
			}
		}

		void __leftRotate(struct body_s *pPointAround)
		{
			assert(pPointAround && "Internal error, algorithm isn't working correct");
			T1 tmp = pPointAround->pRight;
			pPointAround->pRight = tmp->pLeft;
			tmp->pUp = pPointAround->pUp;
			if (tmp->pUp == &head)

			tmp->pLeft				= pPointAround;
			pPointAround->pUp		= tmp;
		}

		void __rightRotate(struct body_s *pPointAround);

		void __map(void (*pfnFunction)(T1 *, T2), T2 metadata, struct body_s *pStart)
		{
			if (pStart)
			{
				__map(pfnFunction, metadata, pStart->pRight);
				pfnFunction(&pStart->data, metadata);
				__map(pfnFunction, metadata, pStart->pLeft);
			}
		}

		void __print(uint32_t level, struct body_s *pStart)
		{
			if (pStart)
			{
				__print(level + 1, pStart->pRight);
				for (int i = 0; i < level; ++i)
					std::cout << "      ";
				std::cout << pStart->data << std::endl;
				__print(level + 1, pStart->pLeft);
			}
		}
};

//template<typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, BinaryTree<int32_t, float> &tree)
{
	tree.__print(0, &tree.head);
	return (out);
}

#endif