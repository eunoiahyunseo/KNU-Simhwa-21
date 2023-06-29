#include "calc.h"

void add(CALC_DATA *data)
{
    data->operator= '+';
    data->result = data->operand1 + data->operand2;
}

void sub(CALC_DATA *data)
{
    data->operator= '-';
    data->result = data->operand1 - data->operand2;
}