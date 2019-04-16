#include "vector_.h"

vector_::vector_()	// конструктор по умолчанию
{
	this->size = 0;			// размер массива по умолчанию
	this->arr = nullptr;	// устанавливаем адрес массива nullptr
}

vector_::vector_(int size, int val) // конструктор по умолчанию
{
	this->size = size;
	this->arr = new int[this->size];
	for (int i = 0; i < this->size; i++)
		this->arr[i] = val;
}

vector_::vector_(const vector_ & obj)		// конструктор копирования объекта
{
	this->size = obj.size;
	if (this->size == 0)
		this->arr = nullptr;
	else
	{
		this->arr = new int[this->size];
		for (int i = 0; i < this->size; i++)
			this->arr[i] = obj.arr[i];
	}
}

void vector_::push_back(int num)	// метод добавления в массив новго элемента в конец
{
	if (this->size == 0)
	{
		this->arr = new int[1];
		this->arr[0] = num;
		this->size++;
		return;
	}
	int *tmp = new int[this->size + 1];
	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i] = this->arr[i];
	}
	tmp[this->size] = num;
	delete[]this->arr;
	this->arr = tmp;
	this->size++;
}

void vector_::pop_back()  // метод удаления последнего элемента
{
	if (this->size == 0)
	{
		cout << "Array is empty!";
	}
	else
	{
		int *tmp = new int[this->size - 1];
		for (size_t i = 0; i < this->size - 1; i++)
		{
			tmp[i] = this->arr[i];
		}
		delete[]this->arr;
		this->arr = tmp;
		this->size--;
	}

}

void vector_::erase(int pos)	//метод вставки в заданную элемента в заданную позицию
{
	if (this->size == 0)
	{
		cout << "Array is empty!";
	}
	else
	{
		int *tmp = new int[this->size];
		int j = 0;
		for (size_t i = 0; i < this->size; i++)
		{
			if (i == pos)
			{
				tmp[i] = this->arr[i + 1];
				i++;
			}
			tmp[j] = this->arr[i];
			j++;
		}
		delete[] this->arr;
		this->arr = tmp;
		this->size--;
	}

}

void vector_::clear()	// метод очистки объекта класса
{
	if (this->arr != nullptr)
	{
		delete[] this->arr;
		this->arr = nullptr;
		this->size = 0;
	}
}

int vector_::getSize() // геттер размера массива
{
	cout << "Array size is " << this->size << "\n\n";
	return this->size;
}

bool vector_::empty() // проверка массива на заполнение
{
	if (this->arr == nullptr)
		return true;
	return false;
}

int vector_::getElement(int pos)		// метод получения элемента из заданной позиции
{
	if (pos > this->size)
	{
		cout << "Wrong input" << endl;
		return 0;
	}
	else
	{
		cout << "Getting the value of a given element position: pos " << pos << " = value " << this->arr[pos] << "\n\n";
		return this->arr[pos];
	}
}

void vector_::print() // вывод массива на экран
{
	if (this->arr == nullptr)
		cout << "Array is empty!\n";
	else
	{
		for (size_t i = 0; i < this->size; i++)
		{
			cout << this->arr[i] << " ";
		}
	}
	cout << endl;
}
// postfix incriment
vector_ & vector_::operator++()
{
	for (size_t i = 0; i < size; i++)
	{
		this->arr[i] += 1;
	}
	this->push_back(this->arr[0]);
	return *this;
}
// prefix incriment
vector_ vector_::operator++(int)
{
	vector_ c = *this;
	for (size_t i = 0; i < size; i++)
	{
		this->arr[i] += 1;
	}
	return c;
}
// метод - перегрузка оператора присваивания =
vector_ vector_::operator=(vector_&obj)
{
	if (this->size != obj.size)
	{
		delete[] arr;
		this->arr = new int[obj.size];
		this->size = obj.size;
	}
	
	for (size_t i = 0; i < this->size; i++)
	{
		this->arr[i] = obj.arr[i];
	}
	return *this;
}
// метод - перегрузка оператора += (в конец одного массива добавляем элементы из второго)
vector_ vector_::operator+=(const vector_ & obj)
{
	int tmpSize = this->size + obj.size;
	int *tmp = new int[tmpSize];
	
	for (size_t i = 0; i < tmpSize; i++)
	{
		if (i < this->size) tmp[i] = this->arr[i];
		if (i >= this->size) tmp[i] = obj.arr[i-this->size];
	}
	delete[] this->arr;
	this->size = tmpSize;
	this->arr = new int[tmpSize];
	for (size_t i = 0; i < this->size; i++)
	{
		this->arr[i] = tmp[i];
	}
	return *this;
}

// деструктор
vector_::~vector_()
{
	if (this->arr != nullptr) {
		delete[]this->arr;
		this->size = 0;
	}
}

// гл.функция оператора "+" для типа данных drob
//Vector_ operator+(const Vector & a, const Vector & b)
//{
//	Vector c = a;
//	c += b;
//	//drob c;
//	//c.setX(a.getY()*b.getX() + a.getX()*b.getY());
//	//c.setY(a.getY()*b.getY());
//	return c;
//}

vector_ operator+(const vector_ & a, const vector_ & b)
{
	vector_ c = a;
	c += b;
	return c;
}
