#include <stdio.h> // Para comparar com o printf original
#include "ft_printf.h" // Inclua o cabeçalho da sua ft_printf
#include <limits.h> // Para INT_MIN, INT_MAX, LONG_MIN, LONG_MAX
#include <unistd.h> // Para NULL em alguns casos

int main()
{
    int ret_ft;
    int ret_orig;


    ret_ft = ft_printf("F %x ", 9223372036854775807LL);
	ret_orig = printf("P %x ", 9223372036854775807LL);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

	return (0);

    printf("--- Testes de %%c (caractere) ---\n");
    ret_ft = ft_printf("Char: %c\n", 'A');
    ret_orig = printf("Char: %c\n", 'A');
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("Char nulo: %c\n", 0); // Caractere nulo
    ret_orig = printf("Char nulo: %c\n", 0);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    printf("--- Testes de %%s (string) ---\n");
    ret_ft = ft_printf("String: %s\n", "Hello World!");
    ret_orig = printf("String: %s\n", "Hello World!");
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("String nula: %s\n", (char *)NULL); // String nula (deve imprimir "(null)")
    ret_orig = printf("String nula: %s\n", (char *)NULL);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("String vazia: %s\n", "");
    ret_orig = printf("String vazia: %s\n", "");
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    printf("--- Testes de %%p (ponteiro) ---\n");
    int var = 42;
    int *ptr = &var;
    ret_ft = ft_printf("Endereco de ptr: %p\n", ptr);
    ret_orig = printf("Endereco de ptr: %p\n", ptr);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("Endereco NULL: %p\n", (void *)NULL); // Ponteiro NULL
    ret_orig = printf("Endereco NULL: %p\n", (void *)NULL);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    printf("--- Testes de %%d (decimal) e %%i (inteiro) ---\n");
    ret_ft = ft_printf("Decimal positivo: %d\n", 12345);
    ret_orig = printf("Decimal positivo: %d\n", 12345);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("Decimal negativo: %d\n", -9876);
    ret_orig = printf("Decimal negativo: %d\n", -9876);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("Inteiro zero: %i\n", 0);
    ret_orig = printf("Inteiro zero: %i\n", 0);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("INT_MAX: %d\n", INT_MAX);
    ret_orig = printf("INT_MAX: %d\n", INT_MAX);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("INT_MIN: %d\n", INT_MIN);
    ret_orig = printf("INT_MIN: %d\n", INT_MIN);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    printf("--- Testes de %%u (unsigned decimal) ---\n");
    ret_ft = ft_printf("Unsigned positivo: %u\n", 12345U);
    ret_orig = printf("Unsigned positivo: %u\n", 12345U);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("Unsigned de negativo (INT_MIN): %u\n", (unsigned int)INT_MIN); // Conversão de negativo para unsigned
    ret_orig = printf("Unsigned de negativo (INT_MIN): %u\n", (unsigned int)INT_MIN);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("Unsigned zero: %u\n", 0U);
    ret_orig = printf("Unsigned zero: %u\n", 0U);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("UINT_MAX: %u\n", UINT_MAX);
    ret_orig = printf("UINT_MAX: %u\n", UINT_MAX);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    printf("--- Testes de %%x (hexadecimal minusculo) ---\n");
    ret_ft = ft_printf("Hex positivo: %x\n", 255);
    ret_orig = printf("Hex positivo: %x\n", 255);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("Hex zero: %x\n", 0);
    ret_orig = printf("Hex zero: %x\n", 0);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("Hex INT_MAX: %x\n", INT_MAX);
    ret_orig = printf("Hex INT_MAX: %x\n", INT_MAX);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("Hex negativo (como unsigned): %x\n", -1); // Comportamento como unsigned int
    ret_orig = printf("Hex negativo (como unsigned): %x\n", -1);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    printf("--- Testes de %%X (hexadecimal maiusculo) ---\n");
    ret_ft = ft_printf("HEX positivo: %X\n", 255);
    ret_orig = printf("HEX positivo: %X\n", 255);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("HEX zero: %X\n", 0);
    ret_orig = printf("HEX zero: %X\n", 0);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("HEX INT_MAX: %X\n", INT_MAX);
    ret_orig = printf("HEX INT_MAX: %X\n", INT_MAX);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("HEX negativo (como unsigned): %X\n", -1); // Comportamento como unsigned int
    ret_orig = printf("HEX negativo (como unsigned): %X\n", -1);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    printf("--- Testes de %%%% (sinal de porcentagem) ---\n");
    ret_ft = ft_printf("Porcentagem: %%\n");
    ret_orig = printf("Porcentagem: %%\n");
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("Texto com %% no meio\n");
    ret_orig = printf("Texto com %% no meio\n");
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    printf("--- Testes de combinacao ---\n");
    ret_ft = ft_printf("Char: %c, String: %s, Int: %d, Ptr: %p\n", 'Y', "Combinado", -50, &ret_ft);
    ret_orig = printf("Char: %c, String: %s, Int: %d, Ptr: %p\n", 'Y', "Combinado", -50, &ret_ft);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    ret_ft = ft_printf("Hex: %x, HEX: %X, Unsigned: %u, Percent: %%\n", 1024, 1024, 2048U);
    ret_orig = printf("Hex: %x, HEX: %X, Unsigned: %u, Percent: %%\n", 1024, 1024, 2048U);
    printf("ft_printf retorno: %d, printf retorno: %d\n\n", ret_ft, ret_orig);

    return 0;
}