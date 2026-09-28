#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template<typename T>
class Array {
	public:
		Array() {
			this->array = NULL;
			this->n = 0;
		}

		Array(unsigned int n) {
			this->array = new T[n];
			this->n = n;
		}

		~Array() {
			delete[] array;
		}

	
		Array(const Array& other)
		{
			array = new T[other.size()];
			n = other.size();

			for (unsigned int i = 0; i < n; i++)
				array[i] = other.array[i];
		}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] array;

				n = other.size();
				array = new T[n];

				for (unsigned int i = 0; i < n; i++)
					array[i] = other.array[i];
			}

			return *this;
		}

		T& operator[](unsigned int index)
		{
			if (index >= n)
				throw std::exception();

			return array[index];
		}

		const T& operator[](unsigned int index) const
		{
			if (index >= n)
				throw std::exception();

			return array[index];
		}

		unsigned int size() const {
			return this->n;
		}

	private:
		T* array;
		unsigned int n;
};

#endif