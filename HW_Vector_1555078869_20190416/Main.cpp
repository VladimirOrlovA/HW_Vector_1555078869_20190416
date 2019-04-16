#include "vector_.h"

int main()
{
	vector_ arr1(2, 3);		// передача в конструктор размера и исходное значение элементов массива
	vector_ arr2(3, 5);
	vector_ arr3(4, 7);
	arr1.print();
	arr2.print();
	//obj++;
	//++obj;
	//int num = 10;
	//obj.push_back(num);		// добавление в конец массива  одного элемента
	//obj.print();
	//obj.pop_back();			// удаление последнего элемента
	//obj.print();
	//int pos = 3;
	//obj.erase(pos);			// удаление элемента под индексом pos
	//obj.print();
	////obj.clear();			// освобождение памяти
	////obj.print();
	//obj.getSize();
	//obj.empty();
	//obj.getElement(3);

	vector_ c=arr1 + arr2 + arr3;
	cout << "after operation\n";
	c.print();

	system("pause");
}