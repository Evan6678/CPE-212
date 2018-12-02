
//public fucntion implementation
template <typename ItemType>
Heap<ItemType>::Heap()
{
  ptr = new ItemType[MAXSIZE];
  maxsize = MAXSIZE;
  num = 0;
}

template <typename ItemType>
Heap<ItemType>::~Heap()
{
	num = 0;
  delete [] ptr;
}

template <typename ItemType>
void Heap<ItemType>::Insert(ItemType n)
{
	if (!IsFull())
		{
			ptr[num] = n;
			num++;
		}
	else
		{

			//create temp ptr
			ItemType* tempPtr;
			//double maxsize
			maxsize = maxsize * 2;
			//create new double sized array
			try
			{
				tempPtr = new ItemType[maxsize];
			}
			catch(...)
			{
				throw FullHeap();
			}
			//transfer over old data to new array
			for (int x = 0; x < num; x++)
			{
				tempPtr[x] = ptr[x];
			}
			//delete old array
			delete [] ptr;
			//set ptr to tempptr
			ptr = tempPtr;
			//insert new element
			ptr[num] = n;
			//increment num
			num++;
		}
    ReheapUp(0, num-1);
}

template <typename ItemType>
ItemType Heap<ItemType>::DeleteMax()
{

	if(Size() == 0)
	{
		throw EmptyHeap();
	}
	else
	{
		ItemType returnVal = ptr[0];
		ptr[0] = ptr[num-1];
		num--;
		//catch negative num
		if (num < 0)
		{
			num = 0;
		}
		ReheapDown(0, num-1);
		return returnVal;
	}
}

template <typename ItemType>
void Heap<ItemType>::MakeEmpty()
{
	num = 0;
}

template <typename ItemType>
int Heap<ItemType>::Size() const
{
  return num;
}

template <typename ItemType>
int Heap<ItemType>::Capacity() const
{
  return maxsize;
}

//Private functions
template <typename ItemType>
void Heap<ItemType>::Swap(ItemType& a, ItemType& b)
{
	ItemType temp = a;
	a = b;
	b = temp;
}

template <typename ItemType>
void Heap<ItemType>::ReheapDown(int root, int bottom)
{

	//create vars for data
	int maxChild, rightChild, leftChild;

	//get left and right child
	leftChild = root*2+1;
	rightChild = root*2+2;

	//ensure it is not end of tree
	if (leftChild <= bottom)
	{
		//if left child is the only child
		if (leftChild == bottom)
		{
			maxChild = leftChild;
		}
		//if there are a left and right child
		else
		{
			//if right child is greater then left child set right to max
			if (ptr[leftChild] <= ptr[rightChild])
			{
				maxChild = rightChild;
			}
			//else set left to max
			else
			{
				maxChild = leftChild;
			}
		}
		//if parent is less than child swap and use recursion to rerun Heap Down
		if(ptr[root] < ptr[maxChild])
		{
			Swap(ptr[root], ptr[maxChild]);
			ReheapDown(maxChild, bottom);
		}
	}
}

template <typename ItemType>
void Heap<ItemType>::ReheapUp(int root, int bottom)
{
  int parent;

	if (bottom > root)
	{
		parent = (bottom-1) / 2;
		if (ptr[parent] < ptr[bottom])
		{
			Swap(ptr[parent], ptr[bottom]);
			ReheapUp(root, parent);
		}
	}
}

template <typename ItemType>
bool Heap<ItemType>::IsFull() const
{
  if (Size() == maxsize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ItemType>
bool Heap<ItemType>::IsEmpty() const
{
  if (num == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
