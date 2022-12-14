/*Задание 3. Подсчёт количества слов
Что нужно сделать
Напишите программу, которая считает количество слов в тексте, введённом пользователем. Словом считается любая последовательность символов (необязательно букв) без пробелов.

Пользователь вводит строку, состоящую из произвольных символов и пробелов. Программа должна вывести одно число — количество слов во введённой строке.

Примеры

Введите строку: 
abcd abce skjc ahdy 
Ответ: 4  
 
Введите строку: 
..33 !!@! WWW )))))))))) __ )) 
Ответ: 6 

Введите строку: 
_ 
(много пробелов, затем один знак _ и ещё много пробелов) 
Ответ: 1 

Введите строку: 

 
(несколько пробелов и больше ничего) 
Ответ: 0 

Замечание. Если вводить строку обычным способом с помощью команды std::cin >> s, то С++ проигнорирует все символы после первого пробела (потому что пробел по умолчанию считается концом вводимой строки).
Чтобы ввести строку с пробелами, нужно вместо команды std::cin >> s использовать команду std::getline(std::cin, s). 

Что оценивается
Программа корректно считает любое количество символов — от 0 до 100.
Корректно обрабатывается пустая строка.*/

#include <iostream>

int main() {

	std::string inputNumber;
	std::cout << "Enter a real number, not in exponential form: ";
	std::cin >> inputNumber;

	bool correctNumber = true;
	bool presenceDigit = false;
	int numberPoints = 0;

	if (inputNumber[0] >= '0' && inputNumber[0] <= '9') {
		presenceDigit = true;
	}
	else if (inputNumber[0] == '.') {
		numberPoints++;
	}
	else if (inputNumber[0] != '-') {
		correctNumber = false;
	}

	for (int i = 1; correctNumber && i < inputNumber.length(); i++) {
		if (inputNumber[i] >= '0' && inputNumber[i] <= '9') {
			presenceDigit = true;
		}
		else if (inputNumber[i] == '.') {
			numberPoints++;
		}
		else {
			correctNumber = false;
		}
		if (numberPoints > 1) {
			correctNumber = false;
		}
	}

	std::cout << ((presenceDigit && correctNumber) ? "Yes" : "No");
}