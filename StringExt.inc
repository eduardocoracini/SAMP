/// [Version Control]
/// Project: StringExt
/// Author: Eduardo AC
/// Version: 1.0
/// Release: 14/12/2020
/// Update:   /  /

/*

str_trimleft(input[], output[])
str_trimright(input[], output[])
str_trim(input[], output[])
str_replace(input[], output[], old_value[], new_value[], bool:ignore_case)
str_remove(input[], output[], value[], bool:ignore_case)
str_tochararray(input[], output_chars[][2])
str_split(input[], delimiter[], output[][])
str_toupper(input[], output[])
str_tolower(input[], output[])
str_caseintercalate(input[], output[], bool:invert = false)
str_caseinvert(input[], output[])
str_capitalize(input[], output[])
bool:str_startswith(input[], value[], bool:ignore_case)
bool:str_endswith(input[], value[], bool:ignore_case)
str_padleft(input[], output[], padchar[2], width)
str_padright(input[], output[], padchar[2], width)

*/

#if !defined _string_included
  #error "[string_ext.inc] string.inc need to be included"
#endif
#if defined _string_ext_included
  #endinput
#endif
#define _string_ext_included

/// <summary>Remove todos os caracteres de espaço em branco à esquerda da cadeia de caracteres atual.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output[]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <returns></returns>
stock str_trimleft(input[], output[])
{
	output[0] = '\0';
	for(new __idx1__ = 0, __idx2__ = 0; __idx1__ < strlen(input) + 100; __idx1__ ++)
	{
		switch(input[__idx1__])
		{
			case ' ', '	': __idx2__ ++;
			default:
			{
				strmid(output, input, __idx1__, strlen(input), strlen(input) + 100);
				break;
			}
		}
	}
}

/// <summary>Remove todos os caracteres de espaço em branco à direita da cadeia de caracteres atual.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output[]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <returns></returns>
stock str_trimright(input[], output[])
{
	output[0] = '\0';
	for(new __idx3__ = strlen(input) - 1, __idx4__ = 0; __idx3__ > 0; __idx3__ --)
	{
		switch(input[__idx3__])
		{
			case ' ', '	', '\0': __idx4__ ++;
			default:
			{
				strmid(output, input, 0, __idx3__ + 1, strlen(input) + 100);
				break;
			}
		}
	}
}

/// <summary>Remove todos os caracteres de espaço em branco à esquerda e à direita da cadeia de caracteres atual.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output[]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <returns></returns>
stock str_trim(input[], output[])
{
	output[0] = '\0';
	new __idx6__ = 0;
	for(new __idx5__ = 0; __idx5__ < strlen(input); __idx5__ ++)
	{
		switch(input[__idx5__])
		{
			case ' ', '	': __idx6__ ++;
			default:
			{
				strmid(output, input, __idx5__, strlen(input), strlen(input) + 100);
				break;
			}
		}
	}
	
	new __idx7__ = 0;
	for(new __idx5__ = strlen(input) - 1; __idx5__ > 0; __idx5__ --)
	{
		switch(input[__idx5__])
		{
			case ' ', '	', '\0': __idx7__ ++;
			default:
			{
				strmid(output, output, 0, __idx5__ - __idx6__ + 1, strlen(input) + 100);
				break;
			}
		}
	}
}

/// <summary>Retorna (referência) uma nova cadeia de caracteres na qual todas as ocorrências de um caractere Unicode especificado ou String na cadeia de caracteres atual são substituídas por outro caractere Unicode especificado ou por String.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output[]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <param name="old_value[]">Valor a ser substituído.</param>
/// <param name="new_value[]">Novo valor.</param>
/// <param name="bool:ignore_case">Indiferente à caixa.</param>
/// <returns></returns>
stock str_replace(input[], output[], old_value[], new_value[], bool:ignore_case)
{
	output[0] = '\0';
	new __idx8__ = strfind(input, old_value, ignore_case);
	new len = strlen(old_value);
	new __count1__ = 0;
	
	while(__idx8__ > -1)
    {
    	strdel(input, __idx8__, __idx8__ + len);
    	strins(input, new_value, __idx8__, strlen(input) + 100);
        __idx8__ = strfind(input, old_value, ignore_case, __idx8__ + 1);
        __count1__ ++;
    }
    
    strcat(output, input, strlen(input) + (strlen(new_value) * __count1__));
}

/// <summary>Retorna (referência) uma nova cadeia de caracteres na qual um número especificado de caracteres da cadeia de caracteres atual é excluído.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output[]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <param name="value[]">Valor a ser removido.</param>
/// <param name="bool:ignore_case">Indiferente à caixa.</param>
/// <returns></returns>
stock str_remove(input[], output[], value[], bool:ignore_case)
{
	output[0] = '\0';
	new __idx9__ = strfind(input, value, ignore_case);
	new len = strlen(value);
	
	while(__idx9__ > -1)
    {
    	strdel(input, __idx9__, __idx9__ + len);
        __idx9__ = strfind(input, value, ignore_case, __idx9__ + 1);
    }
    
    strcat(output, input, strlen(input));
}

/// <summary>Copia os caracteres nesta instância para uma matriz de caracteres Unicode.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output_chars[][2]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <returns></returns>
stock str_tochararray(input[], output_chars[][2])
{
	for(new __idx10__ = 0; __idx10__ < strlen(input); __idx10__ ++)
	{
		output_chars[__idx10__][0] = '\0';
        strcat(output_chars[__idx10__], input[__idx10__], 2);
    }
}

/// <summary>Retorna (referência) uma matriz de cadeia de caracteres que contém as subcadeias de caracteres nesta instância delimitadas por elementos de uma cadeia de caracteres especificada ou da matriz de caracteres Unicode.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="delimiter[]">Delimitador chave.</param>
/// <param name="output[][]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <returns></returns>
stock str_split(input[], delimiter[], output[][])
{
	new __idx11__ = strfind(input, delimiter, true);
	new lastIdx = 0;
	new __count2__ = 0;
	
	if(__idx11__ > -1)
	{
		output[__count2__][0] = '\0';
		strmid(output[__count2__], input, 0, __idx11__, strlen(input) + 100);
		__count2__ ++;
	}
	
	while(__count2__ < 25)
	{
		lastIdx = __idx11__ + 1;
		__idx11__ = strfind(input, delimiter, true, lastIdx);
		
		while(lastIdx == __idx11__)
		{
			lastIdx ++;
			__idx11__ = strfind(input, delimiter, true, lastIdx);
		}
		
		if(__idx11__ == -1)
		{
			output[__count2__][0] = '\0';
			strmid(output[__count2__], input, lastIdx, strlen(input), strlen(input) + 100);
			break;
		}
		else
		{
			output[__count2__][0] = '\0';
			strmid(output[__count2__], input, lastIdx, __idx11__, strlen(input) + 100);
		}
		__count2__ ++;
	}
	
	return __count2__;
}

/// <summary>Retorna (referência) uma cópia dessa cadeia de caracteres convertida em maiúsculas.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output[]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <returns></returns>
stock str_toupper(input[], output[])
{
	output[0] = '\0';
	new __count3__ = 0;
	while(__count3__ < strlen(input))
    {
        new _char[2];
        format(_char, 2, "%c", toupper(input[__count3__]));
        strcat(output, _char, strlen(input) + 100);
        __count3__ ++;
    }
}

/// <summary>Retorna (referência) uma cópia dessa cadeia de caracteres convertida em minúsculas.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output[]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <returns></returns>
stock str_tolower(input[], output[])
{
	output[0] = '\0';
	new __count4__ = 0;
	while(__count4__ < strlen(input))
    {
        new _char[2];
        format(_char, 2, "%c", tolower(input[__count4__]));
        strcat(output, _char, strlen(input) + 100);
        __count4__ ++;
    }
}

/// <summary>Retorna (referência) uma cópia dessa cadeia de caracteres convertida em minúsculas e maiúsculas, de forma intercalada.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output[]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <param name="bool:invert = false">Inverter a ordem de minúscula e maiúscula.</param>
/// <returns></returns>
stock str_caseintercalate(input[], output[], bool:invert = false)
{
	output[0] = '\0';
	new __count5__ = 0;
	new bool:intercalate = invert;
    while(__count5__ < strlen(input))
    {
        new _char[2];
        format(_char, 2, "%c", intercalate ? toupper(input[__count5__]) : tolower(input[__count5__]));
        strcat(output, _char, strlen(input) + 100);
        intercalate = !intercalate;
        __count5__ ++;
    }
}

/// <summary>Retorna (referência) uma cópia dessa cadeia de caracteres com o tamanho inverso dos caracteres.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output[]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <returns></returns>
stock str_caseinvert(input[], output[])
{
	output[0] = '\0';
	new __count6__ = 0;
	while(__count6__ < strlen(input))
    {
        new _char[2];
        switch(input[__count6__])
        {
            case 'a'..'z':
            {
                format(_char, 2, "%c", toupper(input[__count6__]));
                strcat(output, _char, strlen(input) + 100);
            }
            case 'A'..'Z':
            {
                format(_char, 2, "%c", tolower(input[__count6__]));
                strcat(output, _char, strlen(input) + 100);
            }
            default:
            {
                format(_char, 2, "%c", input[__count6__]);
                strcat(output, _char, strlen(input) + 100);
            }
        }
        __count6__ ++;
    }
}

/// <summary>Retorna (referência) uma cópia dessa cadeia de caracteres na qual a primeira letra de cada palavra é convertida em maiúscula e as demais em minúscula.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output[]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <returns></returns>
stock str_capitalize(input[], output[])
{
	output[0] = '\0';
	new __count7__ = 0;
	new bool:upper = true;
    while(__count7__ < strlen(input))
    {
        new _char[2];
        switch(input[__count7__])
        {
            case 'a'..'z', 'A'..'Z':
            {
                if(upper)
                {
                    format(_char, 2, "%c", toupper(input[__count7__]));
                    strcat(output, _char, strlen(input) + 100);
                    upper = false;
                }
                else
                {
                    format(_char, 2, "%c", input[__count7__]);
                    strcat(output, _char, strlen(input) + 100);
                }
            }
            default:
            {
                format(_char, 2, "%c", input[__count7__]);
                strcat(output, _char, strlen(input) + 100);
                upper = true;
            }
        }
        __count7__ ++;
    }
}

/// <summary>Retorna (referência) uma cópia inversa dessa cadeia de caracteres.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output[]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <returns></returns>
stock str_invert(input[], output[])
{
	output[0] = '\0';
	for(new __idx12__ = strlen(input) - 1; __idx12__ > -1; __idx12__ --)
	{
		new _char[2];
		format(_char, 2, "%c", input[__idx12__]);
        strcat(output, _char, strlen(input) + 1);
	}
}

/// <summary>Determina se o início desta instância de cadeia de caracteres corresponde a uma cadeia de caracteres especificada.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="value[]"></param>
/// <param name="bool:ignore_case">Indiferente à caixa.</param>
/// <returns></returns>
stock bool:str_startswith(input[], value[], bool:ignore_case)
{
	return (strcmp(input, value, ignore_case, strlen(value)) == 0);
}

/// <summary>Determina se o fim desta instância de cadeia de caracteres corresponde a uma cadeia de caracteres especificada.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="value[]"></param>
/// <param name="bool:ignore_case">Indiferente à caixa.</param>
/// <returns></returns>
stock bool:str_endswith(input[], value[], bool:ignore_case)
{
	new len = strlen(input);
	new len2 = strlen(value);
	strmid(input, input, len - len2, len, len);
	return (strcmp(input, value, ignore_case, strlen(value)) == 0);
}

/// <summary>Retorna (referência) uma nova cadeia de caracteres de um comprimento especificado no qual o início da cadeia de caracteres atual é preenchido com caractere especificado.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output[]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <param name="padchar[2]">Caractere a ser adicionado à esquerda.</param>
/// <param name="width">Tamanho total da nova cadeia de caracteres.</param>
/// <returns></returns>
stock str_padleft(input[], output[], padchar[2], width)
{
	output[0] = '\0';
	if(strlen(input) >= width)
	{
		strcat(output, input, strlen(input) + 1);
	}
	else
	{
		new len = strlen(input);
		new lenDiff = (width - len);

		for(new idx = 0; idx < lenDiff; idx ++)
			strins(output, padchar, 0, (len + lenDiff + 1));

		strcat(output, input, (len + lenDiff + 1));
	}
}

/// <summary>Retorna (referência) uma nova cadeia de caracteres de um comprimento especificado no qual o fim da cadeia de caracteres atual é preenchido com caractere especificado.</summary>
/// <param name="input[]">Cadeia de caracteres de entrada.</param>
/// <param name="output[]">Cadeia de caracteres de saída (nova cadeia de caracteres).</param>
/// <param name="padchar[2]">Caractere a ser adicionado à direita.</param>
/// <param name="width">Tamanho total da nova cadeia de caracteres.</param>
/// <returns></returns>
stock str_padright(input[], output[], padchar[2], width)
{
	output[0] = '\0';
	if(strlen(input) >= width)
	{
		strcat(output, input, strlen(input) + 1);
	}
	else
	{
		new len = strlen(input);
		new lenDiff = (width - len);

		strcat(output, input, (len + lenDiff + 1));

		for(new idx = 0; idx < lenDiff; idx ++)
			strins(output, padchar, strlen(output), (len + lenDiff + 1));
	}
}
