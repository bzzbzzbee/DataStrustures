#include "Stack.h"
#include "StackNode.h"
#include "Queue.h"
#include "Set.h"
#include "List.h"
#include "BinaryTree.h"

template <typename T>
bool binary_search(const T* array, int begin, int end, const T &element)
{
	if (end >= begin)
	{
		int mid = begin + (end - begin) / 2;

		if (array[mid] == element)
			return true;

		if (array[mid] > element)
			return binary_search(array, begin, mid - 1, element);

		return binary_search(array, mid + 1, end, element);
	}
	return false;
}

int main()
{

    return 0;
}