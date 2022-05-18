#include "MyClass.h"

//Array Iterator

//Constructor
template<class T>
ArrayIterator<T>::ArrayIterator()
{
	this->Current = 0;
}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator++() {
	this->Current = this->Current + 1;
}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator--() {
	this->Current = this->Current - 1;
}

template<class T>
bool ArrayIterator<T>::operator= (ArrayIterator<T>& Other) {
	this->Current = Other.Current;
	return 1;
}

template<class T>
bool ArrayIterator<T>::operator!= (ArrayIterator<T>& Other) {
	if (Current != Other.Current)
		return 0;
	return 1;
}

template<class T>
T* ArrayIterator<T>::GetElement() {
	return ptr->List[Current];
}

//Array

//constructor
template<class T>
Array<T>::Array() {
	this->Capacity = 0;
	this->Size = 0;
}

//destructor
template<class T>
Array<T>::~Array() {
	if (this->Capacity > 0)
		delete[] List;
}

template<class T>
Array<T>::Array(int capacity) {
	this->Capacity = capacity;
	List = new T * [Capacity];
	this->Size = 0;
}

//Copy-constructor
template<class T>
Array<T>::Array(const Array<T>& otherArray) {
	this->Capacity = otherArray.Capacity;
	List = new T * [otherArray.Capacity];
	this->Size = otherArray.Size;
	for (int i = 0; i < otherArray.Size; i++) {
		List[i] = otherArray.List[i];
	}
}

template<class T>
T& Array<T>::operator [] (int index) {
	Exception1 OutOfRange;
	if (index < 0 || index > Size - 1) throw OutOfRange;
	return *List[index];
}

template<class T>
const Array<T>& Array<T>::operator += (const T& newElem) {
	Exception2 OutOfMemory;
	id(this->Capacity < this->Size + 1) {
		throw OutOfMemory;
	}
	List[++Size] = (int*)&newElem;
	return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T& newElem) {
	Exception1 OutOfRange;
	Exception2 OutOfMemory;
	if (index < 0 || index > this->Size - 1) throw OutOfRange;
	if (Capacity < Size + 1) throw OutOfMemory;
	for (int i = this->Size - 1; i >= index; i--) {
		List[i + 1] = List[i];
	}
	this->Size++;
	List[index] = (int*)&newElem;
	return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray) {
	Exception1 OutOfRange;
	Exception2 OutOfMemory;
	if (index < 0 || index > this->Size - 1) throw OutOfRange;
	if (Capacity < Size + 1) throw OutOfMemory;
	for (int i = this->Size - 1; i >= index; i--) {
		List[i + otherArray.Size] = List[i];
	}
	this->Size += otherArray.Size;
	for (int i = 0; i < otherArray.Size; i++) {
		List[index + i] = otherArray.List[i];
	}
	return *this;
}