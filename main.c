/* Главная программа Hippothesis-of-Collatsa-in-C:
 * Начало разработки: 08 мая 2024 г.
 * Правка: 15 мая 2024 г.
 *
 * Задание:
 *
 * Реализация гипотезы Лотара Коллатса:
 * (саракузская проблема)
 * 1. Берём любое натуральное число.
 * 2. Если оно чётное, то делим его на 2.
 * 3. Если оно нечётное, то умножаем на 3 и прибавляем 1.
 * 4. Над полученным результатом проводим операции №2 или №3.
 *
 * Утверждение: какое бы число не взяли, получим 1.
 */
 
/* Выполнено v. 0.1 от 08.05.24:
 * -----------------
 * 1. Набросать прототип рассчёта гипотезы.
 * 2. Сделал Makefile для более лёгкой сборки с исходником.
 */

/* Выполнено v. 0.2:
 * -----------------
 * 1. Добавить проект в Git.
 * 2. Подправил комментарии с учётом изменения названия проекта.
 */	

/* План работ на v. 0.Х:
 * ---------------------
 * 2. Доделать Makefile таким образом, чтобы при сборке финальный файл имел
 *    примерно такое назмание: hocic_v.0.1_build_240508t0309.
 * 3. Доделать Makefile stable таким образом, чтобы при сборке финальный файл
 *    имел примерно такое название: hoc_v.0.1.
 * 4. Проверку на чётность/нечётность вынести в отдельную функцию.
 * 5. Все функции вынести в отдельный файл.
 * 6. Все настройки вынести в отдельный файл.
 */

/* Баг:
 * ----
 * B1-0.2: В ходе вычисления натурального числа 113383 достигается максимальное значение для
 *         int: при умножении промежуточного числа 827 370 449 на 3 результатом становится
 *         отрицательное число, а должно быть (827 370 449 * 32 = 2 482 111 347). Тип int от
 *         −2 147 483 648 до 2 147 483 647 (при 4 байтах).
 * B1-0.2 решение: замена типа переменной currentNumber с int на long int.
 */

#include <stdio.h>	// Препроцессор для вывода и ввода.

// Макросы.
#define VERSION "0.2" // Версия текущего билда.

// Начало главной программы.
int main(void)
{
	printf("Hippothesis-of-Colltsa-in-C v. %s\n", VERSION);			// Вывод версии программы.
	printf("------------------------------------------------\n");
	printf("Реализация гипотезы Лотара Коллатса на языке СИ.\n");
	printf("\n");
	
	int naturalNumber = 113383;					// Стартовое натуральное число.
	long int currentNumber = naturalNumber;

	printf("Берем натуральное число %ld:\n", currentNumber);

	// Бесконечный цикл.
	while (naturalNumber < 1000000)
	{
		// Если натуральное число чётное.
		if (currentNumber % 2) {
			printf("%ld - нечётное. %ld * 3 + 1 = ", currentNumber, currentNumber);
			currentNumber = currentNumber * 3;
			currentNumber = currentNumber + 1;
			printf("%ld\n", currentNumber);
		}
		else{
			printf("%ld - чётное. %ld / 2 = ", currentNumber, currentNumber);
			currentNumber = currentNumber / 2;
			printf("%ld\n", currentNumber);
		};

		// Проверяем гипотезу.
		if (currentNumber == 1) {
			printf("\nБерём следующее натуральное число");
			naturalNumber = naturalNumber + 1;
			currentNumber = naturalNumber;
			printf(" %ld:\n", currentNumber);
		};
	}

	return 0;
}