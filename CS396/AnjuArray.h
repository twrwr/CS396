
namespace Anju::Structure
{

//----------------------------------------------------------------------------------------------------
/*!
	Fixed Size Array. Uses C++ 17.
*/
//----------------------------------------------------------------------------------------------------
template<typename T, size_t SIZE>
struct Array
{
	//----------------------------------------------------------------------------------------------------
	
	using value_type			= T;
	using size_type				= std::size_t;
	using difference_type		= std::ptrdiff_t;
	using reference				= value_type&;
	using const_reference		= const value_type&;
	using pointer_type			= value_type*;
	using const_pointer_type	= const value_type*;
	using iterator_type			= pointer_type;
	using const_iterator_type	= const_pointer_type;

	//----------------------------------------------------------------------------------------------------

	constexpr inline iterator_type			begin() noexcept;
	constexpr inline const_iterator_type	begin() const noexcept;
	constexpr inline const_iterator_type	cbegin() const noexcept;

	constexpr inline iterator_type			end() noexcept;
	constexpr inline const_iterator_type	end() const noexcept;
	constexpr inline const_iterator_type	cend() const noexcept;

	constexpr inline pointer_type			data() noexcept;
	constexpr inline const_pointer_type		data() const noexcept;

	constexpr inline reference				front() noexcept;
	constexpr inline const_reference		front() const noexcept;

	constexpr inline reference				back() noexcept;
	constexpr inline const_reference		back() const noexcept;

	constexpr inline size_type size() const noexcept	{ return SIZE; }
	constexpr inline bool empty() const noexcept { return SIZE == 0; }

	//----------------------------------------------------------------------------------------------------

	constexpr inline reference operator[](const int index) noexcept;
	constexpr inline const_reference operator[](const int index) const noexcept;

	value_type mData[SIZE]; // Fixed Sized Buffer
};

template<typename T, size_t SIZE>
constexpr inline typename Array<T, SIZE>::iterator_type Array<T, SIZE>::begin() noexcept
{
	if constexpr (SIZE == 0)
		return nullptr;
	return mData;
}

template<typename T, size_t SIZE>
constexpr inline typename Array<T, SIZE>::const_iterator_type Array<T, SIZE>::begin() const noexcept
{
	if constexpr (SIZE == 0)
		return nullptr;
	return mData;
}

template<typename T, size_t SIZE>
constexpr inline typename Array<T, SIZE>::const_iterator_type Array<T, SIZE>::cbegin() const noexcept
{
	if constexpr (SIZE == 0)
		return nullptr;
	return mData;
}

template<typename T, size_t SIZE>
constexpr inline typename Array<T, SIZE>::iterator_type Array<T, SIZE>::end() noexcept
{
	if constexpr (SIZE == 0)
		return nullptr;
	return mData + SIZE;
}

template<typename T, size_t SIZE>
constexpr inline typename Array<T, SIZE>::const_iterator_type Array<T, SIZE>::end() const noexcept
{
	if constexpr (SIZE == 0)
		return nullptr;
	return mData + SIZE;
}

template<typename T, size_t SIZE>
constexpr inline typename Array<T, SIZE>::const_iterator_type Array<T, SIZE>::cend() const noexcept
{
	if constexpr (SIZE == 0)
		return nullptr;
	return mData + SIZE;
}

template<typename T, size_t SIZE>
constexpr inline typename Array<T,SIZE>::pointer_type Array<T, SIZE>::data() noexcept
{
	if constexpr (SIZE == 0)
		return nullptr;
	return mData;
}

template<typename T, size_t SIZE>
constexpr inline typename Array<T, SIZE>::const_pointer_type Array<T, SIZE>::data() const noexcept
{
	if constexpr (SIZE == 0)
		return nullptr;
	return mData; 
}

template<typename T, size_t SIZE>
constexpr inline typename Array<T, SIZE>::reference Array<T, SIZE>::front() noexcept
{
	static_assert(SIZE > 0, "Array Size is ZERO, There are no elements to access.");
	return *mData;
}

template<typename T, size_t SIZE>
constexpr inline typename Array<T, SIZE>::const_reference Array<T, SIZE>::front() const noexcept
{ 
	static_assert(SIZE > 0, "Array Size is ZERO, There are no elements to access.");
	return *mData; 
}

template<typename T, size_t SIZE>
inline constexpr typename Array<T, SIZE>::reference Array<T, SIZE>::back() noexcept
{
	static_assert(SIZE > 0, "Array Size is ZERO, There are no elements to access.");
	return *(mData + SIZE - 1);
}

template<typename T, size_t SIZE>
inline constexpr typename Array<T, SIZE>::const_reference Array<T, SIZE>::back() const noexcept
{
	static_assert(SIZE > 0, "Array Size is ZERO, There are no elements to access.");
	return *(mData + SIZE - 1);
}

template<typename T, size_t SIZE>
constexpr inline typename typename Array<T, SIZE>::reference Array<T, SIZE>::operator[](const int index) noexcept
{
	static_assert(SIZE > 0, "Array Size is ZERO, There are no elements to access.");
	return mData[index];
}

template<typename T, size_t SIZE>
constexpr inline typename Array<T, SIZE>::const_reference Array<T, SIZE>::operator[](const int index) const noexcept
{
	static_assert(SIZE > 0, "Array Size is ZERO, There are no elements to access.");
	return mData[index]; 
}


}//namespace Anju::Structure

