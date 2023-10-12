## Лабораторная работа 4

### Теоретическая справка
- Ссылки (lvalue)**
  Ссылки, как и указатели, являются сложной для понимания частью языка.
  Если информации на лекциях было недостаточно или вы что-то успустили, то воспользуйтесь
  [ссылкой](http://cppstudio.com/post/429/)
  Пример работы со сcылками - https://github.com/bmstu-iu8-cpp/cpp-beginner-2017/tree/master/lab5

- Функции и разделение кода на файлы
  Функция — средство языка, которое позволяет в разы сократить объем вашего кода, внести в него
  ясность для других программистов (и проверяющего в частности), реализовать более сложные
  алгоритмы и создать универсальное средство решения для типовых задач.

  Ниже можете ознакомиться с полезнымим ссылками:
  - что такое функции и для чего они нужны - http://cppstudio.com/post/396/
  - разделение исходного кода на файлы - https://metanit.com/cpp/tutorial/3.8.php

- Объявление и определение функции
  Чем определение функции отличается от её объявления? Объявление функции сообщает нам лишь о типе
  её возвращаемого значения, количеcтве аргументов и их типе, а также о том, что в коде мы должны
  встретить её реализацию. Перед использованием функции мы ВСЕГДА должны её объявить. Определение
  функции — это сам код функции, алгоритм.
  
  [Подробнее](https://metanit.com/cpp/tutorial/3.1.php)

- Передача аргументов по ссылкам
  Ссылки используются в С++ повсеместно, поэтому необходимо разобраться в принцие их использования.
  По ссылкам передаются переменные в функции, чтобы изменять сам объект, а не его копию. Ссылки
  позволяют избежать нежелательного копирования.
  
  Зачем все таки передавать аргументы по ссылке - https://metanit.com/cpp/tutorial/3.3.php

- Константные ссылки
  Константные ссылки мы используем для того, чтобы избежать ненужного копирования аргумента, но при
  этом не изменить его значение. Дело в том, что функция, как мы уже знаем, работает не с самим
  аргументом, а с его копией, если передача аргумента идет по значению. Как следствие, возникает
  дополнительное копирование, которого мы стремимся избежать. Если аргумент не должен быть изменен в
  теле функции, а копировать его нецелесообразно, используем константные ссылки.
  
  Читаем на эту тему подробнее [тут](http://alenacpp.blogspot.com/2005/09/const-1.html)

### Инструкция
- Каждое задание должно быть выполнено в `.cpp` файле, например `functions.cpp`.
- Прототипы функции должны быть вынесены в `functions.hpp` файл.
- Все `.cpp` файлы добавить в `sources/meson.build`

### Задание
1. Необходимо реализовать функцию, которая определяет арифметическое среднее в массиве.
Прототип функции:
```cpp
float mean(const std::vector<float>&);
```

2. Необходимо реализовать функцию, которая определяет максимум и минимум в массиве. 
Прототип функции:
```cpp
// .first is min
// .second is max
std::pair<float, float> minMax(const std::vector<float>&);
```
Если массив пуст, функция должна вернуть `min` и `max` из `std::numeric_limits`.
Об этом можно почитать [тут](https://en.cppreference.com/w/cpp/types/numeric_limits).

3. Необходимо реализовать функцию `argmax`, которая определяет индекс максимума в массиве. 
Прототип функции необходимо выбрать самостоятельно.
Нумерация элементов массива начинается с нуля.
Если массив пуст, функция должна вернуть `-1`.

4. Необходимо реализовать функцию, которая сортирует по убыванию входной массив.
Стандартными функциями для сортировки массива пользоваться нельзя!
Прототип функции:
```cpp
void sort(std::vector<float>&);
```

5. Необходимо реализовать функцию `remove_first_negative_element`, которая удаляет первый
   отрицательный элемент массива.
Прототип функции:
```cpp
bool remove_first_negative_element(const std::vector<int>& vec, int& removed_element);
```
Функция возвращает `true` если удалось удалить элемент, а `false` если не удалось.
Значение удаленного элемента помещать в `removed_element`, если удаление не произошло то
инициализировать `removed_element` нулем.

6. Необходимо реализовать функцию, которая заменяет в строке все вхождения подстроки на новую строку.
Можно пользоваться функцией `std::string::find`, о которой можно почитать
[тут](https://ru.cppreference.com/w/cpp/string/basic_string/find).
```cpp
std::string replace(const std::string& str, const std::string& old, const std::string& new_string);
```
Пример:
```cpp
std::string newString = replace("Can you can a can as a canner can can a can?", "can", "cAN");
std::cout << newString; // "Can you cAN a cAN as a cANner cAN cAN a cAN?"
```

7. Необходимо реализовать функцию `split`, которая делит строку по заданному символу.
```cpp
std::vector<std::string> split(const std::string&, char sep);
```
Пример:
```cpp
std::vector<std::string> arr = split("Can you can a can as a canner can can a can?", ' ');
// arr == {"Can", "you", "can", "a", "can", "as", "a", "canner", "can", "can", "a", "can?"};
```
Если строка состоит только из символов, которые указаны вторым аргументом, функция должна вернуть
пустой вектор.

8. Необходимо реализовать функцию, которая соединяет массив строк в одну строку.
```cpp
std::string join(const std::vector<std::string>&, const std::string& sep);
```
Пример:
```cpp
std::vector<std::string> arr = {
    "Can", "you", "can", "a", "can", "as", "a", "canner", "can", "can", "a", "can?"
};
std::string str = join(arr, " ");
// str == "Can you can a can as a canner can can a can?"
```
