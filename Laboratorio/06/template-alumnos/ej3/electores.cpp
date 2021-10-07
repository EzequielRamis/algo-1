#include "electores.h"

int edadEnFecha(int nd, int nm, int na, int fd, int fm, int fa)
{
	int edad = fa - na;
	if ((fd < nd && fm == nm) || fm < nm)
		edad--;
	return edad;
}

int validarVotante(int a, int m, int d)
{
	/* Fecha de elecciones */
	int dia = 14, mes = 11, ano = 2021;
	int edadMaxima = 150;
	/* Valido rangos */
	if (a >= ano && m >= mes && d >= dia)
		return ERROR;
	if (a < ano - edadMaxima || a > ano || m <= 0 || m > 12 || d <= 0 || d > 31)
		return ERROR;
	/* Valido meses de 30 días */
	if (d == 31 && (m == 4 || m == 6 || m == 9 || m == 11))
		return ERROR;
	/* Valido años bisiestos */
	bool esAnoBisiesto = a % 4 == 0 && a % 400 == 0;
	if (!esAnoBisiesto && m == 2 && d > 28)
		return ERROR;
	/* Fin de datos validados */
	if (edadEnFecha(d, m, a, dia, mes, ano) < 16)
		return NO_VOTA;
	if (edadEnFecha(d, m, a, dia, mes, ano) >= 16 && edadEnFecha(d, m, a, dia, mes, ano) < 18)
		return OPCIONAL_MENOR;
	if (edadEnFecha(d, m, a, dia, mes, ano) >= 70)
		return OPCIONAL_MAYOR;
	return OBLIGATORIO;
}
